#include "arr_strings.h"
#include <stdlib.h>
#include <stdio.h>

static void swap_char(char* char1, char* char2){
    char temp = *char1;
    *char1 = *char2;
    *char2 = temp;
}

int string_len(String str) {
    int longitud;
    for(longitud = 0; str[longitud]!='\0'; longitud++);
    return longitud;
}

void string_reverse(String str) {
    int longitud = string_len(str) - 1;

    for(int pos = 0; pos <= longitud; pos++,longitud--)
        swap_char(&str[pos], &str[longitud]);

}

int string_concat(String str1, String str2, int max) {
    int longitudStr2 = string_len(str2);
    int caracteresConcatenados = (longitudStr2 >= max ? max : max - longitudStr2);

    int longitudStr1 = string_len(str1);

    int posStr1, posStr2;
    for(posStr1 = longitudStr1, posStr2 = 0; posStr1 < longitudStr1 + caracteresConcatenados;)
        str1[posStr1++] = str2[posStr2++];
    
    str1[posStr1] = '\0';
    return caracteresConcatenados;
}

int string_compare(String str1, String str2) {
    int comp = 0;
    for(int pos = 0; str1[pos] != '\0' && str2[pos] != '\0' && comp == 0; pos++){
        if(str1[pos] < str2[pos])
            comp = -1;
        else if (str1[pos] > str2[pos])
            comp = 1;
    }

    return comp;
}

static int string_subcadena_desde_indice(String str1, String str2, int posStr1){
    int posStr2 = 0;
    if(str1[posStr1] != str2[posStr2])
        return 0;

    int sonIguales = 1;
    for(; str2[posStr2] != '\0' && str1[posStr1 + posStr2] != '\0' && sonIguales; posStr2++){
        if(str2[posStr2] != str1[posStr1 + posStr2])
            sonIguales = 0;
    }

    if(str2[posStr2] != '\0')
        sonIguales = 0;

    return sonIguales;
}

int string_subcadena(String str1, String str2) {
    int indicePrimerOcurrencia = -1;
    for(int posStr1 = 0; str1[posStr1]!='\0' && indicePrimerOcurrencia == -1; posStr1++){
        if(string_subcadena_desde_indice(str1, str2, posStr1))
            indicePrimerOcurrencia = posStr1;
    }

    return indicePrimerOcurrencia;
}

static void string_insertar(String dest, String src, int* idxDest){
    int pos;
    for(pos = 0; src[pos] != '\0'; pos++)
        dest[*idxDest + pos] = src[pos];
    *idxDest+=pos;
}

void string_unir(String arregloStrings[], int cantidadCadenas, String separador, String resultado) {
    if(cantidadCadenas == 0)
        return;

    int* idxResultado, mem = 0;
    idxResultado = &mem;

    for(int pos = 0; pos < cantidadCadenas; pos++){
        string_insertar(resultado, arregloStrings[pos],idxResultado);
        if(pos != cantidadCadenas - 1)
            string_insertar(resultado, separador, idxResultado);
    }
    resultado[*idxResultado] = '\0';
}


int main(){
    char name[30] = "Roberto de las Fl0res\0";
    char name1[] = "Flores\0";
    //String name = malloc(sizeof(char) * 22);
    //strcpy(name, "Roberto de las Flores");
    
    printf("-- REVERSO --\n");
    printf("Nombre sin cambios: %s\n", name);
    string_reverse(name);
    printf("Nombre reverso: %s\n\n", name);

    string_reverse(name);
    printf("-- CONCATENAR --\n");
    printf("Str inicial: %s\n",name);    
    int caracteresConcatenados = string_concat(name, name1, 6);
    printf("Str concatenado: %s\n", name);
    printf("Caráctares concatenados: %d\n\n", caracteresConcatenados);

    printf("-- COMPARE --");
    printf("Comparación entre: \n%s \n%s \n-> %d\n\n", name, name1, string_compare(name, name1));


    printf("-- OCURRENCIA --\n");
    printf("índice de la primer ocurrencia de \n'%s' en \n'%s'\n -> %d\n\n", name1, name, string_subcadena(name,name1));


    printf("-- UNIR CON SEPARADOR --\n");
    String strings[] = {"Hola", "Mundo", "C", "Programacion"};
    String separador = ", ";
    int cantidadCadenas = sizeof(strings) / sizeof(strings[0]);
    char resultado[255];
    string_unir(strings, cantidadCadenas, separador, resultado);
    printf("Resultado: %s\n", resultado);

    return 0;
}
