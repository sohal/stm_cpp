if (NOT DEFINED ${libName})
    set(libName k_devices)
endif ()
# Minimum version for cmake compatiblity
cmake_minimum_required(VERSION 3.25)
include(CMakePrintHelpers)
include(FetchContent)

project(
    ${libName}
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "Device Register library for STM32 in Modern CPP"
)

# Includes ---------------------------------------------------------------------
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Main target ------------------------------------------------------------------
add_library(${libName} STATIC)
add_library(${libName}::framework ALIAS ${libName})

# set public headers
set(${libName}_PUBLIC_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/k_address.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/k_register.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/k_rcc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/k_flash.h
    ${CMAKE_CURRENT_SOURCE_DIR}/startup/include/_llvm.h
)

target_include_directories(${libName}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/startup/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${libName}>
)

set_target_properties(${libName}
    PROPERTIES
        CXX_STANDARD_REQUIRED 17
        CXX_EXTENSIONS OFF
        PUBLIC_HEADER           "${${libName}_PUBLIC_HEADERS}"
        EXPORT_NAME             framework
)

target_compile_options(${libName}
    INTERFACE
        $<$<C_COMPILER_ID:Clang>:-Wcast-align
                                 -Wcast-qual
                                 -Wconversion
                                 -Wexit-time-destructors
                                 -Wglobal-constructors
                                 #-Wmissing-noreturn
                                 -Wmissing-prototypes
                                 -Wno-missing-braces
                                 -Wold-style-cast
                                 -Wshadow
                                 -Wweak-vtables
                                 #-Werror
                                 -Wall>
        $<$<C_COMPILER_ID:GNU>:-Waddress
                               -Waggregate-return
                               -Wformat-nonliteral
                               -Wformat-security
                               -Wformat
                               -Winit-self
                               -Wmissing-declarations
                               -Wmissing-include-dirs
                               -Wno-multichar
                               -Wno-parentheses
                               -Wno-type-limits
                               -Wno-unused-parameter
                               -Wunreachable-code
                               -Wwrite-strings
                               -Wpointer-arith
                               #-Werror
                               -Wall>
       $<$<C_COMPILER_ID:MSVC>:/Wall>
)
## Sub project ---------------------------------------------------------------
target_sources(${libName}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/k_rcc.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/k_flash.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/startup/sources/stm32f031k6.cpp
)

target_link_libraries(${libName}
    cmsis_v5
)

## ---------------------------------------------------------------------------
write_basic_package_version_file(${libName}ConfigVersion.cmake
    VERSION         ${libName}
    COMPATIBILITY   SameMajorVersion
)

## Target installation
install(TARGETS     ${libName} ${GenericName}
    EXPORT          ${libName}Targets
    ARCHIVE         DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY         DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER   DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${libName}
    COMPONENT       library
)

## Target's cmake files: targets export
install(EXPORT      ${libName}Targets
    NAMESPACE       ${libName}::
    DESTINATION     ${CMAKE_INSTALL_LIBDIR}/cmake/${libName}
)

## Target's cmake files: config and version config for find_package()
install(FILES       ${libName}Config.cmake
                    ${CMAKE_CURRENT_BINARY_DIR}/${libName}ConfigVersion.cmake
    DESTINATION     ${CMAKE_INSTALL_LIBDIR}/cmake/${libName}
)

# This will set the CPACK tar file as
# cmsis_v5-<cmsisVersion>-<cortexType>-<compiler>-<compilerVersion>.tar.gz
set(CPACK_PACKAGE_CHECKSUM SHA3_256)
set(CPACK_SYSTEM_NAME "$ENV{CORTEX_TYPE}-${CMAKE_C_COMPILER_ID}-${CMAKE_C_COMPILER_VERSION}")
set(CPACK_BINARY_TGZ "ON")
set(CPACK_BINARY_ZIP "OFF")
set(CPACK_BINARY_ZIP "OFF")
set(CPACK_BINARY_NSIS "OFF")
set(CPACK_SOURCE_IGNORE_FILES
  \\.git/
  build/
  ".*~$"
)
set(CPACK_VERBATIM_VARIABLES YES)
include(CPack)
