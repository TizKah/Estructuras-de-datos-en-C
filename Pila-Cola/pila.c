#include "pila.h"

Pila pila_crear(int size, 
    FunctionCopy c, FunctionDestroy d, 
    FunctionCompare comp, FunctionVisit v){
    Pila pila = malloc(sizeof(Pila));
    pila->array = array_create(size, c, d, comp, v);
    pila->ultimo = 0;
}

void pila_destruir(Pila pila){
    array_delete(pila->array);
    free(pila);
}

int pila_es_vacia(Pila pila){
    return (pila->ultimo==0);
}

void* pila_tope(Pila pila){
    return pila->array->at[pila->ultimo];
}

void pila_apilar(Pila pila, void *nuevo_elemento){
    int capacidad = pila->array->capacity;
    int ultimo = pila->ultimo;
    if(capacidad==ultimo)
        array_resize(pila->array,capacidad*2);
    
    array_write(pila->array,nuevo_elemento,++(pila->ultimo));
}

void pila_desapilar(Pila pila){
    array_delete(pila->array,--(pila->ultimo));
}

void pila_imprimir(Pila pila, FunctionVisit visit){
    if(pila==NULL) return;

    array_print(pila->array);
}