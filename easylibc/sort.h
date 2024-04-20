#ifndef __$SORT$_$H$__
#define __$SORT$_$H$__

#include "def.h"

_extern_c_beg_

// public
typedef int(sort_comp_func)(const void*, const void*,size_t);

void array_quick_sort(void* target, int ele_size, int ele_count,sort_comp_func* compare);

// private
void __array_quick_sort(void* target, int ele_size,sort_comp_func* compare,int start,int stop);

_extern_c_end_

#endif