#include "glist.h"
#include <assert.h>
#include <stdlib.h>

/**
 * Devuelve una lista vacía.
 */
GList glist_crear() { return NULL; }

/**
 * Destruccion de la lista.
 * destroy es una función que libera el dato almacenado.
 */
void glist_destruir(GList list, FuncionDestructora destroy) {
  GNode *nodeToDelete;
  while (list != NULL) {
    nodeToDelete = list;
    list = list->next;
    destroy(nodeToDelete->data);
    free(nodeToDelete);
  }
}

/**
 * Determina si la lista es vacía.
 */
int glist_vacia(GList list) { return (list == NULL); }

/**
 * Agrega un elemento al inicio de la lista.
 * copy es una función que retorna una copia física del dato.
 */
GList glist_agregar_inicio(GList list, void *data, FuncionCopia copy) {
  GNode *newNode = malloc(sizeof(GNode));
  assert(newNode != NULL);
  newNode->next = list;
  newNode->data = copy(data);
  return newNode;
}

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void glist_recorrer(GList list, FuncionVisitante visit) {
  for (GNode *node = list; node != NULL; node = node->next)
    visit(node->data);
}




GList glist_filtrar(GList lista, FuncionCopia c, Predicado p){
  GList lista_filtrada = glist_crear();
  GNode *temp = lista;
  for(;temp!=NULL; temp=temp->next){
    if(p(temp->data))
      lista_filtrada = glist_agregar_inicio(lista_filtrada, temp->data, c);
  }

  return lista_filtrada;
}









SGList sglist_crear(){return NULL;};

void sglist_destruir(SGList lista, FuncionDestructora d){
  GNode *nodo_a_destruir;
  while(nodo_a_destruir!=NULL){
    nodo_a_destruir = lista;
    lista=lista->next;
    d(nodo_a_destruir->data);
    free(nodo_a_destruir);
  }
}

int sglist_vacia(SGList lista){
  return (lista==NULL);
}

void sglist_recorrer(SGList lista, FuncionVisitante visit){
  for(GNode *temp_nodo = lista ;temp_nodo!=NULL; temp_nodo=temp_nodo->next){
    visit(temp_nodo->data);
  }
}

SGList sglist_insertar(SGList lista, void* dato, FuncionCopia c, FuncionComparadora comp){
  GNode *nodo_a_insertar = malloc(sizeof(GNode*));
  nodo_a_insertar->data = c(dato);
  nodo_a_insertar->next = NULL;
  
  if(lista==NULL) return nodo_a_insertar;
  
  if(comp(lista->data,dato)>0){
    GNode *nodo_temp = lista;
    lista = nodo_a_insertar;
    lista->next = nodo_temp;
  }
  
  
  GNode *nodo_temp = lista;
  for(; nodo_temp->next!=NULL && comp(nodo_temp->next->data, dato)<=0; nodo_temp=nodo_temp->next);
  if(nodo_temp->next==NULL)
    nodo_temp->next = nodo_a_insertar;
  else{
    GNode *nodo_temp2 = nodo_temp->next;
    nodo_temp->next = nodo_a_insertar;
    nodo_a_insertar->next = nodo_temp2;
  }

  return lista;
}

int sglist_buscar(SGList lista, void *dato, FuncionComparadora comp){
  GNode *nodo_temp = lista;
  for(;nodo_temp!=NULL && comp(nodo_temp->data,dato)>0;nodo_temp=nodo_temp->next);
  return (nodo_temp==NULL);
}

SGList sglist_arr(void **arr, int longitud, FuncionCopia c, FuncionComparadora comp){
  SGList lista = sglist_crear();
  
  for(int i = 0; i<longitud;i++){
    sglist_insertar(lista,arr[i],(FuncionCopia)c,(FuncionComparadora)comp);
  }

  return lista;
}
