#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include <string.h>

// Estructura del elemento de la tabla hash
typedef struct hash_elem_t {
    struct hash_elem_t* next; // Siguiente elemento en caso de colisión
    void* data; // Puntero al elemento almacenado
    char key[]; // Clave del elemento almacenado
} hash_elem_t;

// Estructura de la tabla hash
typedef struct {
    unsigned int capacity; // Capacidad de la tabla hash (en términos de claves hash)
    unsigned int e_num; // Número de elementos almacenados actualmente en la tabla hash
    hash_elem_t** table; // La tabla que contiene los elementos
} hashtable_t;

// Estructura utilizada para iteraciones
typedef struct {
    hashtable_t* ht; // La tabla hash en la que iteramos
    unsigned int index; // Índice actual en la tabla
    hash_elem_t* elem; // Elemento actual en la lista
} hash_elem_it;

/*  Función interna para calcular el hash para las claves.
    Está basada en el algoritmo DJB de Daniel J. Bernstein.
    La clave debe terminar con el carácter '\0'. */
static unsigned int ht_calc_hash(char* key);

/*  Crear una tabla hash con capacidad 'capacity'
    y devolver un puntero a ella */
hashtable_t* ht_create(unsigned int capacity);

/*  Almacenar datos en la tabla hash. Si los datos con la misma clave ya están almacenados,
    se sobrescriben y se devuelven por la función. Si no, devuelve NULL.
    Devuelve HT_ERROR si hay un error de asignación de memoria. */
void* ht_put(hashtable_t* hasht, char* key, void* data);

/* Recuperar datos de la tabla hash */
void* ht_get(hashtable_t* hasht, char* key);

/*  Eliminar datos de la tabla hash. Devuelve los datos eliminados de la tabla
    para que podamos liberar la memoria si es necesario */
void* ht_remove(hashtable_t* hasht, char* key);

/* Listar claves. k debería tener una longitud igual o mayor que el número de claves */
void ht_list_keys(hashtable_t* hasht, char** k, size_t len);

/*  Listar valores. v debería tener una longitud igual o mayor
    que el número de elementos almacenados */
void ht_list_values(hashtable_t* hasht, void** v, size_t len);

/* Iterar a través de los elementos de la tabla. */
hash_elem_t* ht_iterate(hash_elem_it* iterator);

/* Iterar a través de las claves. */
char* ht_iterate_keys(hash_elem_it* iterator);

/* Iterar a través de los valores. */
void* ht_iterate_values(hash_elem_it* iterator);

/*  Elimina todos los elementos almacenados en la tabla hash.
    Si free_data es verdadero, todos los datos almacenados también se liberan. */
void ht_clear(hashtable_t* hasht, int free_data);

/*  Destruye la tabla hash y libera la memoria.
    Los datos almacenados aún se liberan. */
void ht_destroy(hashtable_t* hasht);

#endif /* HASHTABLE_H */
