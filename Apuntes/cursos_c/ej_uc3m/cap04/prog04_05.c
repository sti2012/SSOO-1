/*
 * Programa:    prog_04_05
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 4:
 *              Programa que lee dos números e imprime el mayor y el menor
 */
#include <stdio.h>

 
int main(void)
{
    int n1;
    int n2;
    int mayor;
    int menor;
    
    printf("Introduzca el primer número: ");
    scanf("%d", &n1);
    
    printf("Introduzca el segundo número: ");
    scanf("%d", &n2);
    
    mayor = (n1 > n2) ?   n1  :  n2;
    menor = (n1 < n2) ?   n1  :  n2;
    
    printf("El mayor es %d\n", mayor);
    printf("El menor es %d\n", menor);
    
    return(0);
}
