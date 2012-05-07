/*
 * Programa:    prog_03_02
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 3:
 *              Programa que imprime el número de bytes que ocuapn los tipos 
 *              básicos de C
 */

#include <stdio.h>

int main(void)
{
    printf("Un char ocupa %d bytes\n", sizeof(char));
    printf("Un signed char ocupa %d bytes\n", sizeof(signed char));
    printf("Un unsigned char ocupa %d bytes\n", sizeof(unsigned char));
    printf("Un int ocupa %d bytes\n", sizeof(int));
    printf("Un signed int ocupa %d bytes \n", sizeof(signed int));
    printf("Un unsigned int ocupa %d bytes \n", sizeof(unsigned int));
    printf("Un short ocupa %d bytes \n", sizeof(short));
    printf("Un signed short ocupa %d bytes\n", sizeof(signed short));
    printf("Un unsigned short ocupa %d bytes\n", sizeof(unsigned short));
    printf("Un long ocupa %d bytes\n", sizeof(long));
    printf("Un signed long ocupa %d bytes\n", sizeof(signed long));
    printf("Un unsigned long ocupa %d bytes\n", sizeof(unsigned long));
    printf("Un long long ocupa %d bytes\n", sizeof(long long));
    printf("Un signed long long ocupa %d bytes\n", sizeof(signed long long));
    printf("Un unsigned long long ocupa %d bytes\n", sizeof(unsigned long long));
    printf("Un float ocupa %d bytes\n", sizeof(float));
    printf("Un double ocupa %d bytes\n", sizeof(double));
    printf("Un long double ocupa %d bytes\n", sizeof(long double));

    return(0);
}

