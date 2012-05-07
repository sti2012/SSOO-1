/*
 * Programa:    prog_04_05
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 4:
 *              Programa que lee dos n�meros e imprime el mayor y el menor
 */
#include <stdio.h>

 
int main(void)
{
    int n1;
    int n2;
    int mayor;
    int menor;
    
    printf("Introduzca el primer n�mero: ");
    scanf("%d", &n1);
    
    printf("Introduzca el segundo n�mero: ");
    scanf("%d", &n2);
    
    mayor = (n1 > n2) ?   n1  :  n2;
    menor = (n1 < n2) ?   n1  :  n2;
    
    printf("El mayor es %d\n", mayor);
    printf("El menor es %d\n", menor);
    
    return(0);
}
