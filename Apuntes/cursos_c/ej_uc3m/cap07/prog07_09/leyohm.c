/*
 * Programa:    prog07_09
 * Fichero:     leyOhm.c
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 2:
 *              libreria de funciones de la ley de Ohm
 */
#include <stdio.h>
  

static float multiplicar(float a, float b);  /* Multiplica a * b */ 
static float dividir(float a, float b);      /* Dividir  a / b */ 
    
int vecesLeyOhm = 0;    /* Veces que se ha llamado a este módulo */
 
void calculoVoltaje(void)   /* Cálculo del voltaje en voltios. */
{
    float voltaje;     /* Voltaje del circuito en voltios.     */
    float intensidad;  /* Intensidad del circuito en amperios. */
    float resistencia; /* Resistencia del circuito en ohmios.  */

    static int vecesVol = 0; /* Veces que se ha calculado voltaje */

    printf("Introduzca la intensidad en amperios => ");
    scanf("%f",&intensidad);
    printf("Valor de la resistencia en ohmios => ");
    scanf("%f",&resistencia);

    voltaje = multiplicar(intensidad,  resistencia);
    printf("El voltaje es %f voltios.\n",voltaje);
 
    vecesLeyOhm ++;
    vecesVol ++;
    printf("Llamadas al módulo: %d  para voltaje %d \n", 
        vecesLeyOhm, vecesVol);    
}

void calculoIntensidad(void) /* Cálculo de la intensidad en amperios.*/
{
    float voltaje;     /* Voltaje del circuito en voltios.     */
    float intensidad;  /* Intensidad del circuito en amperios. */
    float resistencia; /* Resistencia del circuito en ohmios.  */

    static int vecesInt = 0; /* Veces que se ha calculado intensidad */

    printf("Introduzca el voltaje en voltios => ");
    scanf("%f",&voltaje);
    printf("Valor de la resistencia en ohmios => ");
    scanf("%f",&resistencia);

    intensidad = dividir(voltaje , resistencia);
    printf("La intensidad es %f amperios.\n",intensidad);
  
    vecesLeyOhm ++;
    vecesInt ++;
    printf("Llamadas al módulo: %d  para intensidad %d \n", 
        vecesLeyOhm, vecesInt);    
}
void calculoResistencia(void) /* Cálculo de la resistencia en ohmios.*/
{
    float voltaje;     /* Voltaje del circuito en voltios.     */
    float intensidad;  /* Intensidad del circuito en amperios. */
    float resistencia; /* Resistencia del circuito en ohmios.  */

    static int vecesRes = 0; /* Veces que se ha calculado resistencia */

    printf("Introduzca el voltaje en voltios => ");
    scanf("%f",&voltaje);
    printf("Valor de la intensidad en amperios => ");
    scanf("%f",&intensidad);

    resistencia = dividir(voltaje, intensidad);
    printf("La resistencia es %f ohmios.\n",resistencia);

    vecesLeyOhm ++;
    vecesRes ++;
    printf("Llamadas al módulo: %d  para resistencia %d \n", 
        vecesLeyOhm, vecesRes);    
}

static float multiplicar(float a, float b)  /* Multiplica a * b */ 
{
    return (a*b);
}

static float dividir(float a, float b)      /* Dividir  a / b */ 
{
    if (b == 0) {
        printf("Error, no se puede dividir por 0\n");
        return (-1);
    }
    else
        return (a/b);
}

