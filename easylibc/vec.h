#ifndef __$VEC$_$H$__
#define __$VEC$_$H$__

#include "def.h"
#include "sort.h"
_extern_c_beg_

#define $declare_$vec(_typename_)\
_extern_c_beg_ \
typedef struct $__vec_##_typename_{\
    _typename_* data;\
    int size;\
    int capacity;\
} $vec_##_typename_; \
_extern_c_end_

$declare_$vec(void)

#define $vec(_typename_) $vec_##_typename_
void* vec_new(int reserve);
void vec_del(void* _pvec);
void* vec_copy(const void* _pvec);
#define vec_pushback(_pvec,_val)        __vec_pushback(_pvec,_val) 
#define vec_popback(_pvec)              {if(_pvec->size!=0) {_pvec->size--;}}(void)0
#define vec_insert(_pvec,_pos,_val)     __vec_insert(_pvec,_pos,_val) 
#define vec_at(_pvec,_pos)              _pvec->data[_pos]
#define vec_erase(_pvec,_pos)           __vec_erase(_pvec,_pos) 
#define vec_clear(_pvec)                _pvec->size=0
#define vec_shrink(_pvec)               {__vec_resize(_pvec,_pvec->size)}(void)0
#define vec_sort(_pvec)                 array_quick_sort(_pvec->data,sizeof(*(_pvec->data)),_pvec->size,memcmp)
#define vec_reverse(_pvec)              for(int i=0; i <= _pvec->size/2;i++) {$swap(&$vec_at(_pvec,i),&$vec_at(_pvec,_pvec->size-1-i),sizeof(*(_pvec->data)));}(void)0
#define vec_eq(_pvec1,_pvec2)           (_pvec1->size!=_pvec2->size? false:(memcmp(_pvec1->data,_pvec2->data,_pvec1->size)==0))

// private
#define __vec_next_capacity(_pvec) (_pvec->capacity *2+1)
#define __vec_resize(_pvec,_new_size) {\
    _pvec->data = realloc(_pvec->data,_new_size*sizeof(*(_pvec->data)));\
    _pvec->size = _pvec->size<_new_size? _pvec->size:_new_size;\
    _pvec->capacity = _new_size;\
}
#define __vec_pushback(_pvec,_val) {\
    if(_pvec->size>=_pvec->capacity){\
        __vec_resize(_pvec,__vec_next_capacity(_pvec));\
    }\
    _pvec->data[_pvec->size] = _val;\
    _pvec->size++;\
}
#define __vec_insert(_pvec,_pos,_val) {\
    if(_pvec->size==0){\
        __vec_pushback(_pvec,_val);\
    }\
    else if(_pos<_pvec->size){\
        if(_pvec->size>=_pvec->capacity){\
            __vec_resize(_pvec,__vec_next_capacity(_pvec));\
        }\
        int right_size =(_pvec->size-_pos) * sizeof(*(_pvec->data));\
        void* right = malloc(right_size);\
        memcpy(right,_pvec->data+_pos,right_size);\
        _pvec->data[_pos]=_val;\
        memcpy(_pvec->data+_pos+1,right,right_size);\
        _pvec->size++;\
    }\
}
#define __vec_erase(_pvec,_pos) {\
    if(_pvec->size){\
        if(_pos<_pvec->size){\
            if(_pos==_pvec->size-1) {__vec_popback(_pvec);}\
            else{\
                int right_size =(_pvec->size-_pos-1) * sizeof(*(_pvec->data));\
                void* right = malloc(right_size);\
                memcpy(right,_pvec->data+_pos+1,right_size);\
                memcpy(_pvec->data+_pos,right,right_size);\
                _pvec->size--;\
            }\
        }\
    }\
}

_extern_c_end_
#endif