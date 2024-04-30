#include <stdlib.h>

typedef struct _Pagoda
{
    int dato;
    unsigned int prioridad;
    struct _Pagoda *der, *izq;
    struct _Pagoda *G, *D;
} _Pagoda;

typedef _Pagoda *Pagoda;

Pagoda crear_pagoda();

Pagoda inicializar_nodo_pagoda_con_valores(int valor, unsigned int prioridad);

Pagoda union_pagoda(Pagoda p1, Pagoda p2);

Pagoda insert_pagoda(Pagoda p, int valor, unsigned int prioridad);

int top_pagoda(Pagoda p);

Pagoda pop_pagoda(Pagoda p);

void destruir_pagoda(Pagoda p);
