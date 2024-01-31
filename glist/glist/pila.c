#include "pila.h"
#include <stdint.h>
#include <stdio.h>



Pila pila_crear(FuncionCopia c, FuncionDestructora d, 
    FuncionComparadora comp, FuncionVisitante v){

    Pila pila = malloc(sizeof(Pila));
    pila->lista = glist_crear();
    pila->ultimo = pila->lista;
    pila->copy = c;
    pila->comp = comp;
    pila->visit = v;
    pila->destroy = d;
    
    return pila;
}

void pila_destruir(Pila pila){
    glist_destruir(pila->lista, pila->destroy);
    free(pila);
}

int pila_es_vacia(Pila pila){
    return (glist_vacia(pila->lista));
}

void* pila_tope(Pila pila){
    return pila->ultimo->data;
}

void pila_apilar(Pila pila, void *elemento){
    //Create the new node
    GNode *nodo_nuevo = malloc(sizeof(GNode*));
    nodo_nuevo->data = pila->copy(elemento);
    nodo_nuevo->next = NULL;

    //Add new node
    pila->ultimo->next = nodo_nuevo;
    pila->ultimo = nodo_nuevo;
}

void pila_desapilar(Pila pila){
    GNode *nodo_temp = pila->ultimo->prev;
    pila->destroy(pila->ultimo->data);
    free(pila->ultimo);
    pila->ultimo = nodo_temp;
}

void pila_imprimir(Pila pila){
    glist_recorrer(pila->lista, pila->visit);
}



//Da el reverso de una lista, modificando la original
GList glist_reverso_pila(GList lista, FuncionCopia c, FuncionDestructora d, 
    FuncionComparadora comp, FuncionVisitante v){
    
    Pila pila = pila_crear(c,d,comp,v);
    GNode *nodo_temp = lista;
    for(;nodo_temp!=NULL;nodo_temp=nodo_temp->next){
        pila_apilar(pila,nodo_temp->data);
    }

    //Para no modificar la original aquí simplemente creamos una nueva GList
    nodo_temp = lista;
    while(!pila_es_vacia(pila)){
        nodo_temp->data = c(pila_tope(pila));
        pila_desapilar(pila);
        nodo_temp=nodo_temp->next;
    }

    return lista;
}