/* Ejercicio 16.2  (cuentaVocales.c)
      Implementar un programa que pida 15 caracteres por teclado y muestre
      a continuación cuántas veces se ha introducido cada vocal.
      Informar al usuario de cuál es la vocal que ha aparecido más veces.
      */

#include <stdio.h>
#include <ctype.h>


int main()
{
   char c, caracter;
   int num;
   int vocala=0, vocale=0, vocali=0, vocalo=0, vocalu=0;
   char vocalmas;

   printf("Introduce 15 caracteres: [               ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

   num = 1;

   do
   {
      num++;
      scanf("\n%c", &c);

      caracter = tolower(c);

         switch(caracter)
         {
            case 'a': 
            {
              vocala++;
//              printf("\nHas pulsado la vocal: %c\n", c);
              break;
            }
            case 'e':
            {
              vocale++;
//              printf("\nHas pulsado la vocal: %c\n", c);
              break;
            }
            case 'i':
            {
              vocali++;
//              printf("\nHas pulsado la vocal: %c\n", c);
              break;
            }
            case 'o':   
            {         
              vocalo++;
//              printf("\nHas pulsado la vocal: %c\n", c);
              break;
            }
            case 'u':
            {            
              vocalu++;
//              printf("\nHas pulsado la vocal: %c\n", c);
              break;
            }
            default: break; //printf("\n%c NO es una vocal \n", c);
         }
   }while (num <= 15);

   printf("\nHas introducido (%d A) (%d E) (%d I) (%d O) (%d U)\n", vocala, vocale, vocali, vocalo, vocalu);

   if (vocala > vocale && vocala > vocali && vocala > vocalo && vocala > vocalu)
   {
     vocalmas = 'A';
   }
   else if (vocala < vocale && vocale > vocali && vocale > vocalo && vocale > vocalu)
   {
     vocalmas = 'E';
   }
   else if (vocala < vocali && vocale < vocali && vocali > vocalo && vocali > vocalu)
   {
     vocalmas = 'I';
   }
   else if (vocala < vocalo && vocale < vocalo && vocali < vocalo && vocalo > vocalu)
   {
     vocalmas = 'O';
   }
   else if (vocala < vocalu && vocale < vocalu && vocali < vocalu && vocalo < vocalu)
   {
     vocalmas = 'U';
   }
   else 
   {
      printf("\nHa habido un empate entre 2 o mas vocales.\n");
      system("pause");
      return 0;
   }
   printf("\nLa vocal mas veces pulsada ha sido la %c\n", vocalmas);
   system("pause");
   return 0;
}