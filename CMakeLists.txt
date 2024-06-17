# Minimum version for cmake compatiblity
cmake_minimum_required(VERSION 3.29)
include(CMakePrintHelpers)
include(FetchContent)

# Set branch names for the sub modules dependencies
set(GITHUB_BRANCH_TOOLCHAIN "HEAD" CACHE STRING "git SHA for CMake Toolchain")
# set the location of all fetched repos
set(FETCHCONTENT_BASE_DIR "${CMAKE_SOURCE_DIR}/_deps")
# show limited messages while cloning git repos
set(FETCHCONTENT_QUIET ON)

cmake_print_variables(GITHUB_BRANCH_TOOLCHAIN)
FetchContent_Declare(
    cmake_scripts                             # Recommendation: Stick close to the original name.
    GIT_REPOSITORY  git@github.com:kodezine/cmake_scripts.git
    GIT_TAG         ${GITHUB_BRANCH_TOOLCHAIN}
)

# pre-fetch the toolchain repository as the first job before project configuration
FetchContent_GetProperties(cmake_scripts)

if(NOT cmake_scripts_POPULATED)
    FetchContent_Populate(cmake_scripts)
endif()

project(
    f031k6
    VERSION     0.0.1
    LANGUAGES   C ASM CXX
    DESCRIPTION "Hardware Abstraction Layer for STM32CubeXX based project"
)

if(CMAKE_SYSTEM_PROCESSOR STREQUAL "arm")
    # Include dependencies from repositories ---------------------------------------
    set(GITHUB_BRANCH_cmsis_v6 "6.1.0")
    include(${cmake_scripts_SOURCE_DIR}/frameworks/cmsis_v6/cmsis_v6.cmake)
    #include(${cmake_scripts_SOURCE_DIR}/frameworks/segger_rtt/segger_rtt.cmake)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/k_devices)
else()
    message( STATUS "Compiling for Host system")
endif()

set(${PROJECT_NAME}_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/app/main.cpp
)

add_executable (${PROJECT_NAME}
    ${${PROJECT_NAME}_SRCS}
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD_REQUIRED 17
        CXX_EXTENSIONS OFF
)

target_link_libraries(${PROJECT_NAME}
    k_devices
)

set(${PROJECT_NAME}_LLVM_LINKER_SCRIPT "llvm.ld")
set(${PROJECT_NAME}_LLVM_LINKER_PATH "${CMAKE_SOURCE_DIR}")

setTargetLinkOptions(PROJECT_NAME)
