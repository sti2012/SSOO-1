/*
 * Programa:    prog_05_011
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 5:
 *              Programa con errores
 */
#include <stdio.h>

int main(void)
{
    /* Contadores de bucles */
    int contador;
    int i;
    int control = 0.0;
    int valor = 0;

    /* Imprimir valor mientras contador sea menor que 10 */
    while (contador < 10)
    {
        printf("N�mero: %d \n", valor);
        contador ++;
    }

    /* Imprimir valor e incrementarlo 5 veces */
    for (i=0; i < 5; i++)
        printf("N�mero: %d \n", valor);
        valor ++;


    /* Imprimir valor mientras contador sea menor que 10.*/
    contador = 0;
    while (contador < 10);
    {
        printf("N�mero: %d \n", valor);
        contador ++;
    }
    /* Imprimir valor mientras contador sea menor que 10.
     * Si contador es igual a 5, imprimir un aviso
     */
    contador = 0;
    valor = 1;
    while (contador < 10)
    {
        printf("N�mero: %d \n", valor*5);
        if ( contador = 5)
        {
            printf("Valor contador es 5\n");
        }
        contador ++;
    }

    /* Imprimir valor hasta que i sea igual a 5 */
    for (i=0; i == 5; i++)
    {
        printf("N�mero: %d \n", valor);
    }


    /* Imprimir contador 10 veces, increment�ndolo.*/
    contador = 1;
    while (contador < 10);
    {
        printf("N�mero: %d \n", contador);
        contador ++;
    }

    /* Imprimir contador 10 veces, increment�ndolo.*/
    contador = 0;
    while (contador <= 10);
    {
        printf("N�mero: %d \n", contador);
        contador ++;
    }
    /* Imprimir control hasta que sea 2.*/
    control = 0.0;
    while (control != 0.249);
    {
        printf("N�mero: %f \n", control);
        control += 0.249;
    }

    /* Imprimir control hasta que sea 2, excepto en el tramo entre 0.5 y 1.0.*/
    control = 0.0;
    while (control != 0.2499999999999);
    {
        if ((control > 0.5) && (control < 1.0))
            break;
        printf("N�mero: %f \n", control);
        control += 0.249999999999;
    }


    /* Imprimir valor hasta que i sea igual a 5 */
    valor = 1;
    for (i=0; (i < 5) && ( valor ++ < 7); i++)
    {
        printf("N�mero: %d \n", valor);
    }


    /* Imprimir valor+7 hasta que i y k sean iguales a 5,  */
    valor = 1;
    for (i=0; i < 5; i++)
    {

        for (k = 0; k < 5; k ++)
        {
            i = valor + 7;
            printf("N�mero: %d \n", i);       
        }
    }


    /* Imprimir valor+i hasta que i sea igual a 5, pero s�lo 
     * para los i impares 
     */
    valor = 1;
    for (i=0; i <= 5; i++)
    {
        switch (i)
        {
        case 1:
            printf("N�mero: %d \n", valor + i);       
        case 3:
            printf("N�mero: %d \n", valor + i);       
            break;
        case 5:
            printf("N�mero: %d \n", valor + i);       
        default:
            printf("N�mero: %d \n", valor + i);       
            break;
        }
    }
}

