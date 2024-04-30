#include <stdlib.h>
#include "dictionary.h"

#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define BUFFER_SIZE 500

//ACLARACIÓN: 
//El diccionario del trie no acepta tildes (se da por hecho ya que el enunciado ignora las tildes) 
//ni ñ.

dictionaryType *inicialize_dictionary(int htSize){
    dictionaryType *dictionarys = (dictionaryType*)malloc(sizeof(dictionaryType));
    dictionarys->hash = ht_create(htSize);
    dictionarys->trie = create_trie_nodo();
    dictionarys->shorterLen = 999;
    dictionarys->longerLen = 0;
    return dictionarys;
}

//Inserto las palabras del diccionario en el Trie y en la tabla hash.
//Guardo la longitud mínima y la máxima entre las palabras.
void insert_words_dictionary(dictionaryType* dictionarys, FILE* dictionaryFile) {
    char buffer[BUFFER_SIZE];
    int *existWord = (int*)malloc(sizeof(int));
    if (existWord == NULL) {
        // Manejar error de asignación de memoria
        // Por ejemplo, imprimir un mensaje de error y salir de la función
        return;
    }
    *existWord = 1;

    while (fgets(buffer, sizeof(buffer), dictionaryFile)) {
        size_t len = strlen(buffer);

        // Eliminar el salto de línea y/o coma al final de la palabra
        if (len > 0 && (buffer[len - 1] == '\n' || buffer[len - 1] == ',')) {
            buffer[len - 1] = '\0';
            len--;
        }

        // Actualizar longitudes máximas y mínimas
        if (len > 0) {
            dictionarys->shorterLen = MIN(dictionarys->shorterLen, len);
            dictionarys->longerLen = MAX(dictionarys->longerLen, len);
            insert_word_into_trie(dictionarys->trie, buffer);
            ht_put(dictionarys->hash, buffer, existWord);
        }
    }

    free(existWord);
}


void destroy_dictionary(dictionaryType *dictionarys){
    ht_destroy(dictionarys->hash);
    destroy_trie(dictionarys->trie);
    free(dictionarys);
}