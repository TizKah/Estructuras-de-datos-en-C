#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef int (*FuncionComparadora)(void *, void *);
typedef void (*FuncionDestructora)(void *dato);
typedef void (*FuncionVisitante)(void *dato);
typedef void *(*FuncionCopiadora)(void *dato);
typedef void *(*FuncionSwap)(BHeap heap, void* dato, void* dato1);

typedef struct _BHeap {
    void* *arr;
    int capacidad;
    int ultimo;
    FuncionComparadora comp;
} _BHeap;

typedef _BHeap *BHeap;



BHeap bheap_crear(FuncionComparadora comp, int capacidad, int tamBytes){
    BHeap heap = malloc(sizeof(BHeap));
    heap->arr = malloc(sizeof(capacidad * tamBytes));
    heap->capacidad = capacidad;
    heap->ultimo = 0;
    heap->comp = comp;
    return heap;
}

void bheap_destruir(BHeap heap, FuncionDestructora destroy){
    for(int i=0; i< heap->ultimo; i++)
        destroy(heap->arr[i]);
    
    free(heap->arr);
    free(heap);
}

int bheap_es_vacio(BHeap heap){
    return (heap->ultimo == 0);
}

void bheap_recorrer(BHeap heap, FuncionVisitante visit){
    for(int i=0; i<heap->ultimo; i++)
        visit(heap->arr[i]);
}

BHeap bheap_insertar(BHeap heap, void* elemento, FuncionCopiadora copy){
    int ultimo = heap->ultimo;
    int capacidad = heap->capacidad;
    if(ultimo==capacidad){
        heap->arr = realloc(heap->arr, 2*capacidad*type(heap->arr[1]));
        heap->capacidad = capacidad*2;
    }

    heap->arr[++ultimo] = copy(elemento);
    // El elemento debe trepar. Es decir, debemos compararlo con el nodo padre hasta que deje de ser mayor.
    for(int pos_elemento = ultimo; pos_elemento>1 && heap->arr[pos_elemento/2]<=heap->arr[pos_elemento]; pos_elemento/=2){
        void *temp = heap->arr[pos_elemento];
        heap->arr[pos_elemento] = heap->arr[pos_elemento/2];
        heap->arr[pos_elemento] = copy(temp);
    }

    return heap;
}

BHeap bheap_eliminar(BHeap heap, void *dato, FuncionCopiadora copy, FuncionComparadora comp){
    BHeap nuevo_heap = malloc(sizeof(BHeap));

    for(int i = 0; i<heap->ultimo; i++){
        if(!comp(heap->arr[i], dato) == 0)
            bheap_insertar(nuevo_heap, dato, copy);
    }    

    return nuevo_heap;  
}


void* bheap_eliminar_tope(BHeap heap, void *dato, FuncionCopiadora copy, FuncionComparadora comp){
    void *tope = heap->arr[1];
    heap->arr[1] = heap->arr[heap->ultimo];
    heap->ultimo--;

    int esMayor = 1;
    for(int pos=1; pos*2 < heap->ultimo && esMayor;){
        //Ver qué hijo es el mayor:
        int k = pos*2;
        if(k+1<=heap->ultimo && heap->arr[k]<heap->arr[k+1])
            k++; //El hijo derecho es el mayor
        
        if(heap->arr[k]>heap->arr[k*2])
            esMayor = 0;
        else
        {
            void *temp = heap->arr[pos];
            heap->arr[pos] = heap->arr[k];
            heap->arr[pos] = copy(temp);
            pos=k;
        }

    }

    return tope;
}

BHeap bheap_crear_desde_arr(void**arr, int largo, FuncionCopiadora copiar, FuncionComparadora comp){
    BHeap heap = malloc(sizeof(BHeap));
    heap->capacidad = largo;
    heap->comp = comp;
    

    

}




