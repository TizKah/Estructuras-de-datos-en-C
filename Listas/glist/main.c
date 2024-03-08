#include "contacto.h"
#include "glist.h"
#include <stdio.h>
#include <stdlib.h>

int mayor_a_60(void *pContacto){
  Contacto *persona = (Contacto*) (pContacto);
  int edad = persona->edad;
  return (edad>60);
}

int contacto_comparar_edad(Contacto *c1, Contacto *c2) {
  return (c1->edad>c2->edad);
}

int main() {

  GList lista = glist_crear();
  Contacto *contactos[6];
  contactos[0] = contacto_crear("Pepe Argento", "3412695452", 61);
  contactos[1] = contacto_crear("Moni Argento", "3412684759", 60);
  contactos[2] = contacto_crear("Coqui Argento", "3415694286", 32);
  contactos[3] = contacto_crear("Paola Argento", "3416259862", 29);
  contactos[4] = contacto_crear("Maria Elena Fuseneco", "3416874594", 59);
  contactos[5] = contacto_crear("Dardo Fuseneco", "3416894526", 64);

  for (int i = 0; i < 6; ++i) {
    lista =
        sglist_insertar(lista, contactos[i], (FuncionCopia)contacto_copia, (FuncionComparadora)contacto_comparar_edad);
    contacto_destruir(contactos[i]);
  }

  printf("Lista:\n");
  sglist_recorrer(lista, (FuncionVisitante)contacto_imprimir);


  printf("\nFiltrar mayores a 60:\n");
  lista = glist_filtrar(lista,(FuncionCopia)contacto_copia,(Predicado)mayor_a_60);
  glist_recorrer(lista, (FuncionVisitante)contacto_imprimir);

  glist_destruir(lista, (FuncionDestructora)contacto_destruir);

  return 0;
}