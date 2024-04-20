#ifndef __$STR_C__
#define __$STR_C__

#include "str.h"
#include <stdio.h>

_extern_c_beg_

$str* str_new() {return vec_new(0);}

$str* str_copy(const $str* _pstr){ return vec_copy(_pstr); }

$str* str_copy_from(const char* _c_str){
    $str* _str = malloc(sizeof($str));
    int sz = (int)strlen(_c_str);
    _str->size = sz;
    _str->capacity = sz+1;
    _str->data = malloc(_str->capacity );
    memcpy(_str->data,_c_str,_str->capacity);
    _str->data[sz]=0;
    return _str;
}

$str* str_move_from(char* _char_pointer,int _capacity){
    $str* _str = malloc(sizeof($str));
    _str->data = _char_pointer;
    _str->size = (int)strlen(_char_pointer);
    _str->capacity = _capacity;
    return _str;
}

$str* str_from_c(char _val){
    char temp[2] = {_val,0};
    return str_copy_from(temp);
}

$str* str_from_i(int _val){
    char* temp = malloc(12);
    sprintf(temp,"%d",_val);
    return str_move_from(temp,12);
}

$str* str_from_ll(long long _val){
    char* temp = malloc(21);
    sprintf(temp,"%lld",_val);
    return str_move_from(temp,21);
}

$str* str_from_d(double _val){
    char* temp = malloc(19);
    sprintf(temp,"%llf",_val);
    return str_move_from(temp,19);
}

void str_del($str* _pstr) {
    vec_del(_pstr);
}

void str_add($str* _pstr, char _other){
    if(_pstr->size == 0){
        __vec_resize(_pstr,2);
        str_at(_pstr,0) = _other;
        str_at(_pstr,1) = 0;
        _pstr->size++;
        return;
    }
    
    if(_pstr->size+1 >= _pstr->capacity){
        __vec_resize(_pstr,__vec_next_capacity(_pstr));
    }
    str_at(_pstr,_pstr->size) = _other;
    str_at(_pstr,_pstr->size+1) = 0;
    _pstr->size++;
    return;
}

void str_app($str* _pstr, const char* _other){
    int in_size = (int)strlen(_other);
    int target_capacity  = _pstr->size+in_size+1;
    if(_pstr->capacity<target_capacity){
        __vec_resize(_pstr,target_capacity);
    }
    memcpy(_pstr->data+_pstr->size,_other,in_size);
    _pstr->data[target_capacity-1]=0;
    _pstr->size = target_capacity-1;
    return;
}

void str_merge($str* _target,$str* _src){
    str_app(_target,_src->data);
    str_del(_src);
}

$str* str_substr($str* _pstr,int _off, int _count){
    $str* res = str_new();
    if(_off<=0) return res;
    if(_count==str_npos) _count = _pstr->size-_off;
     res->capacity = _count+1;
    res->size = _count;
    res->data = malloc(res->capacity);
    memcpy(res->data,_pstr->data+_off,_count);
    res->data[res->size]=0;
    return res;

}

int str_first_of($str* _pstr,char _c){
    for(int i = 0;i<_pstr->size;i++){
        if(_pstr->data[i] == _c) return i;
    }
    return str_npos;
}

int str_first_not_of($str* _pstr,char _c){
    for(int i = 0;i<_pstr->size;i++){
        if(_pstr->data[i] != _c) return i;
    }
    return str_npos;
}

int str_last_of($str* _pstr,char _c){
    for(int i = _pstr->size-1; i>=0; i--){
        if(_pstr->data[i] == _c) return i;
    }
    return str_npos;
}

int str_last_not_of($str* _pstr,char _c){
    for(int i = _pstr->size-1; i>=0; i--){
        if(_pstr->data[i] != _c) return i;
    }
    return str_npos;
}

_extern_c_end_
#endif