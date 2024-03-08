#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include "array_float.h"

void bubble_sort(float arreglo[], int longitud) {
    for (int iter = 0; iter < longitud - 1; iter++)
    {
        for (int i = 0; i < longitud - iter - 1; i++)
        {
            if (arreglo[i] > arreglo[i + 1])
            {
                float aux = arreglo[i];
                arreglo[i] = arreglo[i + 1];
                arreglo[i + 1] = aux;
            }
        }
    }
}

float mediana(float *arreglo, int longitud){
    if(longitud==1)
        return arreglo[0];
    if(longitud==2)
        return ((float) (arreglo[0] + arreglo[1]) / 2.0);

    // Creo una copia del arreglo original para no modificarlo al hacer el ordenamiento.
    float* copia_arreglo = malloc(sizeof(float) * longitud);

    // Coppio el array original
    memcpy(copia_arreglo,arreglo,longitud);

    bubble_sort(copia_arreglo,longitud);

    unsigned int mitad = floor(longitud/2);
    float mediana;
    if(longitud % 2 == 0)
        mediana = (float) (arreglo[mitad-1] + arreglo[mitad]) / 2.0;
    else
        mediana = (float) arreglo[mitad];

    free(copia_arreglo);

    return mediana;
}

int main(){
    float array[] = {-1.0, 2.2, 2.9, 3.1, 3.5};
    printf("Mediana: %.2f\n", mediana(array,5));
    


    int max_tamanio = 10;
    float *array_dinamico = malloc(sizeof(float) * max_tamanio); 
    int idx = 0;

    printf("Ingrese valores para el arreglo separados por espacios y presione Enter:\n");
    //while (scanf("%f", &array_dinamico[idx++]) == 1); // Terminado con Crtl + D

    char buffer[255];
    fgets(buffer, sizeof(buffer),stdin);
    char* token = strtok(buffer, " \n");
    while (token!=NULL) {
        //array_dinamico[idx++] = atof(token);
        sscanf(token, "%f", &array_dinamico[idx++]);
        token = strtok(NULL, " \n");
    }
    
    printf("Mediana: %.2f\n", mediana(array_dinamico,idx));

    free(array_dinamico);
}