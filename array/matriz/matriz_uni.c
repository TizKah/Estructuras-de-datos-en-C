#include "matriz.h"

/*
** Implmentacion utilizando un unico arreglo unidimensional
*/

struct Matriz_ {
  size_t numFilas;
  size_t numColumnas;
  float* direccion;
};


Matriz* matriz_crear(size_t numFilas, size_t numColumnas) {
  Matriz* matriz = malloc(sizeof(Matriz));
  matriz->numFilas = numFilas;
  matriz->numColumnas = numColumnas;
  matriz->direccion = calloc(numFilas * numColumnas, sizeof(float));
  return matriz;
}

void matriz_destruir(Matriz* matriz) {
  free(matriz->direccion);
  free(matriz);
}

double matriz_leer(Matriz* matriz, size_t fil, size_t col) {
  return matriz->direccion[matriz->numColumnas * fil + col];
}

void matriz_escribir(Matriz* matriz, size_t fil, size_t col, double val) {
  matriz->direccion[fil * matriz->numColumnas, col] = val;
}

size_t matriz_num_filas(Matriz* matriz) {
  return matriz->numFilas;
}

size_t matriz_num_columnas(Matriz* matriz) {
  return matriz->numColumnas;
}



