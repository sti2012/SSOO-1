/*
 * Programa:    prog_07_09
 * Fichero:     prog_07_09.c
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 7:
 *              Programa que calcula la ley de Ohm
 */

#include <stdio.h>
#include "leyohm.h"

/*
 * Prototipos de funciones que importa
 */
extern void calculoVoltaje(void);   
extern void calculoIntensidad(void);
extern void calculoResistencia(void);

    
int main(void)
{
    char eleccion;     /* Elecci�n del usuario.                */

    do
    {
        /* Lectura de la operaci�n a realizar */
        printf("\n\nElija la forma de la ley de Ohm que");             
        printf(" corresponda:\n");
        printf("A] Voltaje B] Intensidad C] Resistencia S] Salir\n");
        printf("Su eleccion (A, B, C, o S) => ");
        scanf("%c",&eleccion);

        /* Realizaci�n de la operaci�n de la ley de Ohm */
        switch(eleccion){            
            case 'A': 
                      calculoVoltaje();
                      break;
            case 'B': 
                      calculoIntensidad();
                      break;  
            case 'C': 
                      calculoResistencia();
                      break;
            default: 
                      printf ("Operaci�n no v�lida \n");
                      break;
        }   /* Fin del switch. */
    } while (eleccion != 'S');

    return (0);
}

