#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"



int* int_copy(void* numP){
    int* ptr = malloc(sizeof(int));
    *ptr = *(int*) numP;
    return ptr;
}

int int_comp(void* n1, void* n2){
    return (*(int*)n1 - *(int*)n2);
}

void int_destroy(void* n){
    free(n);
}

void int_visit(void* n){
    printf("%d",*(int*)n);
}


int main(int argc, char *argv[]){
    DList lista = DList_crear((FuncionComparadora)int_comp, (FuncionCopiadora)int_copy, 
    (FuncionDestructora)int_destroy, (FuncionVisitante)int_visit);
    
    DList lista1 = DList_crear((FuncionComparadora)int_comp, (FuncionCopiadora)int_copy, 
    (FuncionDestructora)int_destroy, (FuncionVisitante)int_visit);

    if (lista == NULL) {
        fprintf(stderr, "Error al crear la lista\n");
        return 1;
    }

    int *arg1 = malloc(sizeof(int));
    *arg1 = atoi(argv[1]);

    int *arg2 = malloc(sizeof(int));
    *arg2 = atoi(argv[2]);

    int *arg3 = malloc(sizeof(int));
    *arg3 = atoi(argv[3]);

    int *arg4 = malloc(sizeof(int));
    *arg4 = atoi(argv[4]);

    lista = DList_agregar_final(lista,arg1);
    DList_recorrer(lista);
    puts("");
    lista = DList_agregar_final(lista,arg2);
    DList_recorrer(lista);
    puts("");

    lista = DList_agregar_inicio(lista,arg3);
    DList_recorrer(lista);
    puts("");
    lista = DList_agregar_inicio(lista,arg4);
    DList_recorrer(lista);
    puts("");
    puts("");

    printf("Longitud de la lista: %d",DList_longitud(lista));
    puts("");

    lista1 = DList_agregar_final(lista1,arg3);
    DList_recorrer(lista1);
    puts("");
    lista1 = DList_agregar_final(lista1,arg2);
    DList_recorrer(lista1);
    puts("");

    lista1 = DList_agregar_inicio(lista1,arg1);
    DList_recorrer(lista1);
    puts("");
    lista1 = DList_agregar_inicio(lista1,arg4);
    DList_recorrer(lista1);
    puts("");
    puts("");

    DList_concatenar(lista,lista1);
    DList_recorrer(lista);
    puts("");


    free(arg1);
    free(arg2);
    free(arg3);
    free(arg4);
    
    DList_destruir(lista);

}