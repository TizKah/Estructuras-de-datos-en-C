#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef void (*FuncionVisitante) (int dato);
typedef int (*FuncionCmp) (int dato1, int dato2);

typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

typedef struct _SList
{
    SNodo *primero;
    SNodo *ultimo;
} SList;

/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList lista);

/**
 * Determina si la lista es vacía.
 */
int slist_vacia(SList lista);

/**
 * Agrega un elemento al final de la lista.
 */
SList slist_agregar_final(SList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
SList slist_agregar_inicio(SList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

// Devuelve la longitud de la lista.
int slist_longitud(SList lista);

// Concatena dos listas, modificando la primer lista.
void slist_concatenar(SList lista1, SList lista2);

// Inserta un dato en la lista en una posición elegida por el usuario.
SList slist_insertar(SList lista, int dato, int posicion);

// Elimina de la lista un dato en una posición dada por el usuario.
void slist_eliminar(SList *lista, int posicion);

// Devuelve 0 o 1 respecto a si el elemento "dato" está en la lista o no.
int slist_contiene(SList lista, int dato);

// Devuelve la posición de la primera ocurrencia de un elemento si el mismo está enla lista dada, y -1 en caso que no esté
int slist_indice(SList lista, int dato);

// Devuelve una nueva lista con los elementos en común entre las dos listas. No se modifican las originales.
SList slist_intersecar(SList lista1, SList lista2);

SList slist_intersecar_custom(SList lista1, SList lista2, FuncionCmp son_iguales);

SList slist_ordenar(SList lista, FuncionCmp R_Orden);

void swap_data_slist(SList lista1, SList lista2);

SList slist_ordenar(SList lista, FuncionCmp R_Orden);

SList slist_reverso(SList lista, FuncionCmp funcion_comp);

SList slist_intercalar(SList lista1, SList lista2);

SNodo* slist_partir(SList lista);

#endif /* __SLIST_H__ */
