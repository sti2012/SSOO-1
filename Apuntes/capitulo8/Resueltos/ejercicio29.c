/*
*ejemplox_29.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char entradaDivisa(const char* tipoDivisa);
void entrada(char* divisaInicial, char* divisaFinal, double* cantidad);
double conversion (char divisaInicial, char divisaFinal, double cantidad);
void salida (double valor);

int main()
{
        char divisaInicial, divisaFinal;
        double cantidad, cantidadConvertida;

        printf("Programa para de conversión de divisas.\n");
        entrada(&divisaInicial,&divisaFinal,&cantidad);
        cantidadConvertida=conversion(divisaInicial,divisaFinal,cantidad);
        salida(cantidadConvertida);

        system ("PAUSE");
        return 0;
}

char entradaDivisa(const char *tipoDivisa) {
   int entradaValida;
   char divisa;
   
   // Solicitar divisaInicial
   do {
       entradaValida=1;
        printf("Introduzca la divisa %s:\n",tipoDivisa);
        printf("E. Para euros\n"
               "P. Para pesetas\n"
               "F. Para francos\n");
        scanf(" %c",&divisa);
        divisa=toupper(divisa);
        if (divisa!='E' && divisa!='P' && divisa!='F')
        {
        printf("La divisa introducida no es correcta\n");
        entradaValida=0;
        }
   } while (!entradaValida);
   return divisa;
}

void entrada(char* divisaInicial, char* divisaFinal, double* cantidad)
{
   *divisaInicial=entradaDivisa("inicial");
   *divisaFinal=entradaDivisa("final");
   printf("Introduzca la cantidad que desea convertir:\n");
   scanf(" %lf",cantidad);
}

double conversion (char divisaInicial, char divisaFinal, double valor)
{
        double valorConvertido=valor;
        switch (divisaInicial)
        {
                case 'E': if (divisaFinal == 'P')
                          {
                                valorConvertido = valor * 166.386;
                          }
                          else if (divisaFinal == 'F')
                          {
                                valorConvertido = valor * 1.57;
                          }

                          break;

                case 'P': if (divisaFinal == 'E')
                          {
                                valorConvertido = valor / 166.386;
                          }
                          else if (divisaFinal == 'F')
                          {
                                valorConvertido = (valor / 166.386) * 1.57;
                          }
                          break;

                case 'F': if (divisaFinal == 'E')
                          {
                                valorConvertido = valor / 1.57;
                          }
                          else if (divisaFinal == 'P')
                          {
                                valorConvertido = (valor / 166.386) / 1.57;
                          }
                          break;

        }
        return valorConvertido;
}

void salida(double valor)
{
        printf("El valor convertido es %f\n",valor);
}

