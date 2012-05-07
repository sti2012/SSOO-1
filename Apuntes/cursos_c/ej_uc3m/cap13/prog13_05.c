/* 
 * Programa:    prog13_05
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 13:
 *              Programa que calcula de la ley de Ohm usando funciones 
 *              como argumentos
 */
   

#include <stdio.h>
    

void calculoVoltaje(void);      /* C�lculo del voltaje en voltios. */
void calculoIntensidad(void); /* C�lculo de intensidad en amperios.*/
void calculoResistencia(void);/* C�lculo de resistencia en ohmios.*/

/* Ejecuta la funci�n que recibe como par�metro */
void calculoLeyOhm (void (*funcion)(void)); 

void (*leyOhm[3])(void) =
{
    calculoVoltaje,
    calculoIntensidad,
    calculoResistencia
};

int main(void)
{
    char eleccion;     /* Elecci�n del usuario.                */

    printf("\n\nElija la forma de la ley de Ohm que corresponda:\n");
    printf("A] Voltaje B] Intensidad C] Resistencia\n");
    printf("Su eleccion (A, B, or C) => ");
    scanf("%c",&eleccion);

    switch(eleccion)
    {
        case 'A' : calculoLeyOhm(leyOhm[0]);
               break;
        case 'B' : calculoLeyOhm(leyOhm[1]);
               break;
        case 'C' : calculoLeyOhm(leyOhm[2]);
               break;
    }   /* Fin del switch. */
    return (0);
}

void calculoVoltaje(void)   /* C�lculo del voltaje en voltios. */
{
    float voltaje;     /* Voltaje del circuito en voltios.     */
    float intensidad;  /* Intensidad del circuito en amperios. */
    float resistencia; /* Resistencia del circuito en ohmios.  */

    printf("Introduzca la intensidad en amperios => ");
    scanf("%f",&intensidad);
    printf("Valor de la resistencia en ohmios => ");
    scanf("%f",&resistencia);
    voltaje = intensidad * resistencia;
    printf("El voltaje es %f voltios.\n",voltaje);
}

void calculoIntensidad(void) /* C�lculo de la intensidad en amperios.*/
{
    float voltaje;     /* Voltaje del circuito en voltios.     */
    float intensidad;  /* Intensidad del circuito en amperios. */
    float resistencia; /* Resistencia del circuito en ohmios.  */

    printf("Introduzca el voltaje en voltios => ");
    scanf("%f",&voltaje);
    printf("Valor de la resistencia en ohmios => ");
    scanf("%f",&resistencia);
    intensidad = voltaje / resistencia;
    printf("La intensidad es %f amperios.\n",intensidad);
}

void calculoResistencia(void) /* C�lculo de la resistencia en ohmios.*/
{
    float voltaje;     /* Voltaje del circuito en voltios.     */
    float intensidad;  /* Intensidad del circuito en amperios. */
    float resistencia; /* Resistencia del circuito en ohmios.  */

    printf("Introduzca el voltaje en voltios => ");
    scanf("%f",&voltaje);
    printf("Valor de la intensidad en amperios => ");
    scanf("%f",&intensidad);
    resistencia = voltaje / intensidad;
    printf("La resistencia es %f ohmios.\n",resistencia);
}

void calculoLeyOhm (void (*funcion)(void))
{
    funcion();
}

