#include <stdio.h>
#include <stdlib.h>
#include "arr_int.h"

/* 
    No maneja casos donde el arreglo no esté ya lleno. En ese caso
    añadir a la estructura un campo 'int numeroElementos' o hardcodear el
    significado de casilla vacía.
 */

ArregloEnteros* arreglo_enteros_crear(int capacidad){
    ArregloEnteros* arreglo = malloc(sizeof(ArregloEnteros)); 
    arreglo->direccion = calloc(sizeof(int), capacidad);
    arreglo->capacidad = capacidad;
    return arreglo;
}

void arreglo_enteros_destruir(ArregloEnteros* arreglo){
    free(arreglo->direccion);
    free(arreglo);
}

int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos){
    return (arreglo->capacidad > pos ? arreglo->direccion[pos] : -1);
}

void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato){
    if(arreglo->capacidad > pos)
        arreglo->direccion[pos] = dato;
}

int arreglo_enteros_capacidad(ArregloEnteros* arreglo){
    return arreglo->capacidad;
}

void arreglo_enteros_imprimir(ArregloEnteros* arreglo){
    for(int pos = 0; pos < arreglo->capacidad; pos++)
        printf("Elemento %d del arreglo: %d\n", pos, arreglo->direccion[pos]);
}

void arreglo_enteros_ajustar(ArregloEnteros* arreglo, int capacidad, 
                            __attribute__((unused)) int capacidadVieja){
/*     int* arregloViejo = arreglo->direccion;

    arreglo->capacidad = capacidad;
    arreglo->direccion = calloc(sizeof(int), arreglo->capacidad);

    for(int pos = 0; pos < arreglo->capacidad && pos < capacidadVieja; pos++)
        arreglo->direccion[pos] = arregloViejo[pos];
    
    free(arregloViejo); */
    arreglo->direccion = realloc(arreglo->direccion, capacidad * sizeof(int));
    arreglo->capacidad = capacidad;
}

void arreglo_enteros_eliminar(ArregloEnteros* arreglo, int pos){
    if(arreglo->capacidad < pos || pos < 0)
        return;

    arreglo->capacidad -= 1;
    for(int idx = pos; idx < arreglo->capacidad; idx++){
        arreglo->direccion[idx] = arreglo->direccion[idx + 1];
    }
    arreglo_enteros_ajustar(arreglo, arreglo->capacidad, arreglo->capacidad + 1);

}

void arreglo_enteros_insertar(ArregloEnteros* arreglo, int pos, int dato){
    if(arreglo->capacidad < pos || pos < 0)
        return;

    arreglo->capacidad += 1;
    arreglo_enteros_ajustar(arreglo, arreglo->capacidad, arreglo->capacidad - 1);

    for(int idx = arreglo->capacidad - 1; idx > pos; idx--){
        arreglo->direccion[idx] = arreglo->direccion[idx - 1];
    }

    arreglo->direccion[pos] = dato;
}



int main() {
    // Crear un arreglo de enteros con capacidad 5
    ArregloEnteros* arr = arreglo_enteros_crear(5);

    // Escribir datos en el arreglo
    arreglo_enteros_escribir(arr, 0, 10);
    arreglo_enteros_escribir(arr, 1, 20);
    arreglo_enteros_escribir(arr, 2, 30);
    arreglo_enteros_escribir(arr, 3, 40);
    arreglo_enteros_escribir(arr, 4, 50);

    // Imprimir el contenido del arreglo
    printf("Contenido del arreglo:\n");
    arreglo_enteros_imprimir(arr);

    // Leer datos del arreglo
    printf("Dato en la posición 2: %d\n", arreglo_enteros_leer(arr, 2));

    // Insertar un nuevo dato en la posición 2
    arreglo_enteros_insertar(arr, 2, -11);
    printf("Contenido del arreglo después de insertar:\n");
    arreglo_enteros_imprimir(arr);

    // Eliminar el dato en la posición 3
    arreglo_enteros_eliminar(arr, 3);
    printf("Contenido del arreglo después de eliminar la posición 3:\n");
    arreglo_enteros_imprimir(arr);

    // Destruir el arreglo y liberar memoria
    arreglo_enteros_destruir(arr);

    return 0;
}
