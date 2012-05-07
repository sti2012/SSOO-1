/*
 * Programa:    prog_02_02
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
    
    /* 
     * Función que imprime un mensaje de saludo al Lector
     */
     imprimir_saludo (DESTINO);

    /* 
     * Terminación del programa 
     */
    return(0);  /* correcto */
}

int imprimir_saludo (char * destino)
{

    printf("Hola %s.\n", destino);
    return (0);
}
