/* Ejercio 8.2. renta.c:
      Calcular el importe a pagar en la declaración de la renta de tres personas que ganan
      anualmente 12000, 22000 y 35000 Euros respectivamente, suponiendo que las rentas entre 
      0 y 10000 no cotizan, entre 10001 y ....20000 cotizan al 5% y las siguientes 20% 
*/   

#include <stdio.h>
#include <stdlib.h>

int main()
{
     int a=12000;
     int b=22000;
     int c=35000;
     int P1;
     int P2;
     int P3;
     int total;

     P1 = cotiza(a);
     P2 = cotiza(b);
     P3 = cotiza(c);
     printf("El sueldo de %d declara %d \n", a, P1);
     printf("El sueldo de %d declara %d \n", b, P2);
     printf("El sueldo de %d declara %d \n", c, P3);

     total = P1 + P2 + P3;
     printf("El total a cotizar entre las tres personas es: %d \n", total);

     system("pause");
} 

int cotiza(int x){
    int y;

    if (x > 20000)
    {
        y = (x*20)/100;
        return y;
    }
    else if (10000 < x <= 20000)
    {
        y = (x*5)/100;
        return y;
    }
    else if ( x <= 10000 )
    {
        y = 0;
        return y;
    }
    else
    {
        printf("Inserta un sueldo en euros");
        return;
    }
}


/* Usar esta forma si se cuenta cada intervalo por separado
    Ej de 12000 solo lo que supera 10000 al 5%.

int cotiza(int x){
    int y;
    int z;

     if ( x > 20000 )
        {
            z = (x-20001)*20/100;
            y = (20000-10001)*5/100;
            x = z + y;
            return;
        }
     else if ( 10000 < x <= 20000 )
        {
            y = (x-10001)*5/100;
            x = y;
            return;
        }
     else if ( x <= 10000 )
        {
            x = 0;
            return;
        }
     else
        {
            printf("Inserta un sueldo en euros");
            return;
        }
}
*/