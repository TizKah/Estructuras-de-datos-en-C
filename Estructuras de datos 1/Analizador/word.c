#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "word.h"

wordType *inicialize_word(int longerLen){
    wordType *word = (wordType*)malloc(sizeof(wordType));
    word->value = (char*)malloc(sizeof(char)*longerLen);
    word->value[0] = '\0';
    word->len=word->noValidCharsLen=0;
    word->foundValidWord=false;
    word->hasFinalChar=false;
    return word;
}

void add_char_to_word(wordType *word, char charPhrase){
    if(charPhrase!='\n' && charPhrase!=EOF){
        word->value[word->len++] = charPhrase;
        word->value[word->len] = '\0';
        word->noValidCharsLen++;
        word->hasFinalChar = false;
    } else word->hasFinalChar = true;
}

int valid_word_len(wordType *word){
    return(word->len-word->noValidCharsLen);
}

void reset_word(wordType *word){
    word->value[0] = '\0';
    word->len=word->noValidCharsLen=0;
    word->foundValidWord=false;
}

void destroy_word(wordType *word){
    free(word->value);
    free(word);
}