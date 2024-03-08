#ifndef __ARR_INT_H__
#define __ARR_INT_H__

typedef struct {
    int* direccion;
    int capacidad;
} ArregloEnteros;


ArregloEnteros* arreglo_enteros_crear(int capacidad);

void arreglo_enteros_destruir(ArregloEnteros* arreglo);

int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos);

void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato);

int arreglo_enteros_capacidad(ArregloEnteros* arreglo);

void arreglo_enteros_imprimir(ArregloEnteros* arreglo);


/* 
    Ajusta el tamaño del arreglo. 
    Si la nueva capacidad es menor, el contenido es truncado.
 */
void arreglo_enteros_ajustar(ArregloEnteros* arreglo, int capacidad, int capacidadVieja);


/* 
    Inserta el dato en la posición dada, moviendo todos los elementos 
    desde esa posición un lugar a la derecha (incrementa el tamaño del arreglo).
 */
void arreglo_enteros_insertar(ArregloEnteros* arreglo, int pos, int dato);

/* 

    Elimina el dato en la posición dada, moviendo todos los elementos 
    posteriores un lugar a la izquierda (reduce el tamaño del arreglo).
 */
void arreglo_enteros_eliminar(ArregloEnteros* arreglo, int pos);

#endif