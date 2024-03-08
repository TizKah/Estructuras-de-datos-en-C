#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int orden_natural(int dato1, int dato2){
  if(dato1>dato2) return -1;
  if(dato2>dato1) return 1;
  return 0;
}

int main(int argc, char *argv[]) {

  SList lista = slist_crear();

  lista = slist_agregar_inicio(lista, 3);
  lista = slist_agregar_inicio(lista, 2);
  lista = slist_agregar_inicio(lista, 1);
  lista = slist_agregar_final(lista, 4);

  printf("LISTA 1: ");
  slist_recorrer(lista, imprimir_entero);
  puts("");

  SList lista2 = slist_crear();

  lista2 = slist_agregar_inicio(lista2, 1);
  lista2 = slist_agregar_inicio(lista2, 2);
  lista2 = slist_agregar_inicio(lista2, 3);
  lista2 = slist_agregar_final(lista2, 0);

  printf("LISTA 2: ");
  slist_recorrer(lista2, imprimir_entero);
  puts("");

  //Test slist_concatenar
  int suma_longitudes = (slist_longitud(lista) + slist_longitud(lista2));
  slist_concatenar(lista, lista2);
  assert(slist_longitud(lista) == suma_longitudes);

  //Test slist_longitud
  assert(slist_longitud(lista) == 8);

  //Test slist_insertar
  slist_insertar(lista, -5, 3);
  assert(slist_contiene(lista, -5));

  //Test slist_eliminar
  slist_eliminar(&lista,4);
  assert(!slist_contiene(lista, -5));

  //Test slist_contiene
  assert(slist_contiene(lista, 3));
  assert(!slist_contiene(lista, -9));

  //Test slist_indice
  assert(slist_indice(lista, 3) == 3);
  assert(slist_indice(lista, -5) == -1);
  assert(slist_indice(lista, -9) == -1);

  //Test slist_intersecar
  SList lista_interseccion = slist_intersecar(lista, lista2);
  assert(slist_longitud(lista_interseccion) == 4);

  //Test slist_ordenar (selection sort)
  slist_ordenar(lista, orden_natural);
  assert(slist_indice(lista, 0) == 1);

  //Test slist_reverso
  lista = slist_reverso(lista, orden_natural);
  assert(slist_indice(lista, 0) == slist_longitud(lista));

  //Test slist_intercalar
  SList lista_intercalar = slist_intercalar(lista, lista2);
  assert(slist_longitud(lista_intercalar) == (slist_longitud(lista) + slist_longitud(lista2)));

  //Test slist_partir
  SList segunda_lista = slist_partir(lista_intercalar);

  slist_destruir(lista);
  slist_destruir(segunda_lista);
  slist_destruir(lista_intercalar);
  slist_destruir(lista_interseccion);

  return 0;
}
