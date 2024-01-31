#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef struct _DNodo
{
    int dato;
    struct _DNodo* sig;
    struct _DNodo* ant;
} DNodo;

typedef struct
{
    DNodo *primero;
    DNodo *ultimo;
} DList;


DList dlist_crear();





#endif