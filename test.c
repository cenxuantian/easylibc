#include <stdio.h>

#include <def.h>
#include <vec.h>
#include <str.h>
#include <pair.h>
#include <list.h>
#include <stack.h>
#include <trie.h>

$declare_$stack(double)

int main(int argc, char** argv){
    $trie* trie = trie_new();
    trie_push(trie,"hello");
    trie_push(trie,"heyyy");
    printf("%d\n",trie_search(trie,"he"));

}


