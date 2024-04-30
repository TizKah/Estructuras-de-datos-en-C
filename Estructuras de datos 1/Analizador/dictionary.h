#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include "trie.h"
#include "hashtable.h"

typedef struct {
    TrieNode *trie;
    hashtable_t *hash;
    int shorterLen;
    int longerLen;
} dictionaryType;


dictionaryType *inicialize_dictionary(int htSize);
void insert_words_dictionary(dictionaryType *dictionarys, FILE* dictionaryFile) ;
void destroy_dictionary(dictionaryType *dictionarys);


#endif
