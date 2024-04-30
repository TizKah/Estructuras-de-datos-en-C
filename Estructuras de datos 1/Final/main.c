#include <stdio.h>
#include <stdlib.h>
#include "pagoda.h"

int main(){
    Pagoda pagoda = crear_pagoda();


    printf("-- PAGODA 1 --\n");
    int dato_mayor_prioridad_pagoda = 45;
    int mayor_prioridad_pagoda = 940;
    pagoda = insert_pagoda(pagoda, 14, 140);
    pagoda = insert_pagoda(pagoda, 15, 56);
    pagoda = insert_pagoda(pagoda, 10, 10);
    pagoda = insert_pagoda(pagoda, dato_mayor_prioridad_pagoda, mayor_prioridad_pagoda);
    pagoda = insert_pagoda(pagoda, 100, 100);
    pagoda = insert_pagoda(pagoda, 843, 1);

    printf("Prioridad mayor en pagoda 1: %d\nElemento de mayor prioridad en pagoda 1: %d\n\n", 
            dato_mayor_prioridad_pagoda, mayor_prioridad_pagoda);
    printf("Elemento de mayor prioridad en pagoda 1 con top_pagoda: %d\n\n", top_pagoda(pagoda));


    printf("Eliminado el elemento de mayor prioridad\n");
    pagoda = pop_pagoda(pagoda);
    printf("Nuevo elemento de mayor prioridad: %d\n\n", top_pagoda(pagoda));

    printf("-- PAGODA 2 --\n");
    Pagoda pagoda2 = crear_pagoda();
    int dato_mayor_prioridad_pagoda2 = 111;
    int mayor_prioridad_pagoda2 = 2695;
    pagoda2 = insert_pagoda(pagoda2, 15, 960);
    pagoda2 = insert_pagoda(pagoda2, 24, 12);
    pagoda2 = insert_pagoda(pagoda2, dato_mayor_prioridad_pagoda2, mayor_prioridad_pagoda2);
    pagoda2 = insert_pagoda(pagoda2, 144, 14);
    pagoda2 = insert_pagoda(pagoda2, 84, 19);
    pagoda2 = insert_pagoda(pagoda2, 49, 94);

    printf("Prioridad mayor en pagoda 2: %d\nElemento de mayor prioridad en pagoda 2: %d\n\n", 
            dato_mayor_prioridad_pagoda2, mayor_prioridad_pagoda2);
    printf("Elemento de mayor prioridad en pagoda 2 con top_pagoda: %d\n\n", top_pagoda(pagoda2));

    printf("-- UNION --\n");
    pagoda = union_pagoda(pagoda, pagoda2);
    printf("Elemento de mayor prioridad de la union con top_pagoda: %d\n\n", top_pagoda(pagoda));

    destruir_pagoda(pagoda);

    return 0;
}