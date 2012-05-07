/* 
 * Programa:    prog13_01
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 13:
 *              Programa que c�lcula de la ley de Ohm con punteros a funciones
 */


    #include <stdio.h>

    void calculoVoltaje(void);   /* C�lculo del voltaje en voltios.      */
    void calculoIntensidad(void);/* C�lculo de la intensidad en amperios.*/
    void calculoResistencia(void);/* C�lculo de la resistencia en ohmios.*/

    float multiplicar(float a, float b);  /* Multiplica a * b */ 
    float dividir(float a, float b);      /* Dividir  a / b */ 

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
            case 'A' : (*leyOhm[0])();
                   break;
            case 'B' : (*leyOhm[1])();
                   break;
            case 'C' : (*leyOhm[2])();
                   break;
        }   /* Fin del switch. */
	return (0);
    }

    

    void calculoVoltaje(void)   /* C�lculo del voltaje en voltios. */
    {
        float (*operacion)(float a, float b);  /* Operacion  con a y b */ 
        float voltaje;     /* Voltaje del circuito en voltios.     */
        float intensidad;  /* Intensidad del circuito en amperios. */
        float resistencia; /* Resistencia del circuito en ohmios.  */
   

        operacion = multiplicar;
        printf("Introduzca la intensidad en amperios => ");
        scanf("%f",&intensidad);
        printf("Valor de la resistencia en ohmios => ");
        scanf("%f",&resistencia);
        voltaje = (*operacion)(intensidad,  resistencia);
        printf("El voltaje es %f voltios.\n",voltaje);

    }

    void calculoIntensidad(void) /* C�lculo de la intensidad en amperios.*/
    {
        float (*operacion)(float a, float b);  /* Operacion  con a y b */ 
        float voltaje;     /* Voltaje del circuito en voltios.     */
        float intensidad;  /* Intensidad del circuito en amperios. */
        float resistencia; /* Resistencia del circuito en ohmios.  */

    

        operacion = dividir;
        printf("Introduzca el voltaje en voltios => ");
        scanf("%f",&voltaje);
        printf("Valor de la resistencia en ohmios => ");
        scanf("%f",&resistencia);
        intensidad = (*operacion)(voltaje , resistencia);
        printf("La intensidad es %f amperios.\n",intensidad);
    }

    void calculoResistencia(void) /* C�lculo de la resistencia en ohmios.*/
    {
        float (*operacion)(float a, float b);  /* Operacion  con a y b */ 
        float voltaje;     /* Voltaje del circuito en voltios.     */
        float intensidad;  /* Intensidad del circuito en amperios. */
        float resistencia; /* Resistencia del circuito en ohmios.  */

    

        operacion = dividir;
        printf("Introduzca el voltaje en voltios => ");
        scanf("%f",&voltaje);
        printf("Valor de la intensidad en amperios => ");
        scanf("%f",&intensidad);
        resistencia = (*operacion)(voltaje , intensidad);
        printf("La resistencia es %f ohmios.\n",resistencia);
    }

    float multiplicar(float a, float b)  /* Multiplica a * b */ 
    {
        return (a*b);
    }

    float dividir(float a, float b)      /* Dividir  a / b */ 
    {
        if (b == 0)
            return (-1);
        else
            return (a/b);
    }

