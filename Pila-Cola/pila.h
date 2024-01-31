#ifndef __PILA.H__
#define __PILA.H__

#include "array.h"

typedef void *(*FunctionCopy)(void*);
typedef void (*FunctionDestroy)(void*);
typedef void (*FunctionVisit)(void*);
typedef void (*FunctionVisitExtra)(void*, void*);
typedef int (*FunctionCompare)(void*, void*);


struct _Pila
{
    Array array;
    int ultimo;
};

typedef struct _Pila *Pila;


Pila pila_crear(int size, 
    FunctionCopy c, FunctionDestroy d, 
    FunctionCompare comp, FunctionVisit v);

void pila_destruir(Pila pila);

int pila_es_vacia(Pila pila);

void* pila_tope(Pila pila);

void pila_apilar(Pila pila, void *elemento);

void pila_desapilar(Pila pila);

void pila_imprimir(Pila pila);


#endif