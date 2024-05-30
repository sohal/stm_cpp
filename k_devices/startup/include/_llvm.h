#ifdef __cplusplus
extern "C" {
#endif
#ifndef VECTORS_LLVM
#define VECTORS_LLVM

#ifndef __NO_RETURN
#define __NO_RETURN __attribute__((__noreturn__))
#endif

#ifndef __PROGRAM_START
#define __PROGRAM_START               _start
#endif

#ifndef __StackTop
#define __StackTop                    __stack
#endif

#ifndef __StackLimit
#define __StackLimit                  __stack_size
#endif

#ifndef __VECTOR_TABLE
#define __VECTOR_TABLE                __Vectors
#endif

#ifndef __VECTOR_TABLE_ATTRIBUTE
#define __VECTOR_TABLE_ATTRIBUTE      __attribute__((used, section(".vectors")))
#endif

#ifndef __INITIAL_SP
#define __INITIAL_SP                  __StackTop
#endif

#ifndef __STACK_LIMIT
#define __STACK_LIMIT                 __StackLimit
#endif


#endif

#ifdef __cplusplus
}
#endif
