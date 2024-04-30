#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

// Inicializar el iterador de la tabla hash en la tabla hash 'ht'
#define HT_ITERATOR(ht) {ht, 0, ht->table[0]}
char err_ptr;
void* HT_ERROR = &err_ptr; // Los datos que apuntan a HT_ERROR se devuelven en caso de error

/* Función interna para calcular el hash para las claves.
   Está basada en el algoritmo DJB de Daniel J. Bernstein.
   La clave debe terminar con el carácter '\0'. */
static unsigned int ht_calc_hash(char* key)
{
    unsigned int h = 5381;
    while (*(key++))
        h = ((h << 5) + h) + (*key);
    return h;
}

/* Crear una tabla hash con capacidad 'capacity' y devolver un puntero a ella */
hashtable_t* ht_create(unsigned int capacity)
{
    hashtable_t* hasht = malloc(sizeof(hashtable_t));
    if (!hasht)
        return NULL;
    if ((hasht->table = malloc(capacity * sizeof(hash_elem_t*))) == NULL)
    {
        free(hasht->table);
        return NULL;
    }
    hasht->capacity = capacity;
    hasht->e_num = 0;
    unsigned int i;
    for (i = 0; i < capacity; i++)
        hasht->table[i] = NULL;
    return hasht;
}

/* Almacenar datos en la tabla hash. Si los datos con la misma clave ya están almacenados,
   se sobrescriben y se devuelven por la función. Si no, devuelve NULL.
   Devuelve HT_ERROR si hay un error de asignación de memoria. */
void* ht_put(hashtable_t* hasht, char* key, void* data)
{
    if (data == NULL)
        return NULL;
    unsigned int h = ht_calc_hash(key) % hasht->capacity;
    hash_elem_t* e = hasht->table[h];

    while (e != NULL)
    {
        if (!strcmp(e->key, key))
        {
            void* ret = e->data;
            e->data = data;
            return ret;
        }
        e = e->next;
    }

    // Llegar aquí significa que la clave aún no existe

    if ((e = malloc(sizeof(hash_elem_t) + strlen(key) + 1)) == NULL)
        return HT_ERROR;
    strcpy(e->key, key);
    e->data = data;

    // Agregar el elemento al principio de la lista enlazada
    e->next = hasht->table[h];
    hasht->table[h] = e;
    hasht->e_num++;

    return NULL;
}

/* Recuperar datos de la tabla hash */
void* ht_get(hashtable_t* hasht, char* key)
{
    unsigned int h = ht_calc_hash(key) % hasht->capacity;
    hash_elem_t* e = hasht->table[h];
    while (e != NULL)
    {
        if (!strcmp(e->key, key))
            return e->data;
        e = e->next;
    }
    return NULL;
}

/* Eliminar datos de la tabla hash. Devuelve los datos eliminados de la tabla
   para que podamos liberar la memoria si es necesario */
void* ht_remove(hashtable_t* hasht, char* key)
{
    unsigned int h = ht_calc_hash(key) % hasht->capacity;
    hash_elem_t* e = hasht->table[h];
    hash_elem_t* prev = NULL;
    while (e != NULL)
    {
        if (!strcmp(e->key, key))
        {
            void* ret = e->data;
            if (prev != NULL)
                prev->next = e->next;
            else
                hasht->table[h] = e->next;
            free(e);
            e = NULL;
            hasht->e_num--;
            return ret;
        }
        prev = e;
        e = e->next;
    }
    return NULL;
}

/* Listar claves. k debería tener una longitud igual o mayor que el número de claves */
void ht_list_keys(hashtable_t* hasht, char** k, size_t len)
{
    if (len < hasht->e_num)
        return;
    int ki = 0; // Índice a la cadena actual en **k
    int i = hasht->capacity;
    while (--i >= 0)
    {
        hash_elem_t* e = hasht->table[i];
        while (e)
        {
            k[ki++] = e->key;
            e = e->next;
        }
    }
}

/* Listar valores. v debería tener una longitud igual o mayor que el número de elementos almacenados */
void ht_list_values(hashtable_t* hasht, void** v, size_t len)
{
    if (len < hasht->e_num)
        return;
    int vi = 0; // Índice a la cadena actual en **v
    int i = hasht->capacity;
    while (--i >= 0)
    {
        hash_elem_t* e = hasht->table[i];
        while (e)
        {
            v[vi++] = e->data;
            e = e->next;
        }
    }
}

/* Iterar a través de los elementos de la tabla. */
hash_elem_t* ht_iterate(hash_elem_it* iterator)
{
    while (iterator->elem == NULL)
    {
        if (iterator->index < iterator->ht->capacity - 1)
        {
            iterator->index++;
            iterator->elem = iterator->ht->table[iterator->index];
        }
        else
            return NULL;
    }
    hash_elem_t* e = iterator->elem;
    if (e)
        iterator->elem = e->next;
    return e;
}

/* Iterar a través de las claves. */
char* ht_iterate_keys(hash_elem_it* iterator)
{
    hash_elem_t* e = ht_iterate(iterator);
    return (e == NULL ? NULL : e->key);
}

/* Iterar a través de los valores. */
void* ht_iterate_values(hash_elem_it* iterator)
{
    hash_elem_t* e = ht_iterate(iterator);
    return (e == NULL ? NULL : e->data);
}

/* Elimina todos los elementos almacenados en la tabla hash.
   Si free_data es verdadero, todos los datos almacenados también se liberan. */
void ht_clear(hashtable_t* hasht, int free_data)
{
    hash_elem_it it = HT_ITERATOR(hasht);
    char* k = ht_iterate_keys(&it);
    while (k != NULL)
    {
        free_data ? free(ht_remove(hasht, k)) : ht_remove(hasht, k);
        k = ht_iterate_keys(&it);
    }
}

/* Destruye la tabla hash y libera la memoria.
   Los datos almacenados aún se liberan. */
void ht_destroy(hashtable_t* hasht)
{
    ht_clear(hasht, 1); // Eliminar y liberar todos los elementos.
    free(hasht->table);
    free(hasht);
}
