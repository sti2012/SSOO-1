/* EJERCICIO 19.5  (imprimeNumeros.c)
       Codificar un programa que contenga una funci�n con el siguiente
       prototipo:
         void imprimeNumeros(int enteros[], int n);
       que imprime separados por blancos los n primeros n�meros del array
       de enteros pasado.
*/

#include <stdio.h>
/*  PROGRAMA 19: T�cnica de programaci�n por acceso a tablas (arrays)
       "Table driven methods"

    En este programa vamos a utilizar una t�cnica muy interesante para
    el desarrollo de programas. Consiste en "indexar" (utilizar un �ndice)
    para acceder a datos que est�n en una matriz o tabla. En este ejemplo
    vamos a utilizar una matriz unidimensional (array de caracteres) pero la
    idea se puede aplicar a otras estructuras de datos.

    Vamos a realizar un programa que calcule la letra del NIF:

   El procedimiento empleado para el c�lculo de la letra del NIF consiste en
   hallar el m�dulo (o resto) de dividir el DNI por 23.
   El n�mero resultante (comprendido entre 0 y 22) tiene una letra asignada.
   La secuencia no es correlativa:

   T R W A G M Y F P D X B N J Z S Q V H L C K E


   En lugar de calcular el n�mero y utilizar alternativas (if... else o switch)
   emplearemos un �ndice para acceder a la letra correcta. Lo �nico que tenemos
   que hacer es construir un array que contenga las letras en el orden correcto,
   y utilizar el n�mero calculado como �ndice.

 */


int main()
{
   char letras[]="TRWAGMYFPDXBNJZSQVHLCKE";
   int dni, indice;

   printf("Introduce DNI: ");
   scanf("%d", &dni);
   indice = dni % 23;

   printf("La asociada al DNI %d es la %c \n", dni, letras[indice]);

   system("PAUSE");
   return 0;
}