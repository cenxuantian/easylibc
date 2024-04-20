#ifndef __$LIST$_$C$__
#define __$LIST$_$C$__

#include "list.h"

_extern_c_beg_

void* __copy_to_heap(void* data, int size){
    void* res = malloc(size);
    memcpy(res,data,size);
    return res;
}

void* __listnode_new(void* data,void* next){
    $listnode_void* res = malloc(sizeof( $listnode_void));
    res->data=data;
    res->next =next;
    return res;
}
void __listnode_del(void* _node, bool recurse){
    $listnode_void* node = _node;
    if(!recurse){
        if(node->data) free(node->data);
        free(node);
    }else{
        if(node->data) free(node->data);
        if(node->next) __listnode_del(node->next,true);
        free(node);
    }
}

void* list_new(){
    $list_void* res = malloc(sizeof($list_void));
    res->root = 0;
    res->size = 0;
    res->temp = 0;
    return res;
}
void list_del(void* _plist){
    if((($list_void*)_plist)->root) __listnode_del((($list_void*)_plist)->root,true);
    if((($list_void*)_plist)->temp) free((($list_void*)_plist)->temp);
    free(_plist);
}
void list_clear(void* _plist){
    if((($list_void*)_plist)->root) __listnode_del((($list_void*)_plist)->root,true);
    (($list_void*)_plist)->size = 0;
}
void list_erase(void* _list,int _pos){
    $list_void* _plist = _list;
    if(_pos == 0){
        $listnode_void* tar = _plist->root;
        _plist->root = _plist->root->next;
        __listnode_del(tar,false);
        _plist->size--;
        return;
    }
    $listnode_void* cur = _plist->root;
    for(int i=0;i< _pos-1;i++){
        cur = cur->next;
    }
    $listnode_void* tar = cur->next;
    cur->next = cur->next->next;
    __listnode_del(tar,false);
    _plist->size--;
    return;
}


void __list_void_pushback(void* _list, void* _val, int _ele_size){
    $list_void* _plist = _list;
    _plist->size++;
    void* _data = __copy_to_heap(_val,_ele_size);
    $listnode_void* new_node = __listnode_new(_data,0);
    if(!_plist->root) {
        _plist->root = new_node;
        return;
    }
    $listnode_void* cur = _plist->root;
    while(cur->next){
        cur  = cur->next;
    }
    cur->next = new_node;
}
void __list_void_pushfront(void* _list, void* _val, int _ele_size){
    $list_void* _plist = _list;
    _plist->size++;
    void* _data = __copy_to_heap(_val,_ele_size);
    $listnode_void* new_node = __listnode_new(_data,0);
    if(!_plist->root) {
        _plist->root = new_node;
        return;
    }
    new_node->next = _plist->root;
    _plist->root = new_node;
    return;
}
void __list_void_insert(void* _list, void* _val, int _ele_size,int _pos){
    if(_pos==0) {
        __list_void_pushfront(_list,_val,_ele_size);
        return;
    }
    
    $list_void* _plist = _list;
    
    void* _data = __copy_to_heap(_val,_ele_size);
    $listnode_void* new_node = __listnode_new(_data,0);
    $listnode_void* cur = _plist->root;
    for(int i=0;i< _pos-1;i++){
        cur = cur->next;
    }
    new_node->next = cur->next->next;
    cur->next = new_node;
    _plist->size++;
    return;
}
void* __list_void_at(void* _list, int _pos){
    $list_void* _plist = _list;
    $listnode_void* cur = _plist->root;
    for(int i=0;i< _pos;i++){
        cur = cur->next;
    }
    return cur->data;
}

_extern_c_end_


#endif