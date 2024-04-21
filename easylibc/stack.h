#ifndef __$STACK$_$H$__
#define __$STACK$_$H$__

#include "def.h"
#include "list.h"

_extern_c_beg_

#define $declare_$stack(_typename_)\
_extern_c_beg_ \
typedef struct $__stacknode_##_typename_{\
    _typename_* data;\
    struct $__stacknode_##_typename_* next;\
} $stacknode_##_typename_, *$pstacknode_##_typename_;\
\
typedef struct $__stack_##_typename_{\
    int size;\
    $stacknode_##_typename_ *root;\
    _typename_* temp;\
} $stack_##_typename_,*$pstack_##_typename_; \
_extern_c_end_


#define $stack(_typename_) $stack_##_typename_
#define $pstack(_typename_) $pstack_##_typename_
#define stack_new() list_new()
#define stack_del(_pstack) list_del(_pstack)
#define stack_push_rv(_pstack,_val) list_emplacefront(_pstack,_val) 
#define stack_push_lv(_pstack,_val) list_pushfront(_pstack,_val) 
#define stack_top(_pstack) *(_pstack->root->data)
#define stack_pop(_pstack) list_erase(_pstack,0)

_extern_c_end_


#endif