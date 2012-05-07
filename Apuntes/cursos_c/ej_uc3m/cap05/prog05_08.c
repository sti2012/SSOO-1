/* 
 *  Programa: Agenda Electronica
 *  Modulo: agenda.c
 *  Autor: Alberto Miedes
 *  Fecha: 20-06-2001
 *  Descripci�n- M�dulo que contiene la funci�n de inicio del programa.
 */

#include <stdio.h>

/*
 *  Tipos
 */
enum MesesAnyo { enero, febrero, marzo, abril, mayo, junio, julio, 
                 agosto, septiembre, octubre, noviembre, diciembre };
typedef enum MesesAnyo TipoMes;

/* ...................... */

/* 
 *  Funci�n: main 
 *  M�dulo: agenda.c
 *  Autor: Alberto Miedes
 *  Par�metros entrada: no tiene
 *  Par�metros salida: no tiene
 *  Descripci�n: Dado un mes, muestra su n�mero de dias.
 */
int main()
{
    TipoMes mes;
    int     diasMes;
    char    tecla;

    printf("Hola, soy su agenda electr�nica\n");
    printf("Pulsa una tecla para ver un ejemplo\n");
    scanf("%c",&tecla);

    /*
     * Calcular el N� de d�as de un mes
     */
    printf("\nIntroduzca el n�mero del mes (0-11): ");
    scanf("%d", (int *) &mes);
    
    switch (mes) {
    case abril:
    case junio:
    case septiembre:
    case noviembre:
        diasMes = 30;
        break;
    case febrero:
        diasMes = 28;
        break;
    default:
        diasMes = 31;
    }
    printf("\nEl mes n�mero %d tiene %d dias.\n",mes,diasMes);

    return(0);
}

