# Estructuras de Datos en C

Implementaciones de estructuras de datos vistas en la universidad.

## Estructuras de Datos Implementadas

#### - Arrays
#### - Pila
#### - Cola
#### - Listas:
  - Simplementa enlazada
  - Doblemente enlazada
  - Doblemente enlazada circular
#### - Árboles:
  - Binarios:
      - De búsqueda
      - De búsqueda balanceado (AVL)
  - Generales
  - Cola de prioridad (heap)
#### - Tabla hash


## Características

### - Arrays

#### Descripción
Un array es una estructura de datos que almacena elementos del mismo tipo en posiciones contiguas de memoria. Permite un acceso rápido a los elementos mediante índices.

#### Ventajas
- Acceso rápido mediante índices.
- Implementación simple y eficiente para almacenar datos homogéneos.

#### Desventajas
- Tamaño fijo al ser creado.
- Ineficiente para insertar o eliminar elementos en posiciones intermedias.

#### Análisis de Complejidad Asintótica
- Acceso: O(1)
- Inserción/eliminación en posición intermedia: O(n)

### - Pila

#### Descripción
Una pila es una estructura de datos LIFO (Last In, First Out) que sigue el principio de apilar y desapilar elementos.

#### Ventajas
- Operaciones de apilado y desapilado eficientes.
- Estructura simple y fácil de entender.

#### Desventajas
- Acceso directo limitado a elementos fuera de la cima de la pila.

#### Análisis de Complejidad Asintótica
- Apilado/desapilado: O(1)

### - Cola

#### Descripción
Una cola es una estructura de datos FIFO (First In, First Out) que sigue el principio de encolar y desencolar elementos.

#### Ventajas
- Operaciones de encolado y desencolado eficientes.
- Utilizada en situaciones que siguen el orden de llegada.

#### Desventajas
- Acceso directo limitado a elementos fuera del frente de la cola.

#### Análisis de Complejidad Asintótica
- Encolado/desencolado: O(1)

### - Cola de prioridad (heap)

#### Descripción
Una cola de prioridad es una estructura de datos donde cada elemento tiene asignada una prioridad y los elementos se desencolan de acuerdo con su prioridad.

#### Ventajas
- Eficiente para manejar elementos con prioridades.
- Utilizada en algoritmos como Dijkstra y Huffman.

#### Desventajas
- Ineficiente para cambiar la prioridad de un elemento.

#### Análisis de Complejidad Asintótica
- Encolado: O(log n)
- Desencolado: O(1)

### - Árboles binarios

#### Descripción
Un árbol binario es una estructura de datos jerárquica donde cada nodo tiene a lo sumo dos hijos.

#### Ventajas
- Búsqueda, inserción y eliminación eficientes.
- Utilizado en algoritmos de búsqueda y recorridos.

#### Desventajas
- Puede degenerar en una lista enlazada si no está balanceado.

#### Análisis de Complejidad Asintótica
- Búsqueda, inserción y eliminación: O(log n) en el caso promedio (para árboles balanceados).

### - Árboles generales

#### Descripción
Un árbol general es una estructura de datos jerárquica donde cada nodo puede tener cualquier número de hijos.

#### Ventajas
- Modela relaciones de tipo uno a muchos.
- Utilizado en estructuras jerárquicas como el árbol de archivos de un sistema operativo.

#### Desventajas
- Operaciones pueden ser más complejas que en un árbol binario.

#### Análisis de Complejidad Asintótica
- Búsqueda, inserción y eliminación: O(n) en el peor caso.

...

### - Árboles binarios de búsqueda

#### Descripción
Un árbol binario de búsqueda es un árbol binario en el que para cada nodo, sus nodos a la izquierda son menores y los nodos a la derecha son mayores.

#### Ventajas
- Búsqueda, inserción y eliminación eficientes.
- Mantienen los elementos ordenados.

#### Desventajas
- Puede degenerar en una lista enlazada si no está balanceado.

#### Análisis de Complejidad Asintótica
- Búsqueda, inserción y eliminación: O(log n) en el caso promedio (para árboles balanceados). Pues, por ejemplo, una lista simplementa enlazada podría ser un árbol binario pero la búsqueda es del orden O(n).

### - Árboles binarios de búsqueda balanceado (AVL)

#### Descripción
Un árbol AVL es un árbol binario de búsqueda que se mantiene balanceado, asegurando que la altura de los subárboles izquierdo y derecho difiera como máximo en 1.

#### Ventajas
- Búsqueda, inserción y eliminación eficientes.
- Garantiza un tiempo de búsqueda balanceado.

#### Desventajas
- Mayor complejidad en comparación con un árbol binario de búsqueda no balanceado.

#### Análisis de Complejidad Asintótica
- Búsqueda, inserción y eliminación: O(log n)

### - Tabla hash

#### Descripción
Una tabla hash es una estructura de datos que asocia claves con valores. Utiliza una función hash para mapear claves a índices en la tabla.

#### Ventajas
- Búsqueda eficiente mediante claves.
- Buena distribución de datos cuando se utiliza una buena función hash.

#### Desventajas
- Posible colisión de hash.
- Necesidad de manejar colisiones de manera adecuada.

#### Análisis de Complejidad Asintótica
- Búsqueda, inserción y eliminación promedio: O(1) en el caso promedio, O(n) en el peor caso (colisiones).


### - Lista Simplemente Enlazada

#### Descripción
Una lista simplemente enlazada es una estructura de datos donde cada elemento, llamado nodo, contiene un dato y un enlace al siguiente nodo.

#### Ventajas
- Inserción y eliminación eficientes en cualquier posición.
- Uso eficiente de memoria.

#### Desventajas
- Acceso secuencial, no acceso directo a un índice específico.

#### Análisis de Complejidad Asintótica
- Búsqueda: O(n)
- Inserción/eliminación: O(1) para operaciones al principio o al final, O(n) en el caso promedio para otras posiciones.

### - Lista Doblemente Enlazada

#### Descripción
Una lista doblemente enlazada es similar a una lista simplemente enlazada, pero cada nodo contiene un enlace al nodo anterior y al siguiente.

#### Ventajas
- Inserción y eliminación eficientes en cualquier posición.
- Permite recorridos en ambas direcciones.

#### Desventajas
- Uso de memoria ligeramente mayor que una lista simplemente enlazada.

#### Análisis de Complejidad Asintótica
- Búsqueda: O(n)
- Inserción/eliminación: O(1) para operaciones al principio o al final, O(n) en el caso promedio para otras posiciones.

### - Lista Doblemente Enlazada Circular

#### Descripción
Una lista doblemente enlazada circular es similar a una lista doblemente enlazada, pero el último nodo apunta al primero, cerrando el círculo.

#### Ventajas
- Permite recorridos continuos desde cualquier nodo.
- Inserción y eliminación eficientes en cualquier posición.

#### Desventajas
- Uso de memoria ligeramente mayor que una lista doblemente enlazada.

#### Análisis de Complejidad Asintótica
- Búsqueda: O(n)
- Inserción/eliminación: O(1) para operaciones al principio o al final, O(n) en el caso promedio para otras posiciones.
