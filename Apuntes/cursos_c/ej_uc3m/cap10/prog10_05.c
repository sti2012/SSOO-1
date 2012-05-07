/*
 * Programa:    prog_10_05
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 10:
 *              Programa que lee dos fechas y las compara
 */

#include <stdio.h>
/*
 * Definición de la estructura Fecha
 */
struct Fecha
{
    int    dia;
    int    mes;
    int    anyo;
};

void imprimirFecha (struct Fecha f)
{
    printf("%2d/%2d/%4d\n", f.dia,   f.mes, f.anyo);
}


/*
 * Función que lee una fecha
 */
void leerFecha (struct Fecha *f)
{
    printf("Introduzca una fecha: ");
    scanf("%d %d %d", &(f->dia), &(f->mes), &(f->anyo));
    return;
}


/* 
 * Función que compara dos fechas
 * Devuelve 0 si f1 == f2
 * Devuelve 1 si fi > f2
 * Devuelve -1 si f1 < f2
 */
int compararFechas(struct Fecha f1, struct Fecha f2)
{
    int iguales = 0;

    if (f1.anyo > f2.anyo)
        iguales = 1;  /* f1 > f2 */
    else if ( f1.anyo < f2.anyo)
        iguales = -1; /* f1 < f2 */
    else
    {
        if (f1.mes > f2.mes)
           iguales = 1;  /* f1 > f2 */
        else if (f1.mes < f2.mes)
           iguales = -1; /* f1 < d2 */
        else
        {
           if (f1.dia > f2.dia)
               iguales = 1;    /* f1 > f2 */
           else if (f1.dia < f2.dia)
               iguales = -1;   /* f1 < f2 */
           iguales = 0;        /* f1 == f2 */
        }
    }

    return (iguales);
}

int main(void)
{
    struct Fecha fecha1;
    struct Fecha fecha2;
    int iguales;

    leerFecha(&fecha1);
    leerFecha(&fecha2);
   
    iguales = compararFechas (fecha1, fecha2);

    if (iguales == 1) {
        imprimirFecha(fecha1);
        imprimirFecha(fecha2);
    } else if (iguales == -1) {
        imprimirFecha(fecha2);
        imprimirFecha(fecha1);
    } else
        printf("Las dos fechas son iguales \n");

    return(0);
}

