/*
 * Programa:    prog_07_09
 * Fichero:     prog_07_09.c
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 7:
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
    char eleccion;     /* Elección del usuario.                */

    do
    {
        /* Lectura de la operación a realizar */
        printf("\n\nElija la forma de la ley de Ohm que");             
        printf(" corresponda:\n");
        printf("A] Voltaje B] Intensidad C] Resistencia S] Salir\n");
        printf("Su eleccion (A, B, C, o S) => ");
        scanf("%c",&eleccion);

        /* Realización de la operación de la ley de Ohm */
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
                      printf ("Operación no válida \n");
                      break;
        }   /* Fin del switch. */
    } while (eleccion != 'S');

    return (0);
}

