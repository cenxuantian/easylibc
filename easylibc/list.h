#ifndef __$LIST$_$H$__
#define __$LIST$_$H$__

#include "def.h"

_extern_c_beg_

#define $declare_$list(_typename_)\
_extern_c_beg_ \
typedef struct $__listnode_##_typename_{\
    _typename_* data;\
    struct $__listnode_##_typename_* next;\
} $listnode_##_typename_,*$plistnode_##_typename_;\
\
typedef struct $__list_##_typename_{\
    int size;\
    $listnode_##_typename_ *root;\
    _typename_* temp;\
} $list_##_typename_,*$plist_##_typename_; \
_extern_c_end_

$declare_$list(void)

#define $list(_typename_) $list_##_typename_
#define $listnode(_typename_) $listnode_##_typename_
#define $plist(_typename_) $plist_##_typename_
#define $plistnode(_typename_) $plistnode_##_typename_

void* list_new();
void list_del(void* _plist);
void list_erase(void* _plist,int _pos);
#define list_at(__typename, _plist, _pos)  $deref(__typename,__list_void_at(_plist,_pos))
#define list_foreach(__typename, _iter_name,_plist, ...)  __list_foreach(__typename, _iter_name,_plist,##__VA_ARGS__) 
// faster when _val is rvalue
#define list_emplaceback(_plist, _val)    __list_emplaceback(_plist,_val) 
#define list_emplacefront(_plist, _val)    __list_emplacefront(_plist,_val)
#define list_insert_rv(_plist,_pos,_val) __list_insert_rv(_plist,_pos,_val)
// can only be used if _val is lvalue
#define list_pushback(_plist, _val)    __list_pushback(_plist,_val) 
#define list_pushfront(_plist, _val)    __list_pushfront(_plist,_val)
#define list_insert_lv(_plist,_pos,_val) __list_insert_lv(_plist,_pos,_val)



void* __listnode_new(void* data,void* next);
void __listnode_del(void* node, bool recurse);
void __list_void_pushback(void* _list, void* _val, int _ele_size);
void __list_void_pushfront(void* _list, void* _val, int _ele_size);
void __list_void_insert(void* _list, void* _val, int _ele_size,int _pos);
void* __list_void_at(void* _list, int _pos);
#define __list_ele_size(_plist)    sizeof(*(_plist->root->data))

#define __list_emplaceback(_plist,_val)  {\
    if(!_plist->temp) _plist->temp = malloc(__list_ele_size(_plist));\
    *(_plist->temp) = _val;\
    __list_void_pushback(_plist,_plist->temp,__list_ele_size(_plist));\
}

#define __list_pushback(_plist,_val)  __list_void_pushback(_plist,&_val,$__list_ele_size(_plist))

#define __list_emplacefront(_plist,_val) {\
    if(!_plist->temp) _plist->temp = malloc(__list_ele_size(_plist));\
    *(_plist->temp) = _val;\
    __list_void_pushfront(_plist,_plist->temp,__list_ele_size(_plist));\
}

#define __list_pushfront(_plist,_val) __list_void_pushfront(_plist,&_val,__list_ele_size(_plist))

#define __list_insert_rv(_plist,_pos,_val) {\
    if(!_plist->temp) _plist->temp = malloc(__list_ele_size(_plist));\
    *(_plist->temp) = _val;\
    __list_void_insert(_plist,_plist->temp,__list_ele_size(_plist),_pos);\
}

#define __list_insert_lv(_plist,_pos,_val) $__common_list_insert(_plist,&_val,__list_ele_size(_plist),_pos)

#define __list_foreach(__typename, _iter_name,_plist, ...) {\
    $listnode(__typename)* __loop_iter = _plist->root;\
    while(__loop_iter){\
        __typename* _iter_name = __loop_iter->data;\
        __VA_ARGS__;\
        __loop_iter = __loop_iter->next;\
    }\
}


_extern_c_end_


#endif