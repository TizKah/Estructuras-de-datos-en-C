#include <stdio.h>
#include <stdlib.h>
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
  puts("");
  printf("LISTA CONCATENADA: ");
  slist_concatenar(lista, lista2);
  slist_recorrer(lista, imprimir_entero);
  puts("");

  //Test slist_longitud
  printf("Longitud de la lista concatenada: %d", slist_longitud(lista));
  puts("");

  //Test slist_insertar
  puts("");
  printf("LISTA CON ELEMENTO INSERTADO: ");
  slist_insertar(lista, -5, 3);
  slist_recorrer(lista, imprimir_entero);
  puts("");

  //Test slist_eliminar
  printf("LISTA CON ELEMENTO ELIMINADO: ");
  slist_eliminar(&lista,3);
  slist_recorrer(lista, imprimir_entero);
  puts("");

  //Test slist_contiene
  puts("");
  printf("ESTÁ EL 3 EN LA LISTA: %d", slist_contiene(lista,3));
  puts("");
  printf("ESTÁ EL -5 EN LA LISTA: %d", slist_contiene(lista,-5));
  puts("");
  printf("ESTÁ EL -9 EN LA LISTA: %d", slist_contiene(lista,-9));
  puts("");

  //Test slist_indice
  puts("");
  printf("INDICE DEL 3 EN LA LISTA: %d", slist_indice(lista,3));
  puts("");
  printf("INDICE DEL -5 EN LA LISTA: %d", slist_indice(lista,-5));
  puts("");
  printf("INDICE DEL -9 EN LA LISTA: %d", slist_indice(lista,-9));
  puts("");

  //Test slist_intersecar
  puts("");
  printf("INTERSECCIÓN DE LISTA 1 CON LISTA 2: ");
  puts("");
  SList lista_interseccion = slist_intersecar(lista, lista2);
  slist_recorrer(lista_interseccion, imprimir_entero);
  puts("");

  //Test slist_ordenar (selection sort)
  puts("");
  printf("LISTA DESORDENADA: ");
  slist_recorrer(lista, imprimir_entero);
  puts("");
  printf("LISTA ORDENADA: ");
  slist_ordenar(lista,(*orden_natural));
  slist_recorrer(lista, imprimir_entero);
  puts("");

  //Test slist_reverso
  puts("");
  printf("LISTA ORIGINAL: ");
  slist_recorrer(lista, imprimir_entero);
  puts("");
  printf("REVERSO DE LA LISTA: ");
  lista = slist_reverso(lista, *orden_natural);
  slist_recorrer(lista, imprimir_entero);
  puts("");

  //Test slist_intercalar
  puts("");
  printf("LISTA 1: ");
  slist_recorrer(lista, imprimir_entero);
  puts("");
  printf("LISTA 2: ");
  slist_recorrer(lista2, imprimir_entero);
  puts("");
  printf("LISTA INTERCALADA: ");
  SList lista_intercalar = slist_intercalar(lista, lista2);
  slist_recorrer(lista_intercalar, imprimir_entero);
  puts("");
  
  //Test slist_partir
  puts("");
  printf("LISTA: ");
  slist_recorrer(lista, imprimir_entero);
  puts("");
  printf("--LISTA PARTIDA--\n");
  SList segunda_lista = slist_partir(lista);
  printf("PRIMER MITAD: ");
  slist_recorrer(lista, imprimir_entero);
  printf("SEGUNDA MITAD: ");
  slist_recorrer(segunda_lista, imprimir_entero);
  puts("");


  slist_destruir(lista);
  slist_destruir(segunda_lista);
  slist_destruir(lista_intercalar);
  slist_destruir(lista_interseccion);

  return 0;
}
