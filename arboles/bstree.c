#include "bstree.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Estructura del nodo del arbol de busqueda binaria.
 * Tiene un puntero al dato (dato),
 * un puntero al nodo raiz del subarbol izquierdo (izq),
 * y un puntero al nodo raiz del subarbol derecho (der).
 */
struct _BST_Nodo {
  void *dato;
  struct _BST_Nodo *izq, *der;
};

/**
 * bstee_crear: Retorna un arbol de busqueda binaria vacio
 */
BSTree bstee_crear() { return NULL; }

/**
 * bstree_destruir: Destruye el arbol y sus datos
 */
void bstree_destruir(BSTree raiz, FuncionDestructora destr) {
  if (raiz != NULL) {
    bstree_destruir(raiz->izq, destr);
    bstree_destruir(raiz->der, destr);
    destr(raiz->dato);
    free(raiz);
  }
};

/**
 * bstree_buscar: Retorna 1 si el dato se encuentra y 0 en caso
 * contrario
 */
int bstree_buscar(BSTree raiz, void *dato, FuncionComparadora comp) {
  if (raiz == NULL)
    return 0;
  else if (comp(dato, raiz->dato) == 0) // raiz->dato == dato
    return 1;
  else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    return bstree_buscar(raiz->izq, dato, comp);
  else // raiz->dato < dato
    return bstree_buscar(raiz->der, dato, comp);
}

/**
 * bstree_insertar: Inserta un dato no repetido en el arbol, manteniendo la
 * propiedad del arbol de busqueda binaria
 */
BSTree bstree_insertar(BSTree raiz, void *dato, FuncionCopiadora copia,
                       FuncionComparadora comp) {
  if (raiz == NULL) { // insertar el dato en un nuevo nodo
    struct _BST_Nodo *nuevoNodo = malloc(sizeof(struct _BST_Nodo));
    assert(nuevoNodo != NULL);
    nuevoNodo->dato = copia(dato);
    nuevoNodo->izq = nuevoNodo->der = NULL;
    return nuevoNodo;
  } else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    raiz->izq = bstree_insertar(raiz->izq, dato, copia, comp);
  else if (comp(dato, raiz->dato) > 0) // raiz->dato < dato
    raiz->der = bstree_insertar(raiz->der, dato, copia, comp);
  // si el dato ya se encontraba, no es insertado
  return raiz;
}

/**
 * bstree_recorrer: Recorrido DSF del arbol
 */
void bstree_recorrer(BSTree raiz, BSTreeRecorrido orden,
                     FuncionVisitanteExtra visita, void *extra) {
  if (raiz != NULL) {
    if (orden == BTREE_RECORRIDO_PRE)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->izq, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_IN)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->der, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_POST)
      visita(raiz->dato, extra);
  }
}



void buscar_nodo_eliminar(BSTree* nodoActual, BSTree* nodoPadre, void* dato, FuncionComparadora comp){
  while (*nodoActual != NULL && comp(dato, (*nodoActual)->dato) != 0) {
    *nodoPadre = *nodoActual;
    if(comp(dato, (*nodoActual)->dato) < 0) {
        *nodoActual = (*nodoActual)->izq;
    }else {
      if (comp(dato, (*nodoActual)->dato) > 0)
        *nodoActual = (*nodoActual)->der;
    }
    }
}

BSTree nodoMin(BSTree raiz) {
  if (raiz->izq->izq==NULL)
  {
    return raiz;
  } else{
    return nodoMin(raiz->izq);
  }
  
}

/* BSTree bstree_eliminar(BSTree arbol, void * dato, FuncionComparadora comp, FuncionDestructora destroy){

  if(arbol == NULL)
    return arbol;

  int comparacion = comp(dato,arbol->dato);
  if(comparacion < 0)
    arbol->izq = bstree_eliminar(arbol->izq, dato, (FuncionComparadora)comp, (FuncionDestructora)destroy);
  else if(comparacion > 0)
    arbol->der = bstree_eliminar(arbol->der, dato,(FuncionComparadora)comp, (FuncionDestructora)destroy);

  else if (comparacion == 0){ //Se encontró el nodo
    //Segundo caso: El nodo a eliminar tiene un único hijo.
    BSTree temp;
    if(arbol->der == NULL){
      temp = arbol->izq;
      destroy(arbol->dato);
      free(arbol);
      return temp;
    } else if (arbol->izq==NULL){
      temp = arbol->der;
      destroy(arbol->dato);
      free(arbol);
      return temp;
    }
    //Tercer caso: El nodo a eliminar tiene dos hijos.
      BSTree minNodo = nodoMin(arbol->der);
      
      strcpy(arbol->dato, minNodo->dato);
      arbol->der = bstree_eliminar(arbol->der, arbol->dato, (FuncionComparadora)comp, (FuncionDestructora)destroy);
    }
  return arbol;
}
 */


BSTree nodoMinDeletePadre(BSTree raiz){
  BSTree padre = bstee_crear();
  while (raiz->izq!=NULL)
  {
    padre = raiz;
    raiz = raiz->izq;
  }
  padre->izq = NULL;
  return raiz;
}


BSTree bstree_padre_sucesor_inorder (BSTree arbol) {
  while (arbol->izq->izq != NULL)
    arbol = arbol->izq;
  return arbol;
}

BSTree bstree_eliminar (BSTree arbol, void *dato, FuncionComparadora comp, FuncionDestructora destroy){


  if (arbol == NULL) return NULL;
  int resultadoComparacion = comp (dato, arbol->dato);
  
  if (resultadoComparacion > 0)
  arbol->der = bstree_eliminar (arbol->der, dato, comp, destroy);
  if (resultadoComparacion < 0)
  arbol->izq = bstree_eliminar (arbol->izq, dato, comp, destroy);

  //ARBOL = nodo a eliminar.
  if (resultadoComparacion== 0 ){
    //printf("\"%s\" ", arbol->dato);

    if (arbol->izq == NULL && arbol->der == NULL){
      destroy(arbol->dato);
      free(arbol);
      return NULL;
    }

    else if (arbol->izq != NULL && arbol->der != NULL) {
      BSTree padreSucesor = bstree_padre_sucesor_inorder (arbol->der);
      BSTree sucesor = padreSucesor ->izq;
      padreSucesor->izq = (sucesor->der == NULL)? NULL: sucesor->der;

      sucesor->izq = arbol->izq;
      sucesor->der = arbol->der;
      destroy(arbol->dato);
      free(arbol);
      return sucesor;
    }
    else {
      BSTree aux = (arbol->izq== NULL) ? arbol->der : arbol->izq;
      destroy(arbol->dato);
      free (arbol);
      return aux;
  }}
}


int btree_validar(BSTree raiz, FuncionComparadora comp){
  if (raiz == NULL) {
    return 1;  // Árbol vacío es un ABB válido
  }

  int esABB = 1;

  if (raiz->izq != NULL) {
    if (comp(raiz->izq->dato, raiz->dato) >= 0) {
      esABB = 0;
    } else {
      esABB = esABB && btree_validar(raiz->izq, comp);
    }
  }

  if (raiz->der != NULL) {
    if (comp(raiz->der->dato, raiz->dato) <= 0) {
      esABB = 0;
    } else {
      esABB = esABB && btree_validar(raiz->der, comp);
    }
  }

  return esABB;
}

