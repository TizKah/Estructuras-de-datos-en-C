#include "btree.h"
#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLA 1000

typedef struct {
  BTree elementos[MAX_COLA];
  int frente, final;
} Cola;


Cola* crear_cola() {
  Cola* nueva_cola = (Cola*)malloc(sizeof(Cola));
  nueva_cola->frente = nueva_cola->final = -1;
  return nueva_cola;
}

bool cola_vacia(Cola* cola) {
  return cola->frente == -1;
}

void encolar(Cola* cola, BTree elemento) {
  if (cola->frente == -1) {
    cola->frente = cola->final = 0;
  } else {
    cola->final = (cola->final + 1) % MAX_COLA;
  }
  cola->elementos[cola->final] = elemento;
}

BTree desencolar(Cola* cola) {
  BTree elemento = cola->elementos[cola->frente];
  if (cola->frente == cola->final) {
    cola->frente = cola->final = -1;
  } else {
    cola->frente = (cola->frente + 1) % MAX_COLA;
  }
  return elemento;
}