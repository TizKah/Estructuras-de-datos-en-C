  #include <assert.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include "tablahash.h"
  /* #include "../../glist/glist/glist.h" */
  #include "glist.h"

  /**
  * Estructura principal que representa la tabla hash.
  */
  struct _TablaHash {
    GList *elems;
    unsigned numElems;
    unsigned capacidad;
    FuncionCopiadora copia;
    FuncionComparadora comp;
    FuncionDestructora destr;
    FuncionHash hash;
  };

  /**
  * Crea una nueva tabla hash vacia, con la capacidad dada.
  */
  TablaHash tablahash_crear(unsigned capacidad, FuncionCopiadora copia,
                            FuncionComparadora comp, FuncionDestructora destr,
                            FuncionHash hash) {

    // Pedimos memoria para la estructura principal y las casillas.
    TablaHash tabla = malloc(sizeof(struct _TablaHash));
    assert(tabla != NULL);
    tabla->elems = malloc(sizeof(GList) * capacidad);
    assert(tabla->elems != NULL);
    tabla->numElems = 0;
    tabla->capacidad = capacidad;
    tabla->copia = copia;
    tabla->comp = comp;
    tabla->destr = destr;
    tabla->hash = hash;

    // Inicializamos las casillas con datos nulos.
    for (unsigned idx = 0; idx < capacidad; ++idx) {
      tabla->elems[idx] = glist_crear();
    }

    return tabla;
  }


  void tablahash_resize(TablaHash tabla){
    unsigned int nueva_capacidad = tabla->capacidad*2;
    // Creamos una var auxiliar para guardar el array de elementos
    GList *old_array = tabla->elems;

    // 'Reseteamos' el array de elementos, con el doble de capacidad anterior
    tabla->capacidad = nueva_capacidad;
    tabla->numElems = 0;
    tabla->elems = malloc(sizeof(GList) * tabla->capacidad);

    // Inicializamos el nuevo arreglo de elementos de la tabla hash
    for(unsigned idx = 0; idx < tabla->capacidad; idx++){
      tabla->elems[idx] = glist_crear();
    }

    // Insertamos nuevamente sus elementos iniciales en el nuevo almacenamiento de la tabla hash
    for(unsigned int idx = 0; idx < nueva_capacidad/2; idx++){
      GNode *nodo_a_insertar = old_array[idx];
      while(nodo_a_insertar && nodo_a_insertar->data){
        tablahash_insertar(tabla, nodo_a_insertar->data);
        nodo_a_insertar = nodo_a_insertar->next;
      }
      glist_destruir(old_array[idx],tabla->destr);
    }

    // Liberamos la memoria del arreglo inicial
    free(old_array);
  }

  /**
  * Retorna el numero de elementos de la tabla.
  */
  int tablahash_nelems(TablaHash tabla) { return tabla->numElems; }

  /**
  * Retorna la capacidad de la tabla.
  */
  int tablahash_capacidad(TablaHash tabla) { return tabla->capacidad; }

  /**
  * Destruye la tabla.
  */
  void tablahash_destruir(TablaHash tabla) {

    // Destruir cada uno de los datos.
    for (unsigned idx = 0; idx < tabla->capacidad; ++idx)
      if (tabla->elems[idx]->data)
        glist_destruir(tabla->elems[idx],tabla->destr);

    // Liberar el arreglo de casillas y la tabla.
    free(tabla->elems);
    free(tabla);
  }


  /* 
    Maneja el caso de que se haya encontrado una colisión al momento de insertar un dato.
  */
  GList colision_manage(TablaHash tabla, int idx, void *dato){  
    // Tendremos que buscar la primer casilla libre a la que acudir para insertar el dato.
    // Es decir:
    // Que el dato sea ==NULL
    // Que el dato haya sido eliminado
    // Que hayamos encontrado un dato igual al que ingresar
    return glist_agregar_inicio(tabla->elems[idx],dato,tabla->copia);
  }

  /**
  * Inserta un dato en la tabla, o lo reemplaza si ya se encontraba.
  */
  void tablahash_insertar(TablaHash tabla, void *dato) {

    // En caso que la tabla haya pasado el factor de carga óptimo
    if((float)tabla->numElems / (float)tabla->capacidad > FACTOR_CARGA_MAX)
      tablahash_resize(tabla);

    // Calculamos la posicion del dato dado, de acuerdo a la funcion hash.
    unsigned idx = tabla->hash(dato) % tabla->capacidad;

    // Insertar el dato si la casilla estaba libre.
    if (!tabla->elems[idx]->data) {
      tabla->numElems++;
      tabla->elems[idx]->data = tabla->copia(dato);
    }
    // Sobrescribir el dato si el mismo ya se encontraba en la tabla.
    else if (tabla->comp(tabla->elems[idx]->data, dato) == 0) {
      tabla->destr(tabla->elems[idx]->data);
      tabla->elems[idx]->data = tabla->copia(dato);
    }
    // En caso de haber colisiones, haremos el linear probing
    else {
      tabla->numElems++;
      tabla->elems[idx] = colision_manage(tabla,idx, dato);
    }
  }

  /**
  * Retorna el dato de la tabla que coincida con el dato dado, o NULL si el dato
  * buscado no se encuentra en la tabla.
  */
  void *tablahash_buscar(TablaHash tabla, void *dato) {

    // Calculamos la posicion del dato dado, de acuerdo a la funcion hash.
    unsigned idx = tabla->hash(dato) % tabla->capacidad;

    // Retornar NULL si la casilla estaba vacia.
    if (!tabla->elems[idx]->data)
      return NULL;
    
    // Retornar el dato de la casilla si hay concidencia.
    if (tabla->comp(tabla->elems[idx]->data, dato) == 0)
      return tabla->elems[idx]->data;
    
    return glist_buscar(tabla->elems[idx],dato,tabla->comp);
  }


  /* 
    Función auxiliar para eliminar el dato de una casilla
  */
  void delete_data(TablaHash tabla, int idx){
    tabla->numElems--;
    tabla->destr(tabla->elems[idx]->data);
    tabla->elems[idx]->data = NULL;
  }

  /**
  * Elimina el dato de la tabla que coincida con el dato dado.
  */
  void tablahash_eliminar(TablaHash tabla, void *dato) {

    // Calculamos la posicion del dato dado, de acuerdo a la funcion hash.
    unsigned idx = tabla->hash(dato) % tabla->capacidad;

    // Retornar si la casilla estaba vacia.
    if(!tabla->elems[idx] || !tabla->elems[idx]->data)
      return;
    
    tabla->elems[idx] = glist_eliminar_dato(tabla->elems[idx],dato,tabla->comp,tabla->destr);
}


