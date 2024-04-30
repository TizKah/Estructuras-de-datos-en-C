#ifndef WORD_H
#define WORD_H

#include <stdbool.h>

// Estructura para representar una palabra
typedef struct {
    char *value;            // Puntero al contenido de la palabra
    int len;                // Longitud total de la palabra
    int noValidCharsLen;    // Longitud de caracteres inválidos en la palabra
    bool foundValidWord;    // Indica si se ha encontrado una palabra válida
    bool hasFinalChar;      // Indica si la palabra contiene un carácter final
} wordType;

// Inicializa una nueva estructura wordType
wordType *inicialize_word(int longerLen);

// Agrega un carácter a la estructura wordType
void add_char_to_word(wordType *word, char charPhrase);

// Obtiene la longitud válida de la palabra (excluyendo caracteres inválidos)
int valid_word_len(wordType *word);

// Reinicia la estructura wordType para su reutilización
void reset_word(wordType *word);

// Libera la memoria utilizada por la estructura wordType
void destroy_word(wordType *word);

#endif
