#ifndef __PILA.H__
#define __PILA.H__

#include "../glist/glist/glist.h"


struct _Pila
{
    GList lista;
    GNode* ultimo;
    FuncionCopia copy;
    FuncionDestructora destroy;
    FuncionComparadora comp;
    FuncionVisitante visit;
};

typedef struct _Pila *Pila;


Pila pila_crear(FuncionCopia c, FuncionDestructora d, 
    FuncionComparadora comp, FuncionVisitante v);

void pila_destruir(Pila pila);

int pila_es_vacia(Pila pila);

void* pila_tope(Pila pila);

void pila_apilar(Pila pila, void *elemento);

void pila_desapilar(Pila pila);

void pila_imprimir(Pila pila);


#endif