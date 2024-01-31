#include "slist.h"
#include <stdlib.h>


SList slist_crear(){
    SList lista;
    lista.primero = NULL;
    lista.ultimo = NULL;
    return lista;
}

SList slist_agregar_inicio(SList lista, int dato){
    SList nueva_lista;
    nueva_lista.ultimo = lista.ultimo;
    nueva_lista.primero->dato = dato;
    nueva_lista.primero->sig = lista.primero;
    return nueva_lista;
}

SList slist_agregar_final(SList lista, int dato){
    SNodo *ultimo_nodo = malloc(sizeof(SNodo*));
    ultimo_nodo->dato = dato;
    ultimo_nodo->sig = NULL;

    lista.ultimo->sig = ultimo_nodo;
    lista.ultimo = ultimo_nodo;
    return lista;
}
