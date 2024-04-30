cmake_minimum_required(VERSION 3.0)
project(MiProyecto VERSION 1.0)

# Agrega los archivos fuente a tu proyecto
add_executable(mi_ejecutable
    dictionary.c
    hashtable.c
    word.c
    trie.c
    main.c
)

# Puedes agregar configuraciones específicas aquí si es necesario
