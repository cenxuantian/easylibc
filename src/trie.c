#ifndef __$TRIE$_$C$__
#define __$TRIE$_$C$__

#include "trie.h"


_extern_c_beg_

$trienode* trienode_new(){
    $trienode* res = malloc(sizeof($trienode));
    res->is_end = false;
    for(int i= 0;i<256;i++) res->next[i]=NULL;
    return res;
}

void trienode_del($trienode* node){
    for(int i=0;i<256;i++){
        if(node->next[i]) trienode_del(node);
    }
    free(node);
}

$trie* trie_new(){
    $trie* res = malloc(sizeof($trie));
    res->root = NULL;
    return res;
}
void trie_del($trie* _ptrie){
    if(_ptrie->root){
        trienode_del(_ptrie->root);
    }
}
void trie_push($trie* _ptrie,const char* _str){
    
    if(!_ptrie->root) _ptrie->root = trienode_new();
    $trienode* cur = _ptrie->root;
    int len = strlen(_str);
    for(int i= 0;i<len;i++){
        unsigned char ch = _str[i];
        if(!cur->next[ch]) cur->next[ch]=trienode_new();
        cur = cur->next[ch];
    }
    cur->is_end=true;
}
bool trie_search($trie* _ptrie,const char* _prefix){
    $trienode* cur = _ptrie->root;
    if(!cur) return false;
    int len = strlen(_prefix);
    for(int i=0;i<len;i++){
        unsigned char ch = _prefix[i];
        if(!cur->next[ch]) return false;
        cur = cur->next[ch];
    }
    return true;
}
bool trie_has_word($trie* _ptrie,const char* _word){
        $trienode* cur = _ptrie->root;
    if(!cur) return false;
    int len = strlen(_word);
    for(int i=0;i<len;i++){
        unsigned char ch = _word[i];
        if(!cur->next[ch]) return false;
        cur = cur->next[ch];
    }
    return cur->is_end;
}
$vec($pstr)* trie_all($trie* _ptrie,const char* prefix);

_extern_c_end_


#endif