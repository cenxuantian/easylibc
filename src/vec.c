#ifndef __$VEC$_$C$__
#define __$VEC$_$C$__

#include "vec.h"

_extern_c_beg_

void* vec_new(int reserve) {
    $vec(void)*res=calloc(1,sizeof($vec(void)));
    if(reserve>0){
        res->capacity=reserve;
        res->data=malloc(reserve);
    }
    return res;
}
void vec_del(void* _pvec){
    if((($vec(void)*)_pvec)->data) free((($vec(void)*)_pvec)->data);
    free(_pvec);
}

void* vec_copy(const void* _pvec){
    $vec(void)* _vec =vec_new(0);
    _vec->size = (($vec(void)*)_pvec)->size;
    _vec->capacity = (($vec(void)*)_pvec)->capacity;
    int data_size = (int)$msize((($vec(void)*)_pvec)->data);
    _vec->data = malloc(data_size);
    memcpy(_vec->data,(($vec(void)*)_pvec)->data,data_size);
    return _vec;
}






_extern_c_end_


#endif