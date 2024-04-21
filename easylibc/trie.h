#ifndef __$TRIE$_$H$__
#define __$TRIE$_$H$__

#include "def.h"
#include "vec.h"
#include "str.h"


$declare_$vec($pstr)

_extern_c_beg_

typedef struct $__trienode{
    struct $__trienode* next[256];
    bool is_end;
} $trienode;

typedef struct $__trie{
    $trienode* root;
} $trie;

$trie* trie_new();
void trie_del($trie* _ptrie);
void trie_push($trie* _ptrie,const char* _str);
bool trie_search($trie* _ptrie,const char* _prefix);
bool trie_has_word($trie* _ptrie,const char* _word);
$vec($pstr)* trie_all($trie* _ptrie,const char* prefix);

_extern_c_end_


#endif