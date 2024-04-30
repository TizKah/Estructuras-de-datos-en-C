#ifndef __GLIST_H__
#define __GLIST_H__

typedef void (*FuncionDestructora)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef void (*FuncionVisitante)(void *dato);
typedef int (*Predicado) (void *dato);
typedef int (*FuncionComparadora) (void *dato1, void *dato2);


typedef struct _GNode {
  void *data;
  struct _GNode *next;
  struct _GNode *prev;
} GNode;

typedef GNode *GList;

typedef GList SGList;


/**
 * Devuelve una lista vacía.
 */
GList glist_crear();

/**
 * Destruccion de la lista.
 */
void glist_destruir(GList lista, FuncionDestructora destruir);

/**
 * Determina si la lista es vacía.
 */
int glist_vacia(GList lista);

/**
 * Agrega un elemento al inicio de la lista.
 */
GList glist_agregar_inicio(GList lista, void *dato, FuncionCopia copiar);

GList glist_agregar_final(GList list, void *data, FuncionCopia copy);

void* glist_buscar(GList list, void* dato, FuncionComparadora comp);

void glist_eliminar_dato(GList list, void* dato, FuncionComparadora comp, FuncionDestructora destr);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void glist_recorrer(GList lista, FuncionVisitante visitar);


GList glist_filtrar(GList lista, FuncionCopia c, Predicado p);



// ----------------------
SGList sglist_crear();

void sglist_destruir(SGList lista, FuncionDestructora d);

int sglist_vacia(SGList lista);

void sglist_recorrer(SGList lista, FuncionVisitante visit);

SGList sglist_insertar(SGList lista, void* dato, FuncionCopia c, FuncionComparadora comp);

int sglist_buscar(SGList lista, void *dato, FuncionComparadora comp);

SGList sglist_arr(void **arr, int longitud, FuncionCopia c, FuncionComparadora comp);

#endif /* __GLIST_H__ */
