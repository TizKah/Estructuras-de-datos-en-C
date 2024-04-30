#include <stdio.h>
#include <stdlib.h>
#include "pagoda.h"

static Pagoda get_extremo_inferior_rama_der(Pagoda p1, int eliminar_ptr_padre){
    Pagoda extremo_inferior = p1;
    Pagoda padre = p1;

    while(extremo_inferior && extremo_inferior->der){
        padre = extremo_inferior;
        extremo_inferior = extremo_inferior->der;
    }
    
    if(eliminar_ptr_padre && padre != extremo_inferior)
        padre->der = NULL;

    return extremo_inferior;
}

static Pagoda get_extremo_inferior_rama_izq(Pagoda p1, int eliminar_ptr_padre){
    Pagoda extremo_inferior = p1;
    Pagoda padre = p1;

    while(extremo_inferior && extremo_inferior->izq){
        padre = extremo_inferior;
        extremo_inferior = extremo_inferior->izq;
    }
    
    if(eliminar_ptr_padre && padre != extremo_inferior)
        padre->izq = NULL;

    return extremo_inferior;
}

static Pagoda insert_nueva_raiz_hijo_der(Pagoda nueva_pagoda, Pagoda extremo_inferior_der){
    /* Asignamos el padre */
    if(nueva_pagoda)
        nueva_pagoda->D = extremo_inferior_der;
    
    /* Asignamos el nodo mas a la izquierda de forma 'recursiva' */
    if(extremo_inferior_der->izq)
        extremo_inferior_der->G = extremo_inferior_der->izq->G;

    /* Asignamos el extremo inferior de la rama derecha como nueva raiz */
    extremo_inferior_der->der = nueva_pagoda;
    return extremo_inferior_der;
}

static Pagoda insert_nueva_raiz_hijo_izq(Pagoda nueva_pagoda, Pagoda extremo_inferior_izq){
    /* Asignamos el padre */
    if(nueva_pagoda)
        nueva_pagoda->G = extremo_inferior_izq;

    /* Asignamos el nodo mas a la derecha de forma 'recursiva' */
    if(extremo_inferior_izq->der)
        extremo_inferior_izq->D = extremo_inferior_izq->der->D;
    
    /* Asignamos el extremo inferior de la rama izquierda como nueva raiz */
    extremo_inferior_izq->izq = nueva_pagoda;
    return extremo_inferior_izq;
}

Pagoda crear_pagoda(){ return NULL;}

Pagoda inicializar_nodo_pagoda_con_valores(int valor, unsigned int prioridad){
    Pagoda nuevo_elemento = malloc(sizeof(struct _Pagoda));
    if (nuevo_elemento == NULL)
        return NULL;
    nuevo_elemento->dato = valor;
    nuevo_elemento->prioridad = prioridad;
    nuevo_elemento->izq = NULL;
    nuevo_elemento->der = NULL;
    nuevo_elemento->D = nuevo_elemento;
    nuevo_elemento->G = nuevo_elemento;
    return nuevo_elemento;
}

Pagoda union_pagoda(Pagoda p1, Pagoda p2){
    Pagoda nueva_pagoda = crear_pagoda();

    int eliminar_ptr_padre = 1;
    /* 
        Para todo subarbol que agreguemos como raiz:
        - Todos sus elementos ya tienen el ptr al padre asignados (excepto por la raiz).
        - Lo mismo ocurre para los nodos mas a la izquierda y derecha, G y D, respectivamente.
    */
    
    Pagoda extremo_inferior_der = crear_pagoda();
    Pagoda extremo_inferior_izq = crear_pagoda();
    /* pX == extremo_inferior_X -> pX ya fue insertado completamente (pX vacio). */
    while(p1 != extremo_inferior_der && p2 != extremo_inferior_izq){
        extremo_inferior_der = get_extremo_inferior_rama_der(p1, eliminar_ptr_padre);
        extremo_inferior_izq = get_extremo_inferior_rama_izq(p2, eliminar_ptr_padre);

        if(extremo_inferior_der->prioridad >= extremo_inferior_izq->prioridad)
            nueva_pagoda = insert_nueva_raiz_hijo_der(nueva_pagoda, extremo_inferior_der);
        else 
            nueva_pagoda = insert_nueva_raiz_hijo_izq(nueva_pagoda, extremo_inferior_izq);
    }

    /* 
        p1 != extremo_inferior_der -> p2 es vacio
        p2 != extremo_inferior_izq -> p1 es vacio
     */
    if(p1 != extremo_inferior_der){ // p2 vacio
        extremo_inferior_der = get_extremo_inferior_rama_der(p1,!eliminar_ptr_padre);
        if(nueva_pagoda)
            nueva_pagoda->D = extremo_inferior_der;
        extremo_inferior_der->der = nueva_pagoda;
        nueva_pagoda = p1;
    }
    else if (p2 != extremo_inferior_izq) { // p1 vacio
        extremo_inferior_izq = get_extremo_inferior_rama_izq(p2, !eliminar_ptr_padre);
        if(nueva_pagoda)
            nueva_pagoda->G = extremo_inferior_izq;
        extremo_inferior_izq->izq = nueva_pagoda;
        nueva_pagoda = p2;
    }

    return nueva_pagoda;
}

Pagoda insert_pagoda(Pagoda p, int valor, unsigned int prioridad){
    Pagoda nuevo_elemento = inicializar_nodo_pagoda_con_valores(valor, prioridad);

    p = union_pagoda(p, nuevo_elemento);
    return p;
}

int top_pagoda(Pagoda p){
    /* 
        Por las condiciones dadas para hacer la union, podemos saber que se trata de un max heap
        pues siempre ponemos de raiz al extremo que tiene mayor prioridad. Tambien implementamos
        el insert con la union, por lo tanto, el elemento de mayor prioridad estara de raiz.
    */
    if(p)
        return p->dato;
    printf("No hay datos en la Pagoda.\n");
    return -1;
}

Pagoda pop_pagoda(Pagoda p){
    /* 
        Dado que el elemeneto de mayor prioridad se situa en la raiz, podemos utilizar la union
        para unir el subarbol derecho con el subarbol izquierdo, creando la nueva pagoda
        sin la raiz original, es decir, sin el elemento de mayor prioridad de p.
     */
    Pagoda nodo_a_eliminar = p;
    p = union_pagoda(p->der, p->izq);
    
    free(nodo_a_eliminar);
    return p;
}

void destruir_pagoda(Pagoda p){
    if(!p)
        return;

    destruir_pagoda(p->izq);
    destruir_pagoda(p->der);
    
    free(p);
}






