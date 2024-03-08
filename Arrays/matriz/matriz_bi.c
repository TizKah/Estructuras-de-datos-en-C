#include "matriz.h"

/*
** Implementacion utilizando un arreglo bidimensional (arreglo de punteros a arreglo)
*/

struct Matriz_ {
  float** direccion;
  size_t numFilas;
  size_t numColumnas;
};


Matriz* matriz_crear(size_t numFilas, size_t numColumnas) {
  Matriz* matriz = malloc(sizeof(Matriz));

  matriz->numFilas = numFilas;
  matriz->numColumnas = numColumnas;
  matriz->direccion = malloc(sizeof(float) * numFilas);

  for(int pos = 0; pos < numFilas; pos++)
    matriz->direccion[pos] = malloc(sizeof(float) * numColumnas);

  return matriz;
}

void matriz_destruir(Matriz* matriz) {
  for(int pos = 0; pos < matriz->numFilas; pos++)
    free(matriz->direccion[pos]);
  free(matriz->direccion);
}

double matriz_leer(Matriz* matriz, size_t fil, size_t col) {
  return matriz->direccion[fil][col];
}

void matriz_escribir(Matriz* matriz, size_t fil, size_t col, double val) {
  matriz->direccion[fil][col] = val;
}

size_t matriz_num_filas(Matriz* matriz) {
  return matriz->numFilas;
}

size_t matriz_num_columnas(Matriz* matriz) {
  return matriz->numColumnas;
}


