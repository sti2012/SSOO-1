/* EJERCICIO 24.3.  copiaCadenas.c
      Escribir un programa que lea una cadena por teclado y la copie
      en otra cadena utilizando la función de string.h adecuada.
*/

#include <stdio.h>
/*  PROGRAMA 24: PUNTEROS Y PASO DE PARÁMETROS A FUNCIONES (Primera Parte)

    OBJETIVOS: saber interpretar los prototipos de funciones que presenten
    tipos de datos que sean punteros y utilizar correctamente estas funciones.

    INTRODUCCIÓN:

  - Un puntero almacena la dirección de una variable.
    Si decimos que un int es un número entero y un char es un carácter,
    podemos decir que un puntero es una dirección (hablando con propiedad,
    un puntero es una variable que almacena la dirección de otra variable).

  - La dirección de una variable se obtiene aplicando el operador &:

     &numero,  &caracter, &vector[2]...

  - El nombre de un array representa la dirección del primer elemento del array:
      Sea el array: int numeros[10];
      Entonces se cumple que:  &numeros[0] == numeros

  - Cuando se pasa un array como parámetro a una función, no se copian todos
    los elementos del array: solo la dirección del primer elemento.
    Esto supone un gran ahorro de memoria y de tiempo: imagínese que hubiese que
    copiar en la pila del programa 100.000 números enteros que, además, ya los
    tenemos en la memoria del programa.

  - Sabemos que el prototipo de una función nos indica qué tipo de datos espera
    la función y qué tipo de dato nos devuelve. Hemos de ajustarnos a los tipos
    especificados en el prototipo: no podemos pasar, por ejemplo, un float
    cuando se espera un char.

  - Una función puede presentar un prototipo en el que los parámetros sean
    punteros:
     int strlen(char *string);
    Esto significa que en dichos parámetros deberemos pasar una dirección.

  - Una función puede presentar un prototipo en el que el valor devuelto es
    un puntero:
      char *strstr(char *string1, char *string2);
    Esto significa que el valor devuelto es la dirección de una variable.

  - Cuando pasamos o recibimos un puntero (dirección), no estamos pasando
    realmente la variable, sino una referencia a ella. A través de su dirección
    podremos acceder a ella y leerla o modificarla.

  - Como regla, cuando haya que pasar un puntero (dirección) a una función,
    podremos pasar el valor de tres formas:
      a) aplicando el operador & a una variable.
      b) pasando un puntero que apunte a una variable.
      c) pasando el nombre de un array, ya que es la dirección del primer
         elemento.

      Cuando pasamos un puntero (dirección) a una función pasamos una referencia
      a una variable: ¿cómo sabemos si tenemos que pasar la dirección de un solo
      dato, o la dirección de comienzo de un array? Esto debe venir especificado
      en la documentación de la función:
      Por ejemplo, el fichero de cabecera string.h contiene la siguiente
      función:
        int strlen(char *str);
        "Devuelve la longitud de la cadena apuntada por str. La cadena debe
         terminar con el carácter nulo (terminador de cadena).
         La función no cuenta el nulo."
      Vemos que se especifica que str apunta a una cadena.
      ¿Para qué puede servir pasar la referencia a un solo carácter o número?
      Veremos más adelante que, al acceder a través de la dirección de una
      variable, podemos cambiar el valor de ésta.

 */

int mi_strlen(char* str);
int calculaLongitudCadena(char str[]);

/* mi_strlen calcula la longitud de una cadena de caracteres haciendo uso
de una función ya existente: decimos que "encapsula" a dicha función o que
"delega" el cálculo en la función strlen(). Más avanzado el curso comentaremos
si esto puede ser de alguna utilidad... o no.
*/

int mi_strlen(char* str)
{
   int longitud;
   longitud = strlen( str );
   return longitud;
}

/* calculaLongitudCadena calcula por sí misma la longitud de una cadena.
La declaración del parámetro str: char str[], es equivalente a la anterior:
char* str. En ambos casos se espera la dirección del primer elemento del array
*/

int calculaLongitudCadena(char str[])
{
     int i = 0;
     while( str[i] != '\0')
      i++;
     return i;
}

int main()
{
   char cadena1[] = "Hola a todos...";
   char *pChar;
   int longitud;
   char palabra[20];

   /*vamos a llamar a las funciones para calcular cadenas de diferentes formas:
     lo importante es que siempre pasemos la dirección del primer elemento
   */
   longitud = calculaLongitudCadena(&cadena1[0]);
   printf("La longitud de cadena1 es %d \n", longitud);

   longitud = calculaLongitudCadena(cadena1);
   printf("La longitud de cadena1 es %d \n", longitud);

   pChar = &cadena1[0];
   longitud = calculaLongitudCadena(pChar);
   printf("La longitud de cadena1 es %d \n", longitud);

   printf("\n");

   longitud = mi_strlen(&cadena1[0]);
   printf("La longitud de cadena1 es %d \n", longitud);

   longitud = mi_strlen(cadena1);
   printf("La longitud de cadena1 es %d \n", longitud);

   longitud = mi_strlen(pChar);
   printf("La longitud de cadena1 es %d \n", longitud);

   printf("\n");

   longitud = strlen(&cadena1[0]);
   printf("La longitud de cadena1 es %d \n", longitud);

   longitud = strlen(cadena1);
   printf("La longitud de cadena1 es %d \n", longitud);

   longitud = strlen(pChar);
   printf("La longitud de cadena1 es %d \n", longitud);
 
   /* Ahora pedimos al usuario una palabra y comprobamos si está contenida
      en la variable cadena1. Ver el prototipo y la descripción de la función
      strstr() más  abajo */

   printf("Introduce una palabra: ");
   scanf("%s", palabra);

   pChar = strstr(cadena1, palabra);
   if (pChar != NULL)
   {
      printf("La palabra '%s' se encuentra dentro de la cadena '%s'\n",palabra,
                                                                       cadena1);
      printf("El carácter apuntado por pChar es: %c \n", *pChar);
   }
   else
   {
     printf("La palabra '%s' NO se encuentra dentro de la cadena '%s'\n",
              palabra, cadena1);
   }

   system("PAUSE");
   return 0;
}

/* PROTOTIPOS:
   char *strstr(char *str1, char *str2);

   Busca str2 dentro de str1, es decir, la cadena apuntada por str2 dentro de la
   cadena apuntada por str1. Devuelve un puntero a la primera aparición dentro
   de la cadena apuntada por str1. El carácter nulo final de str2 no se compara.
   Devuelve un puntero nulo si no hay coincidencia


*/

/* INFORMACIÓN SOBRE FUNCIONES PARA MANEJO DE CADENAS.
  (Puede ampliarse la información utilizando el manual de Unix:
     Ejemplo:     man strlen
   )
Todas las funciones para manejo de cadenas tienen su prototipo en: 
#include <string.h>

Se muestra a continuación los prototipos de algunas de las funciones,
acompañadas de una breve descripción:

char *strcpy(const char *dest, const char *orig);
  Copia la cadena de caracteres apuntada por orig (incluyendo el carácter
  terminador '\0') al vector apuntado por dest. Las cadenas no deben solaparse,
  y la de destino, debe ser suficientemente grande como para alojar la copia.

int strcmp(const char *s1, const char *s2);
  Compara las dos cadenas de caracteres s1 y s2. Devuelve un entero menor,
  igual o mayor que cero si se encuentra que s1 es, respectivamente, menor que,
  igual a, o mayor que s2.

char *strcat(char *str1, char *str2);
   Concatena una copia de str2 a str1 y añade un nulo al final. El carácter
   nulo que tenía str1 se sobreescribe con el primer carácter de str2. La
   función devuleve un puntero a str1. str1 debe ser suficientemente grande
   para guardar su contenido original y el de str2.

int strlen(const char *s);
  Calcula la longitud de la cadena de caracteres.

char *strncat(char *s1, const char *s2, int n);
  Agrega n caracteres de s2 a s1.

int strncmp(const char *s1, char *s2, int n);
  Compara los primeros n caracteres de dos cadenas.

char *strncpy(const char *s1, const char *s2, int n);
  Copia los primeros n caracteres de s2 a s1.

strcasecmp(const char *s1, const char *s2);
  versión de strcmp() que ignora si son mayúsculas o minúsculas .

strncasecmp(const char *s1, const char *s2, int n);
  versión insensible a mayúsculas o minúsculas de strncmp() que compara los
  primeros n caracteres de s1.

char *strchr(const char *s, int c);
  Devuelve un puntero a la primera ocurrencia del carácter c en la cadena
  de caracteres s.

char *strrchr(const char *s, int c);
  Encuentra la última ocurrencia del caracter c en la cadena.

char *strstr(const char *s1, const char *s2);
  Localiza la primera ocurrencia de la cadena s2 en la cadena s1.

char *strpbrk(const char *s1, const char *s2);
  Regresa un apuntador a la primera ocurrencia en la cadena s1 de cualquier
  carácter de la cadena s2, o un apuntador nulo si no hay un caracter de s2
  que exista en s1.

*/