/* EJERCICIO 23.3.  (valorPunteros.c)
     Modifica el programa 23 para que se muestre el valor de los punteros
     que recorren arrays. ¿En cuánto se incrementan los punteros a carácter?
     ¿Y los punteros a enteros?  
*/

#include <stdio.h>
/*  PROGRAMA 23: PUNTEROS
    Un puntero es una variable que contiene la dirección de otra variable.
    Para declarar un puntero se emplea un * seguido del nombre de la
    variable:

    tipo *nombre;
    tipo* nombre;  (de cualquiera de las dos formas)

    donde "tipo" es cualquier tipo de variable en C y "nombre" es el nombre
    del puntero. El tipo indica el tipo de variables que se podrán manipular
    con el puntero:
     char *ptr;  indica que ptr guardará direcciones de variables "char",
                 es decir, apuntará a variables de tipo char.
     int *punt;  apuntará a variables enteras.

     Un puntero almacena una dirección.

     OPERADORES DE PUNTEROS: existen dos operadores unitarios que se utilizan
     con punteros:
      & : devuelve la dirección del operando al que se le aplica (se aplica
      a cualquier variable para calcular su dirección).
      Ejemplo:  int contador;  &contador -> nos da la dirección de memoria
      donde está almacenada la variable contador.

      * : nos da el contenido de (valor guardado en) una dirección de memoria.
         Este operador se aplica a los punteros.
       Ejemplo: int *punt;   numero = *punt; -> numero tomará el valor de lo
       que esté apuntando punt.
       (Recuérdese como, de forma similar, utilizábamos en ensamblador los
       corchetes sobre el registro BX : [BX], para obtener el contenido de
       la dirección de memoria a la que apuntaba BX)
       
       IMPORTANTE: un puntero debe contener una dirección válida.
       Si no apunta a una variable y utilizamos el puntero, podemos
       modificar datos de forma involuntaria o hacer que el programa 
       falle por intentar acceder a espacios de memoria no permitidos.
       Por el hecho de declarar un puntero a un entero (int *p) NO tenemos
       ningún valor entero, solo una variable que puede apuntar a enteros.
 */
int main()
{
   int i, j, k, m;
   int *ptr;
   int *p1, *p2;
   
   /* Inicializa un puntero: NULL indica que no apunta a ningún sitio, es
      una posición de memoria nula o no válida. NULL es una constante. */
   p1 = NULL;     
   p2 = NULL;
   
   j = 5;
   ptr = &j;
   k = *ptr;         /* k = 5 */
   i = *ptr * j;     /* i = 5 * 5 */
   m = *ptr * *ptr;  /*  m = (*ptr) * (*ptr); */
   
   printf("i = %d, j = %d, k = %d, m = %d \n", i, j, k, m);
   printf("el puntero ptr apunta a la direccion: %p \n", ptr);
   ptr = &i;
   printf("el puntero ptr apunta a la direccion: %p \n", ptr);
   i++;
   printf("El valor de i es: %d \n", i);
   printf("El valor apuntado por ptr es ahora: %d \n", *ptr);

   /* Los punteros pueden igualarse y compararse */
   p1 = &m;
   p2 = p1; /*p1 apunta a m */
   if (p2 == p1)
       puts("p1 y p2 son iguales, apuntan al mismo sitio");

   /* Aritmética de punteros y arrays */
   
   /* un puntero puede utilizarse para recorrer un array */
   {
      char saludo[]="Hola a todos";
      char *ptr;
      int numeros[]={1,2,3,4,5};
      int i;
      int* nPtr;
      
      ptr = &saludo[0]; /* apuntamos al primer elemento */
      printf("%c", *ptr);
      ptr++;            /* incrementamos el valor de ptr (la dirección,
                           no lo apuntado */
      printf("%c", *ptr);                     
      while (*ptr != '\0')
      {
         printf("%c", *ptr);
         ptr++; 
      }
      printf("\n");
      nPtr = &numeros[0];
      printf("Sizeof numeros. %d\n", (int) sizeof(numeros));
      for (i=0; i<(sizeof(numeros)/sizeof(int)); i++)
      {
          printf("%d ", *nPtr);
          nPtr++;   /* apuntamos al siguiente elemento */
      }
      /* ¿no deberíamos incrementar de cuatro en cuatro los punteros a 
          enteros, ya que ese es el tamaño de un entero? 
          NO, cuando incrementamos un puntero, el compilador sabe el tipo
          de variable a la que se apunta y lo incrementa en el valor necesario:
          no tenemos que saber cuánto ocupa una variable entera o de cualquier
          otro tipo.
      */
   }
   system("PAUSE");
   return 0;
}