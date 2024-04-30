#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

//Archivos locales .h:
#include "word.h"
#include "dictionary.h"

#define WORD_VALID(hasht, key) (ht_get(hasht, key) != NULL)  //Palabra en diccionario: palabra válida.
#define END_PHRASE(charPhrase) (charPhrase=='\n')

//Debe ser >= cantidad de lineas/palabras en txt de diccionario
#define HASHTABLE_SIZE 999

char *dictionaryFileName = "diccionario.txt";

//FUNCIONES MANEJO DE ARCHIVOS:
//Escribe la palabra válida en el archivo
void write_and_reset_valid_word(wordType *word, FILE* goodPhrasesFile){
    fputs(word->value, goodPhrasesFile);
    fputc(' ', goodPhrasesFile);
    reset_word(word);
}

//Notifica de un error al final de la frase
void report_error(FILE *goodPhrasesFile){
    char* mensajeError = "-[ERROR ENCONTRADO]-";
    fwrite(mensajeError, sizeof(char), strlen(mensajeError), goodPhrasesFile);
}

//Vuelve al final de la última palabra válida escrita
void ignore_valid_word(wordType *word, FILE *badPhrasesFile,char charPhrase){
    if(charPhrase!=EOF && word->hasFinalChar) fseek(badPhrasesFile,-word->noValidCharsLen-2,SEEK_CUR);
    else fseek(badPhrasesFile,-word->noValidCharsLen,SEEK_CUR);
}

//Retrocede al siguiente char luego del error
void ignore_error_char(char charPhrase, int wordLen,FILE *badPhrasesFile){
    int bytesDown = (charPhrase=='\n' ? -(wordLen+1) : -(wordLen-1));
    fseek(badPhrasesFile,bytesDown,SEEK_CUR);
}


//Verifica si las primeres letras de word son prefijo de alguna palabra válida
bool firsts_chars_no_prefix(dictionaryType* dictionarys,wordType *word){
    return (word->len<dictionarys->shorterLen && !posible_longest_world(dictionarys->trie,word->value));
}

//Pasa el char a minúscula
char read_and_format_char(FILE *badPhrasesFile){
    char charPhrase = fgetc(badPhrasesFile);
    if(!END_PHRASE(charPhrase)) 
        charPhrase = tolower(charPhrase);
    return charPhrase;
}

//Inicializa el diccionario ya con las palabras válidas dentro
dictionaryType* inicialize_dictionary_from_file(const char* dictionaryFileName) {
    if (dictionaryFileName == NULL) {
        // Manejar caso en que el nombre de archivo sea NULL
        // Por ejemplo, imprimir un mensaje de error y retornar NULL
        return NULL;
    }

    dictionaryType* dictionarys = inicialize_dictionary(HASHTABLE_SIZE);
    if (dictionarys == NULL) {
        // Manejar error de inicialización de diccionario
        // Por ejemplo, imprimir un mensaje de error y liberar memoria si es necesario
        return NULL;
    }

    FILE* dictionaryFile = fopen(dictionaryFileName, "r");
    if (dictionaryFile == NULL) {
        // Manejar error de apertura de archivo
        // Por ejemplo, imprimir un mensaje de error y liberar memoria si es necesario
        free(dictionarys);  // Liberar memoria del diccionario
        return NULL;
    }

    insert_words_dictionary(dictionarys, dictionaryFile);
    fclose(dictionaryFile);
    return dictionarys;
}


//Procesa el caso de error
void process_error(wordType *word, char charPhrase, bool *error, FILE *badPhrasesFile){
    ignore_error_char(charPhrase,word->len,badPhrasesFile);
    reset_word(word);
    *error = true;
    word->hasFinalChar=false;
}

//Procesa el caso de una palabra válida
void process_valid_word(wordType *word, dictionaryType *dictionarys, FILE *goodPhrasesFile){
    //Dos posibilidades:
    //1- Ya estamos ante la última palabra y es válida
    //2- La palabra válida es prefijo de otra
    if(word->hasFinalChar || !posible_longest_world(dictionarys->trie,word->value)){
        write_and_reset_valid_word(word,goodPhrasesFile);
    } else word->foundValidWord = true;   
                
    word->noValidCharsLen=0;
}

//Procesa el caso que haya palabra válida y se llegue al final
void process_posible_longest_word(wordType *word,char charPhrase ,FILE *goodPhrasesFile, FILE *badPhrasesFile){
    //Vuelvo al final de la última palabra válida
    ignore_valid_word(word,badPhrasesFile,charPhrase);

    //Escribo la palabra
    word->value[valid_word_len(word)] = '\0';
    write_and_reset_valid_word(word,goodPhrasesFile);
    word->hasFinalChar=false;
}

//Corrije la frase tomada del archivo input y la escribe en el archivo output.
//Retorna si estamos en la última frase o no.
bool correct_phrase(FILE *badPhrasesFile,FILE *goodPhrasesFile, dictionaryType *dictionarys,wordType *word){
    bool error=false;
    char charPhrase='-';

    reset_word(word);
    word->hasFinalChar=false;
    while (!word->hasFinalChar) {
        
        //Leo por carácter y lo formateo según corresponda
        charPhrase = read_and_format_char(badPhrasesFile);
        add_char_to_word(word,charPhrase);

        //Pequeña optimizacion para cuando el error no es prefijo
        if(firsts_chars_no_prefix(dictionarys,word)){ 
            reset_word(word);
            error = true;
        }else if (word->len >= dictionarys->shorterLen) {

            if (WORD_VALID(dictionarys->hash, word->value)) {
                process_valid_word(word, dictionarys, goodPhrasesFile);
                
            //Hubo palabra válida y llegamos al final de la evaluación:
            } else if(word->foundValidWord && (word->len==dictionarys->longerLen || word->hasFinalChar)){
                process_posible_longest_word(word, charPhrase, goodPhrasesFile, badPhrasesFile);
    
            //Se encontró un error                
            } else if(word->len==dictionarys->longerLen || word->hasFinalChar){
                process_error(word, charPhrase, &error, badPhrasesFile);
            }
        }
    }

    //Error al final
    if(error || word->value[0]!='\0') 
        report_error(goodPhrasesFile);

    return charPhrase==EOF;
}

int main() {
    char* badPhrasesFileName = "malo.txt";
    char* goodPhrasesFileName = "bueno.txt";

    //Manejo de diccionario:
    dictionaryType *dictionarys = inicialize_dictionary_from_file(dictionaryFileName);

    //Ficheros input y output
    //e inicialización de word, variable para validar palabra.
    FILE* badPhrasesFile = fopen(badPhrasesFileName, "r");
    FILE* goodPhrasesFile = fopen(goodPhrasesFileName, "w+");
    wordType *word = inicialize_word(dictionarys->longerLen);

    //Se corrige una frase por iteración
    bool finalPhrase = false;
    while(!finalPhrase){
        finalPhrase = correct_phrase(badPhrasesFile,goodPhrasesFile,dictionarys,word);
        fputc('\n', goodPhrasesFile);
    }

    //Cierro archivos
    fclose(badPhrasesFile);
    fclose(goodPhrasesFile);

    //Libero memoria
    destroy_dictionary(dictionarys);
    destroy_word(word);

    return 0;
}
