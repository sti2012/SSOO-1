/*
*ejemplox_101.c
*/
#include <stdio.h>
#include <stdlib.h>

// Definición de tipos
typedef struct {
   int numerador;
   int denominador;
} Racional;

// Funciones de utilidad
int maximoComunDivisor(int a, int b) {
    while (1) {
       a=a%b;
	   if (a==0) return b;
	   b=b%a;
       if (b==0) return a;
    }
}

void simplificar(Racional *q) {
   int mcd=maximoComunDivisor(q->numerador,q->denominador);
   q->numerador   /= mcd;
   q->denominador /= mcd;
   if (q->denominador<0) {
      q->denominador*=-1;
      q->numerador*=-1;
   }
}

void imprimirRacional(const Racional q) {
   if (q.numerador==0) printf("0");
   else if (q.denominador==1) printf("%d",q.numerador);
   else printf("%d/%d",q.numerador,q.denominador);
}

Racional leerRacional() {
   Racional q;
   printf("Introduzca racional en formato num/den:");
   scanf("%d/%d",&q.numerador,&q.denominador);
   simplificar(&q);
   return q;
}

Racional suma(const Racional q1, const Racional q2) {
   Racional q;
   q.numerador=q1.numerador*q2.denominador+q2.numerador*q1.denominador;
   q.denominador=q1.denominador*q2.denominador;
   simplificar(&q);
   return q;
}

Racional resta(const Racional q1, const Racional q2) {
   Racional q;
   q.numerador=q1.numerador*q2.denominador-q2.numerador*q1.denominador;
   q.denominador=q1.denominador*q2.denominador;
   simplificar(&q);
   return q;
}

Racional multiplicacion(const Racional q1, const Racional q2) {
   Racional q;
   q.numerador=q1.numerador*q2.numerador;
   q.denominador=q1.denominador*q2.denominador;
   simplificar(&q);
   return q;
}

Racional division(const Racional q1, const Racional q2) {
   Racional q;
   q.numerador=q1.numerador*q2.denominador;
   q.denominador=q1.denominador*q2.numerador;
   simplificar(&q);
   return q;
}

int main() {
   enum Opcion {EntradaQ1=1, EntradaQ2, Sumar, Restar,
      Multiplicar, Dividir, Terminar} opcion;
   enum Operacion {OpNinguna, OpSumar, OpRestar,
      OpMultiplicar, OpDividir} operacion=OpNinguna;
   Racional q1, q2, q0;
   q1.numerador=q1.denominador=0;
   q2.numerador=q2.denominador=0;
   q0.numerador=q0.denominador=0;
   do {
      system("CLS");
      printf("Q1="); imprimirRacional(q1); printf("\n");
      printf("Q2="); imprimirRacional(q2); printf("\n");
      switch (operacion) {
         case OpNinguna: break;
         case OpSumar:
            printf("Q0=Q1+Q2="); imprimirRacional(q0); printf("\n");
            break;
         case OpRestar:
            printf("Q0=Q1-Q2="); imprimirRacional(q0); printf("\n");
            break;
         case OpMultiplicar:
            printf("Q0=Q1*Q2="); imprimirRacional(q0); printf("\n");
            break;
         case OpDividir:
            printf("Q0=Q1/Q2="); imprimirRacional(q0); printf("\n");
            break;
      }
      printf("\n");
      
      printf("1.- Introducir Q1\n"
             "2.- Introducir Q2\n"
             "3.- Sumar\n"
             "4.- Restar\n"
             "5.- Multiplicar\n"
             "6.- Dividir\n"
             "7.- Terminar\n"
             "Opción:");
      scanf("%d",&opcion);
      switch (opcion) {
         case EntradaQ1:
              q1=leerRacional();
              break;
         case EntradaQ2:
              q2=leerRacional();
              break;
         case Sumar:
              q0=suma(q1,q2);
              operacion=OpSumar;
              break;
         case Restar:
              q0=resta(q1,q2);
              operacion=OpRestar;
              break;
         case Multiplicar:
              q0=multiplicacion(q1,q2);
              operacion=OpMultiplicar;
              break;
         case Dividir:
              q0=division(q1,q2);
              operacion=OpDividir;
              break;
      }
   } while (opcion!=Terminar);
   return 0;
}
