/* 
 *  Programa: Agenda Electronica
 *  Modulo: agenda.c
 *  Autor: Alberto Miedes
 *  Fecha: 20-06-2001
 *  Descripción- Módulo que contiene la función de inicio del programa.
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
 *  Función: main 
 *  Módulo: agenda.c
 *  Autor: Alberto Miedes
 *  Parámetros entrada: no tiene
 *  Parámetros salida: no tiene
 *  Descripción: Dado un mes, muestra su número de dias.
 */
int main()
{
    TipoMes mes;
    int     diasMes;
    char    tecla;

    printf("Hola, soy su agenda electrónica\n");
    printf("Pulsa una tecla para ver un ejemplo\n");
    scanf("%c",&tecla);

    /*
     * Calcular el Nº de días de un mes
     */
    printf("\nIntroduzca el número del mes (0-11): ");
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
    printf("\nEl mes número %d tiene %d dias.\n",mes,diasMes);

    return(0);
}

