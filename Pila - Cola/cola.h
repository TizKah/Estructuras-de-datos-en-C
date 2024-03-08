#ifndef __COLA.H__
#define __COLA.H__

#include "glist.h"

typedef struct _Cola
{


};

typedef _Cola DList;




Cola cola_crear();

void cola_destruir();

int cola_es_vacia();

void* cola_inicio();

void cola_encolar();

void cola_desencolar();

void cola_imprimir();






#endif