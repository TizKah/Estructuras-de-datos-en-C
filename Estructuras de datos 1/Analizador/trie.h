#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

// Estructura de nodo del Trie
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE]; // Array de punteros a los hijos
    bool isEndOfWord; // Indica si es el final de una palabra
} TrieNode;

// Crea un nuevo nodo del Trie
TrieNode* create_trie_nodo();

// Inserta una palabra en el Trie
void insert_word_into_trie(TrieNode* root, const char* word);

// Busca una palabra en el Trie
bool searchWordInTrie(TrieNode* root, char* word);

// Destruye el Trie y libera la memoria
void destroy_trie(TrieNode* root);

// Verifica si hay más palabras con el mismo prefijo en el Trie
bool posible_longest_world(TrieNode* root, char* prefix);

#endif /* TRIE_H */
