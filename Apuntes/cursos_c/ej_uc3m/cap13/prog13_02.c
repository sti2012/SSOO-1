/* 
 * Programa:    prog13_02
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 13:
 *              Programa que calcula una m�scara de bits de un n�mero
 */


#include <stdio.h>
#define MASCARA 0xF  /* 0...0000001111 */

int main(void)
{
    int n;

    printf("Introduzca n: ");
    scanf("%d", &n);
    printf("Bits menos significativos = %d\n",
        n & MASCARA );
    return (0);
}

