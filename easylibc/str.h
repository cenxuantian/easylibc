#ifndef __$STR_H__
#define __$STR_H__

#include "def.h"
#include "vec.h"

$declare_$vec(char)

_extern_c_beg_

typedef $vec(char) $str;

#define str_npos -1
// constructor
$str* str_new();
$str* str_copy(const $str* _pstr);
$str* str_copy_from(const char* _c_str);
// will take the ownership of _str, _str will be free if called 
$str* str_move_from(char* _str,int _capacity); 
$str* str_from_c(char _val);
$str* str_from_i(int _val);
$str* str_from_ll(long long _val);
$str* str_from_d(double _val);
// destructor
void str_del($str* _pstr) ;
// operator
void str_add($str* _pstr, char _other);
void str_app($str* _pstr, const char* _other);
// will take the ownership of _src, after $str_merge, _src will be free
void str_merge($str* _target,$str* _src);
#define str_at(_pstr,_pos) vec_at(_pstr,_pos)
$str* str_substr($str* _pstr,int _off, int _count);
int str_first_of($str* _pstr,char _c);
int str_first_not_of($str* _pstr,char _c);
int str_last_of($str* _pstr,char _c);
int str_last_not_of($str* _pstr,char _c);


_extern_c_end_
#endif