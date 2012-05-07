/* 
 *  Programa: Agenda Electronica
 *  Modulo: agenda.c
 *  Autor: Alberto Miedes
 *  Fecha: 20-06-2001
 *  Descripción- Módulo que contiene la función de inicio del programa.
 */

#include <stdio.h>

/* ...................... */

/* 
 *  Función: main 
 *  Módulo: agenda.c
 *  Autor: Alberto Miedes
 *  Parámetros entrada: no tiene
 *  Parámetros salida: no tiene
 *  Descripción: Recoge un año e indica si es bisiesto.
 */
int main()
{
    int anyo;
    char tecla;

    printf("Hola, soy su agenda electrónica\n");
    printf("Pulsa una tecla para ver un ejemplo\n");
    scanf("%c",&tecla);
/*
 *  Calcular si un año que recibimos por el terminal es bisiesto o no, 
 *  mediante el uso de la estructura if-else
 */
    printf("\n¿Que año quieres saber si es bisiesto?\n");
    scanf("%d",&anyo);

    if (0 == (anyo % 100)) {
        if (0 == (anyo % 400)) {
            printf("el año %d es bisiesto\n",anyo);
        } else {
            printf("el año %d no es bisiesto\n",anyo); 
        }
    } else if (0 == (anyo % 4)) {  
            printf("el año %d es bisiesto\n",anyo);
    } else {
            printf("el año %d no es bisiesto\n",anyo); 
    }
    return(0);
}

