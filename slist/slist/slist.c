#include "slist.h"
#include <stdlib.h>

SList slist_crear() {
  return NULL;
}

void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

int slist_vacia(SList lista) {
  return lista == NULL;
}

SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;
}

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}

int slist_longitud(SList lista){
  int longitud = 0;
  for(SNodo *temp = lista; temp != NULL; temp = temp->sig, longitud++);
  return longitud;
}

void slist_concatenar(SList lista1, SList lista2){
  SNodo *temp = lista1;
  for(; temp->sig != NULL; temp=temp->sig);
  temp->sig = lista2;
  return;
}

SList slist_insertar(SList lista, int dato, int posicion){
  int pos_actual = 1;
  SNodo *temp = lista;
  for(;temp!=NULL && pos_actual<posicion;temp=temp->sig, pos_actual++);
  // Si temp == NULL entonces la posición es mayor a la longitud de la lista
  if(temp==NULL) return slist_agregar_final(lista, dato);
  
  SNodo *nuevo_nodo = malloc(sizeof(SNodo*));
  nuevo_nodo->dato = dato;
  nuevo_nodo->sig = temp->sig;

  temp->sig = nuevo_nodo;

  return lista;
}

void slist_eliminar(SList *lista, int posicion){
  int pos_actual = 1;
  SNodo *temp = *lista;
  for(;temp!=NULL && pos_actual<posicion-1;temp=temp->sig, pos_actual++);
  if(temp==NULL) return;
  
  SNodo *nodo_a_eliminar = temp->sig;
  temp->sig=temp->sig->sig;

  free(nodo_a_eliminar);
  return;
}

int slist_contiene(SList lista, int dato){
  SNodo *temp = lista;
  for(; temp!=NULL && temp->dato!=dato; temp=temp->sig);
  if(temp==NULL) return 0;
  return 1;
}

int slist_indice(SList lista, int dato){
  SNodo *temp = lista;
  int indice = 1;
  for(; temp!=NULL && temp->dato!=dato; temp=temp->sig, indice++);
  if(temp==NULL) return -1;
  return indice;
}

SList slist_intersecar(SList lista1, SList lista2){
  if(lista1 == NULL || lista2 == NULL) return NULL;
  

  SNodo *lista_interseccion = slist_crear();

  SNodo *temp2 = lista2;
  for(;temp2!=NULL; temp2=temp2->sig){
    SNodo *temp1 = lista1;
    for(;temp1!=NULL; temp1=temp1->sig){

      if(temp1->dato == temp2->dato && !slist_contiene(lista_interseccion,temp1->dato)){
        lista_interseccion = slist_agregar_inicio(lista_interseccion,temp1->dato);
      }
    }
  }

  return lista_interseccion;
}



SList slist_intersecar_custom(SList lista1, SList lista2, FuncionCmp son_iguales){
  if(lista1 == NULL || lista2 == NULL) return NULL;
  

  SNodo *lista_interseccion = slist_crear();

  SNodo *temp2 = lista2;
  for(;temp2!=NULL; temp2=temp2->sig){
    SNodo *temp1 = lista1;
    for(;temp1!=NULL; temp1=temp1->sig){

      if(son_iguales(temp1->dato, temp2->dato) && !slist_contiene(lista_interseccion,temp1->dato)){
        lista_interseccion = slist_agregar_inicio(lista_interseccion,temp1->dato);
      }
    }
  }

  return lista_interseccion;
}


// Selection sort:
void swap_data_slist(SList lista1, SList lista2){
  int temp_data = lista1->dato;
  lista1->dato = lista2->dato;
  lista2->dato = temp_data;
}

SList slist_ordenar(SList lista, FuncionCmp funcion_comp){
  if(lista == NULL || lista->sig == NULL) return lista;

  SNodo *min_nodo;
  SNodo *temp_nodo;

  for(SNodo *i = lista; i->sig!=NULL; i=i->sig){
    min_nodo = i;
    for(SNodo *j = i->sig; j!=NULL; j=j->sig){
      if(funcion_comp(j->dato, min_nodo->dato)==1) // j->dato > min_nodo->dato
        min_nodo = j;
    }

    if(min_nodo != i)
      swap_data_slist(i,min_nodo);

  }
}

SList slist_reverso(SList lista, FuncionCmp funcion_comp){
  if(lista == NULL || lista->sig == NULL) return lista;

  SNodo *prev = slist_crear();
  SNodo *current = lista;
  SNodo *next = slist_crear();

  while(current!=NULL){
    next = current->sig;
    current->sig = prev;
    prev = current;
    current = next;
  }

  return prev;
}


SList slist_intercalar(SList lista1, SList lista2){
  
  SNodo *temp1 = lista1;
  SNodo *temp2 = lista2;

  SList nueva_lista = NULL;

  while(temp1!=NULL || temp2!=NULL){
    if(temp1!=NULL) // -> temp2 !=NULL
      nueva_lista = slist_agregar_final(nueva_lista, temp1->dato);
    
    if(temp2!=NULL)
      nueva_lista = slist_agregar_final(nueva_lista, temp2->dato);
    

    if(temp2!=NULL)
      temp2=temp2->sig; 
    
    if(temp1!=NULL)
      temp1=temp1->sig;
  }
  
  return nueva_lista;
}


SNodo* slist_partir(SList lista){
  int longitud_lista = slist_longitud(lista);
  int mitad;
  mitad = (longitud_lista%2!=0 ? longitud_lista/2+1:longitud_lista/2);

  SNodo *temp_nodo = lista;
  for(int pos_nodo=1;pos_nodo < mitad;pos_nodo++, temp_nodo = temp_nodo->sig);
  SNodo *segunda_lista = temp_nodo->sig;
  temp_nodo->sig = NULL;

  return segunda_lista;
}

