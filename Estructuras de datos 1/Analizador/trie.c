#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"
#define ALPHABET_SIZE 26

TrieNode* create_trie_nodo() {
    TrieNode* newNode = malloc(sizeof(TrieNode));
    if (newNode != NULL) {
        newNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            newNode->children[i] = NULL;
    }
    return newNode;
}

void insert_word_into_trie(TrieNode* root, const char* word) {
    if (root == NULL || word == NULL)
        return;

    TrieNode* current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        char c = tolower(word[i]);
        if (c >= 'a' && c <= 'z') {
            int index = c - 'a';
            if (current->children[index] == NULL) {
                current->children[index] = create_trie_nodo();
            }
            current = current->children[index];
        }
    }
    current->isEndOfWord = true;
}


bool search_word_in_trie(TrieNode* root, char* word) {
    if (root == NULL || word == NULL) 
        return false;

    TrieNode* current = root;
    int index;
    for (int i = 0; word[i] != '\0'; i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }

    return current->isEndOfWord;
}

void destroy_trie(TrieNode* root) {
    if (root == NULL) 
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        destroy_trie(root->children[i]);

    free(root);
}

// Función para verificar si hay más palabras con el mismo prefijo en el Trie
bool posible_longest_world(TrieNode* root, char* prefix) {
    TrieNode* current = root;

    // Recorre el Trie siguiendo el camino del prefijo
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (current->children[index] == NULL) {
            // No hay más palabras con el mismo prefijo
            return false;
        }
        current = current->children[index];
    }

    // Si llegas al final del prefijo y hay más nodos hijos, hay más palabras con el mismo prefijo
    for (int i = 0; i < 26; i++) {
        if (current->children[i] != NULL) {
            return true;
        }
    }

    // No hay más palabras con el mismo prefijo
    return false;
}