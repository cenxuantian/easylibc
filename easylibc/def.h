#ifndef __$DEF$_$H$__
#define __$DEF$_$H$__

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>

#ifdef __cplusplus
#define _extern_c_beg_ extern "C"{
#define _extern_c_end_ }
#else
#define _extern_c_beg_
#define _extern_c_end_
#endif
_extern_c_beg_

#define $deref(__typename,_pointer) (*((__typename*)_pointer))
#define $offset(_pointer, _off) (((char*)_pointer)+_off)
#define $swap(a,b,size) {void* temp = malloc(size);memcpy(temp,a,size);memcpy(a,b,size);memcpy(b,temp,size);free(temp);}

#ifdef _WIN32
#define $msize(_ptr)  _msize((char*)_ptr)
#elif defined(__linux__)
#define $msize(_ptr) malloc_usable_size(_ptr);
#endif

_extern_c_end_

#endif