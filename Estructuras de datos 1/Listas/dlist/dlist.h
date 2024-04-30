#ifndef __DList_H__
#define __DList_H__

#include <stddef.h>

typedef void *(*FuncionCopiadora)(void *);
typedef int (*FuncionComparadora)(void *, void *);
typedef void (*FuncionDestructora)(void *);
typedef void (*FuncionVisitante)(void *);

typedef struct _DNodo
{
    void *dato;
    struct _DNodo* sig;
    struct _DNodo* ant;
} DNodo;

typedef struct _DList
{
    DNodo *primero;
    DNodo *ultimo;
    FuncionComparadora comp;
    FuncionCopiadora copy;
    FuncionDestructora destr;
    FuncionVisitante visit;
} *DList;


/**
 * Devuelve una lista vacía.
 */
DList DList_crear(FuncionComparadora comp, FuncionCopiadora copy, 
                FuncionDestructora destr, FuncionVisitante visit);

/**
 * Destruccion de la lista.
 */
void DList_destruir(DList lista);

/**
 * Determina si la lista es vacía.
 */
int DList_vacia(DList lista);

/**
 * Agrega un elemento al final de la lista.
 */
DList DList_agregar_final(DList lista, void* dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
DList DList_agregar_inicio(DList lista, void* dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void DList_recorrer(DList lista);

/* 
    Devuelve la longitud de la lista. 
*/
int DList_longitud(DList lista);

// Concatena dos listas, modificando la primer lista.
void DList_concatenar(DList lista1, DList lista2);

// Inserta un dato en la lista en una posición elegida por el usuario.
DList DList_insertar(DList lista, void* dato, int posicion);

// Elimina de la lista un dato en una posición dada por el usuario.
void DList_eliminar(DList *lista, int posicion);

// Devuelve 0 o 1 respecto a si el elemento "dato" está en la lista o no.
int DList_contiene(DList lista, void* dato);

// Devuelve la posición de la primera ocurrencia de un elemento si el mismo está enla lista dada, y -1 en caso que no esté
int DList_indice(DList lista, void* dato);

// Devuelve una nueva lista con los elementos en común entre las dos listas. No se modifican las originales.
DList DList_intersecar(DList lista1, DList lista2);

DList DList_intersecar_custom(DList lista1, DList lista2, FuncionComparadora son_iguales);

DList DList_ordenar(DList lista, FuncionComparadora R_Orden);

void swap_data_DList(DList lista1, DList lista2);

DList DList_ordenar(DList lista, FuncionComparadora R_Orden);

DList DList_reverso(DList lista, FuncionComparadora funcion_comp);

DList DList_intercalar(DList lista1, DList lista2);

DNodo* DList_partir(DList lista);


#endif