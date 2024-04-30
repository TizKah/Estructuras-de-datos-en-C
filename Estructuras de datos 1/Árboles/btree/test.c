#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

static void imprimir_entero(int data) {
  printf("%d ", data);
}

void sumar_nodos(int valor_nodo, void *suma){
  int *suma_int = (int*) suma;
  *suma_int = *suma_int + valor_nodo;
}


int main() {
  BTree lll = btree_unir(6, btree_crear(), btree_crear());
  BTree ll = btree_unir(1, lll, btree_crear());
  BTree rr = btree_unir(-3, btree_crear(), btree_crear());
  BTree rrr = btree_unir(14, btree_crear(), btree_crear());
  BTree l = btree_unir(2, ll, rr);
  BTree r = btree_unir(3, btree_crear(), rrr);
  BTree raiz = btree_unir(4, l, r);

  printf("--- RECORRIDOS ---\n");
  printf("Recorrido post-orden: ");
  btree_recorrer(raiz, BTREE_RECORRIDO_POST, imprimir_entero);
  puts("");

  printf("Recorrido pre-orden: ");
  btree_recorrer(raiz, BTREE_RECORRIDO_PRE, imprimir_entero);
  puts("");


  printf("Recorrido in-orden: ");
  btree_recorrer(raiz, BTREE_RECORRIDO_IN, imprimir_entero);
  puts("");

  puts("");
  puts("");
  printf("--- CANTIDAD NODOS ---\n");
  printf("Cantidad de nodos: %d", btree_nnodos(raiz));
  puts("");


  puts("");
  puts("");
  printf("--- BÚSQUEDA DE DATO ---\n");
  printf("El dato 2 está en el nodo: %d\n", btree_buscar(raiz, 2));
  printf("El dato -8 está en el nodo: %d\n", btree_buscar(raiz, -8));
  printf("El dato 3 está en el nodo: %d\n", btree_buscar(raiz, 3));
  printf("El dato 5 está en el nodo: %d\n", btree_buscar(raiz, 5));
  puts("");

  puts("");
  printf("--- COPIA DE ÁRBOL ---\n");
  BTree raiz_copia = btree_copiar(raiz);
  puts("");
  printf("Recorrido post-orden: ");
  btree_recorrer(raiz_copia, BTREE_RECORRIDO_POST, imprimir_entero);
  puts("");

  printf("Recorrido pre-orden: ");
  btree_recorrer(raiz_copia, BTREE_RECORRIDO_PRE, imprimir_entero);
  puts("");


  printf("Recorrido in-orden: ");
  btree_recorrer(raiz_copia, BTREE_RECORRIDO_IN, imprimir_entero);
  puts("");


  puts("");
  printf("--- ALTURA ÁRBOL ---\n");
  printf("Altura del árbol: %d", btree_altura(raiz));
  puts("");

  puts("");
  puts("");
  printf("--- PROFUNDIDAD NODOS ---\n");
  printf("Cantidad de nodos en la profundidad 1: %d\n", btree_nnodos_profundidad(raiz, 1));
  printf("Cantidad de nodos en la profundidad 2: %d\n", btree_nnodos_profundidad(raiz, 2));
  printf("Cantidad de nodos en la profundidad 3: %d\n", btree_nnodos_profundidad(raiz, 3));
  puts("");
  
  puts("");
  puts("");
  printf("--- PROFUNDIDAD ENCONTRAR DATO ---\n");
  printf("El dato 5 está en la profundidad: %d\n", btree_profundidad(raiz, 5));
  printf("El dato 1 está en la profundidad: %d\n", btree_profundidad(raiz, 1));
  printf("El dato -3 está en la profundidad: %d\n", btree_profundidad(raiz, -3));
  printf("El dato 6 está en la profundidad: %d\n", btree_profundidad(raiz, 6));
  printf("El dato -5 está en la profundidad: %d\n", btree_profundidad(raiz, -5));
  printf("El dato 7 está en la profundidad: %d\n", btree_profundidad(raiz, 7));
  printf("El dato 4 está en la profundidad: %d\n", btree_profundidad(raiz, 4));
  puts("");


  puts("");
  printf("--- SUMA ---\n");
  printf("Suma total de los nodos: %d\n", btree_sumar(raiz));
  puts("");


  puts("");
  printf("--- SUMA CON RECORRER EXTRA ---\n");
  printf("Suma total de los nodos: %d\n", btree_sumar_extra(raiz, (FuncionVisitanteExtra)sumar_nodos));
  puts("");


  puts("");
  puts("");
  printf("--- BFS ---\n");
  printf("Recursivo: ");
  btree_recorrer_bfs_recursivo(raiz, (FuncionVisitante)imprimir_entero);
  puts("");
  printf("Iterativo: ");
  puts("");


  btree_destruir(raiz);

  return 0;
}
