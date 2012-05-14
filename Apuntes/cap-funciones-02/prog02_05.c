/*
 * Programa:    prog_02_05
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 2:
 *              Divisi�n entera con comprobaci�n de error 
 *              Adem�s, da error si el cociente es menor de 3
 */

#include <stdio.h>

/*
 * Prototipo de funciones
 */
int dividir_mayor_que_3 (int x, int y);

int main(void)
{
    int cociente = 0;
    int x = 0;
    int y = 0;
    
    /* 
     * pedir los operandos de la divisi�n
     */
     printf("Introduzca el dividendo: ");
     scanf("%d", &x);
     printf("Introduzca el divisor: ");
     scanf("%d", &y);

     printf("\n");

     cociente = dividir_mayor_que_3 (x,y);

    /* 
     * Terminaci�n del programa 
     */
    if (cociente >= 0) 
    {
        printf("%d / %d es %d \n", x, y, cociente);   
        return(0);  /* correcto */
    } 
    else
    {
        if (cociente == -1) 
            printf("Division por cero. Buen filtro de par�metros\n");
	else 
            if (cociente == -2) 
            {
                printf("La funcion indica cociente menor que 3.\n");
                printf("Realizar acci�n correctora de valores.\n");
            }
        return(-1); /* incorrecto */
    }
    return(cociente); 
}
/*
 * Divide x/y y comprueba cociente mayor que 3
 */
int dividir_mayor_que_3 (int x, int y)
{

    int error_division_cero = -1;
    int error_cociente = -2;
    int cociente = -3;

    if (y == 0)
    { 
         printf("dividir_mayor_que_3: El divisor es cero.\n");
         cociente = error_division_cero;
    }
    else
    { 
         cociente = x / y;
	 if (cociente < 3)
         { 
             printf("dividir_mayor_que_3: El cociente %d es menor que 3.\n", cociente);
             cociente = error_cociente;
          }
    }
    return (cociente);
}
