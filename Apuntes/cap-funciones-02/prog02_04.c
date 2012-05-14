/*
 * Programa:    prog_02_04
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 2:
 *              Programa estructurado en C. Imprime un saludo al lector
 */

#include <stdio.h>
#define DESTINO "Lector"

/*
 * Prototipo de funciones
 */
int imprimir_saludo (char * destino);

int main(void)
{
    int error = 0;
    
    /* 
     * Función que imprime un mensaje de saludo al Lector
     */
     error = imprimir_saludo (DESTINO);

    /* 
     * Terminación del programa 
     */
    if (error == 0) 
        return(0);  /* correcto */
    else
    {
        printf("Error al imprimir saludo.\n");
        return(-1); /* incorrecto */
    }
}

int imprimir_saludo (char * destino)
{

    int error_impresion = 0;

    error_impresion = printf("Hola %s.\n", destino);

    if (error_impresion < 0) /* incorrecto */
    { 
        printf("Error en printf.\n");
        return (error_impresion);
    }
    else
        return (0);
}
