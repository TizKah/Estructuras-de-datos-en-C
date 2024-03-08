#include <stdlib.h>
#include "dlist.h"


DList DList_crear(FuncionComparadora comp, FuncionCopiadora copy, 
                FuncionDestructora destr, FuncionVisitante visit){

    DList lista = malloc(sizeof(struct _DList));
    lista->primero = NULL;
    lista->ultimo = NULL;
    lista->comp = comp;
    lista->copy = copy;
    lista->destr = destr;
    lista->visit = visit;
    return lista;
}



void DList_destruir_aux(DNodo* lista, FuncionDestructora destr) {
    if (!lista)
        return;

    DNodo* nodo_actual = lista;
    DNodo* nodo_siguiente;

    do {
        nodo_siguiente = nodo_actual->sig;
        destr(nodo_actual->dato);
        free(nodo_actual);
        nodo_actual = nodo_siguiente;
    } while (nodo_actual != lista);
}

void DList_destruir(DList lista){
    if(!lista)
        return;

    DList_destruir_aux(lista->primero, lista->destr);
    lista->primero = NULL;
    lista->ultimo = NULL;
    free(lista);
}

int DList_vacia(DList lista){
    return !lista->primero;
}


DList DList_agregar_final(DList lista, void* dato){
    DNodo *nodo_nuevo = malloc(sizeof(struct _DNodo));
    nodo_nuevo->dato = lista->copy(dato);
    nodo_nuevo->sig = NULL;
    nodo_nuevo->ant = NULL;

    if(!lista->primero){
        lista->primero = nodo_nuevo;
        lista->ultimo = nodo_nuevo;
        return lista;
    }

    nodo_nuevo->sig = lista->ultimo->sig;
    lista->ultimo->sig = nodo_nuevo;
    nodo_nuevo->ant = lista->ultimo;
    lista->ultimo = nodo_nuevo;
    return lista;
}


DList DList_agregar_inicio(DList lista, void* dato){
    DNodo *nodo_a_agregar = malloc(sizeof(struct _DNodo));
    nodo_a_agregar->dato = lista->copy(dato);
    nodo_a_agregar->sig = NULL;
    nodo_a_agregar->ant = NULL;
    
    if(!lista->primero){
        lista->primero=nodo_a_agregar;
        lista->ultimo=nodo_a_agregar;
        return lista;
    }

    nodo_a_agregar->ant = lista->ultimo;
    lista->primero->ant = nodo_a_agregar;
    nodo_a_agregar->sig = lista->primero;
    lista->ultimo->sig = nodo_a_agregar;
    lista->primero = nodo_a_agregar;
    return lista;
}


void DList_recorrer(DList lista){
    if(!lista->primero)
        return;

    DNodo *nodo_a_visitar=lista->primero;

    do{
        lista->visit(nodo_a_visitar->dato);
        nodo_a_visitar=nodo_a_visitar->sig;
    }while(nodo_a_visitar && nodo_a_visitar!=lista->primero);
}

int DList_longitud(DList lista){
    if(!lista->primero)
        return 0;

    DNodo *nodo_temp = lista->primero;
    int longitud = 0;
    do{
        longitud++;
        nodo_temp=nodo_temp->sig;
    }while(nodo_temp!=lista->primero);

    return longitud;
}

void DList_concatenar(DList lista1, DList lista2){
    if(!lista1){
        lista1=lista2;
        return;
    }
    if(!lista2)
        return;
    
    lista1->ultimo->sig = lista2->primero;
    lista2->primero->ant = lista1->ultimo;

    lista2->ultimo->sig = lista1->primero;
    lista1->primero->ant = lista2->ultimo;

    free(lista2);
}


DList DList_insertar(DList lista, void* dato, int posicion){
    DNodo *nodo_a_insertar = malloc(sizeof(struct _DNodo));
    nodo_a_insertar->dato = lista->copy(dato);
    


    if(!lista->primero)
        return 
}

/* 

void DList_eliminar(DList *lista, int posicion){

}


int DList_contiene(DList lista, void* dato){

}

int DList_indice(DList lista, void* dato){

}

DList DList_intersecar(DList lista1, DList lista2){

}

DList DList_intersecar_custom(DList lista1, DList lista2, FuncionComparadora son_iguales){

}

DList DList_ordenar(DList lista, FuncionComparadora R_Orden){

}

void swap_data_DList(DList lista1, DList lista2){

}

DList DList_reverso(DList lista, FuncionComparadora funcion_comp){

}

DList DList_intercalar(DList lista1, DList lista2){

}

DNodo* DList_partir(DList lista){

}
 */