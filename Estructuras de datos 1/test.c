#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 255
#define TAM_MAXIMO 50

char** leerLineas() {
    char buffer[BUFFER_SIZE];
    unsigned int tamanio_max = TAM_MAXIMO;
    char** lineas = malloc(sizeof(char*) * tamanio_max);
    unsigned int numLineas = 0;
    char seguir = 'S';

    while (seguir=='S') {
        // Lee una línea en el buffer estático
        //fgets(buffer, BUFFER_SIZE, stdin);

        scanf("%[^\n]",buffer);
        getchar();

        unsigned int tamanoLinea = strlen(buffer);
        char* nuevaLinea = malloc(tamanoLinea + 1);

        // Copia la línea del buffer a la memoria recién asignada
        strcpy(nuevaLinea, buffer);

        // Añade la nueva línea al array dinámico
        if(numLineas>=tamanio_max){
            tamanio_max*=2;
            lineas = realloc(lineas, tamanio_max * sizeof(char*));
        }
        lineas[numLineas++] = nuevaLinea;
        printf("Palabra: %s",lineas[numLineas-1]);

        printf("Seguir (S/N): ");
        scanf("%c", &seguir);  // Añadí un espacio antes de %c para ignorar cualquier carácter en blanco residual

        // Quitamos el \n que deja el scanf en stdin
        getchar();
    }

    if(numLineas!=tamanio_max){
        lineas = realloc(lineas, numLineas * sizeof(char*));
    }

    return lineas;
}

int main() {
    char** lineas = leerLineas();

    // Haz algo con las líneas almacenadas en el array dinámico

    // Libera la memoria asignada para cada línea y luego para el array dinámico
    for (size_t i = 0; i < sizeof(lineas) / sizeof(lineas[0]); i++) {
        free(lineas[i]);
    }
    free(lineas);

    return 0;
}
