/* 
 *  Programa: Agenda Electronica
 *  Modulo: agenda.c
 *  Autor: Alberto Miedes
 *  Fecha: 20-06-2001
 *  Descripci�n- M�dulo que contiene la funci�n de inicio del programa.
 */

#include <stdio.h>

/* ...................... */

/* 
 *  Funci�n: main 
 *  M�dulo: agenda.c
 *  Autor: Alberto Miedes
 *  Par�metros entrada: no tiene
 *  Par�metros salida: no tiene
 *  Descripci�n: Recoge un a�o e indica si es bisiesto.
 */
int main()
{
    int anyo;
    char tecla;

    printf("Hola, soy su agenda electr�nica\n");
    printf("Pulsa una tecla para ver un ejemplo\n");
    scanf("%c",&tecla);
/*
 *  Calcular si un a�o que recibimos por el terminal es bisiesto o no, 
 *  mediante el uso de la estructura if-else
 */
    printf("\n�Que a�o quieres saber si es bisiesto?\n");
    scanf("%d",&anyo);

    if (0 == (anyo % 100)) {
        if (0 == (anyo % 400)) {
            printf("el a�o %d es bisiesto\n",anyo);
        } else {
            printf("el a�o %d no es bisiesto\n",anyo); 
        }
    } else if (0 == (anyo % 4)) {  
            printf("el a�o %d es bisiesto\n",anyo);
    } else {
            printf("el a�o %d no es bisiesto\n",anyo); 
    }
    return(0);
}

