#include "btree.h"
#include <assert.h>
#include <stdlib.h>

#define not NULL==


struct _BTNodo {
  int dato;
  struct _BTNodo *left;
  struct _BTNodo *right;
};

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear() { return NULL; }

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo) { return nodo == NULL; }

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right) {
  BTree nuevoNodo = malloc(sizeof(struct _BTNodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->dato = dato;
  nuevoNodo->left = left;
  nuevoNodo->right = right;
  return nuevoNodo;
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitante visit) {
  if(arbol==NULL) return;
  
  switch (orden)
  {
  case BTREE_RECORRIDO_PRE: // raíz - izq - der
    visit(arbol->dato);
    btree_recorrer(arbol->left, orden, visit);
    btree_recorrer(arbol->right, orden, visit);
    break;
  case BTREE_RECORRIDO_IN: // izq - raíz - der
    btree_recorrer(arbol->left, orden, visit);
    visit(arbol->dato);
    btree_recorrer(arbol->right, orden, visit);
    break;
  case BTREE_RECORRIDO_POST: // izq - der - raíz
    btree_recorrer(arbol->left, orden, visit);
    btree_recorrer(arbol->right, orden, visit);
    visit(arbol->dato);
    break;
  }

  return;
}


/* 
  Retorna el número de nodos del árbol.
 */
int btree_nnodos(BTree arbol) {
  if (not arbol) return 0;

  int izquierda = btree_nnodos(arbol->left);
  int derecha = btree_nnodos(arbol->right);

  return 1 + izquierda + derecha;
}


int btree_buscar(BTree arbol, int dato){
  if(not arbol) return 0;
  if(arbol->dato==dato) return 1;

  int dato_encontrado_left = btree_buscar(arbol->left, dato);
  int dato_encontrado_right = btree_buscar(arbol->right, dato);

  if(dato_encontrado_right || dato_encontrado_left) return 1;
};

BTree btree_copiar(BTree arbol){
  if(not arbol) return arbol;

  BTree raiz_copia = malloc(sizeof(struct _BTNodo));
  raiz_copia->dato = arbol->dato;
  raiz_copia->left = btree_copiar(arbol->left);
  raiz_copia->right = btree_copiar(arbol->right);

  return raiz_copia;
};

int btree_altura(BTree arbol){
  if(not arbol) return 0;

  int altura_izq = btree_altura(arbol->left);
  int altura_der = btree_altura(arbol->right);

  return (altura_der > altura_izq ? altura_der :altura_izq)+1;
};

int btree_nnodos_profundidad_aux(BTree arbol, int profundidad, int profundidad_actual){
  if(not arbol) return 0;

  if(profundidad==profundidad_actual) return 1;

  int nodos_izq = btree_nnodos_profundidad_aux(arbol->left, profundidad, profundidad_actual+1);
  int nodos_der = btree_nnodos_profundidad_aux(arbol->right, profundidad, profundidad_actual+1);


  return nodos_der + nodos_izq;

}

int btree_nnodos_profundidad(BTree arbol, int profundidad){
  return btree_nnodos_profundidad_aux(arbol, profundidad,0);
};

int btree_profundidad_aux(BTree arbol, int dato, int profundidad){
  if(not arbol) return -1;
  if(arbol->dato==dato) return profundidad;

  int profundidad_izq = btree_profundidad_aux(arbol->left, dato, profundidad+1);
  int profundidad_der = btree_profundidad_aux(arbol->right, dato, profundidad+1);

  return(profundidad_izq>profundidad_der ? profundidad_izq : profundidad_der);

};

int btree_profundidad(BTree arbol, int dato){
  return btree_profundidad_aux(arbol, dato, 0);
};

int btree_sumar(BTree arbol){
  if(not arbol) return 0;

  int suma_izq = btree_sumar(arbol->left);
  int suma_der = btree_sumar(arbol->right);

  return suma_izq+suma_der+arbol->dato;
};


void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden,
FuncionVisitanteExtra visit, void *extra){
  if(arbol==NULL) return;
  
  switch (orden)
  {
  case BTREE_RECORRIDO_PRE: // raíz - izq - der
    visit(arbol->dato, extra);
    btree_recorrer_extra(arbol->left, orden, visit, extra);
    btree_recorrer_extra(arbol->right, orden, visit, extra);
    break;
  case BTREE_RECORRIDO_IN: // izq - raíz - der
    btree_recorrer_extra(arbol->left, orden, visit, extra);
    visit(arbol->dato, extra);
    btree_recorrer_extra(arbol->right, orden, visit, extra);
    break;
  case BTREE_RECORRIDO_POST: // izq - der - raíz
    btree_recorrer_extra(arbol->left, orden, visit, extra);
    btree_recorrer_extra(arbol->right, orden, visit, extra);
    visit(arbol->dato, extra);
    break;
  }

  return;
};


int btree_sumar_extra(BTree arbol, FuncionVisitanteExtra visit){
  int suma = 0;
  btree_recorrer_extra(arbol, BTREE_RECORRIDO_IN, visit, &suma);
  return suma;
}
  

void btree_recorrer_bfs_recursivo_aux(BTree arbol, FuncionVisitante visit, int profundidad, int profundidad_actual){
  if(not arbol) return;
  if(profundidad==profundidad_actual) visit(arbol->dato);

  btree_recorrer_bfs_recursivo_aux(arbol->left, visit, profundidad, profundidad_actual+1);
  btree_recorrer_bfs_recursivo_aux(arbol->right, visit, profundidad, profundidad_actual+1);
}

void btree_recorrer_bfs_recursivo(BTree arbol, FuncionVisitante visit){
  if(not arbol) return;

  int altura_arbol = btree_altura(arbol);

  for(int profundidad = 0; profundidad<altura_arbol; profundidad++)
    btree_recorrer_bfs_recursivo_aux(arbol, visit, profundidad, 0);

};


void btree_recorrer_bfs_iterativo(BTree arbol, FuncionVisitante visit){
  if(not arbol) return;

  int cant_nodos = btree_nnodos(arbol);

  BTree nodo_temp = arbol;
  for(int nodos=0; nodos<cant_nodos; nodos++){

  }


};
