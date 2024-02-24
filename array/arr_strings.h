#ifndef __ARR_STRINGS_H__
#define __ARR_STRINGS_H__

typedef char* String;


/* 
    Devuelve la longitud de la cadena str.
 */
int string_len(String str);

/* 
    Invierte la cadena str.
 */
void string_reverse(String str);

/* 
    Concatena no más de max caracteres de la cadena str2 al final de la cadena str1. 
    Retorna el número de caracteres copiados.
 */
int string_concat(String str1, String str2, int max);

/* 
    Compara en orden lexicográfico las cadenas str1 y str2, 
    y retorna -1 si la primera es menor que la segunda, 
    0 si son iguales, y 1 si es mayor.
 */
int string_compare(String str1, String str2);

/* 
    Retorna el índice de la primera ocurrencia de la cadena str2 
    en la cadena str1. En caso de no ocurrir nunca, retorna −1.
 */
int string_subcadena(String str1, String str2);

/* 
    Concatena las n cadenas del arreglo arregloStrings, 
    separándolas por la cadena sep y almacenando el resultado en res.
 */
void string_unir(String arregloStrings[], int n, String sep, String res);

#endif