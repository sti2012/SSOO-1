/* EJERCICIO 24.3.  copiaCadenas.c
      Escribir un programa que lea una cadena por teclado y la copie
      en otra cadena utilizando la funci�n de string.h adecuada.
*/

#include <stdio.h>
/*  PROGRAMA 24: PUNTEROS Y PASO DE PAR�METROS A FUNCIONES (Primera Parte)

    OBJETIVOS: saber interpretar los prototipos de funciones que presenten
    tipos de datos que sean punteros y utilizar correctamente estas funciones.

    INTRODUCCI�N:

  - Un puntero almacena la direcci�n de una variable.
    Si decimos que un int es un n�mero entero y un char es un car�cter,
    podemos decir que un puntero es una direcci�n (hablando con propiedad,
    un puntero es una variable que almacena la direcci�n de otra variable).

  - La direcci�n de una variable se obtiene aplicando el operador &:

     &numero,  &caracter, &vector[2]...

  - El nombre de un array representa la direcci�n del primer elemento del array:
      Sea el array: int numeros[10];
      Entonces se cumple que:  &numeros[0] == numeros

  - Cuando se pasa un array como par�metro a una funci�n, no se copian todos
    los elementos del array: solo la direcci�n del primer elemento.
    Esto supone un gran ahorro de memoria y de tiempo: imag�nese que hubiese que
    copiar en la pila del programa 100.000 n�meros enteros que, adem�s, ya los
    tenemos en la memoria del programa.

  - Sabemos que el prototipo de una funci�n nos indica qu� tipo de datos espera
    la funci�n y qu� tipo de dato nos devuelve. Hemos de ajustarnos a los tipos
    especificados en el prototipo: no podemos pasar, por ejemplo, un float
    cuando se espera un char.

  - Una funci�n puede presentar un prototipo en el que los par�metros sean
    punteros:
     int strlen(char *string);
    Esto significa que en dichos par�metros deberemos pasar una direcci�n.

  - Una funci�n puede presentar un prototipo en el que el valor devuelto es
    un puntero:
      char *strstr(char *string1, char *string2);
    Esto significa que el valor devuelto es la direcci�n de una variable.

  - Cuando pasamos o recibimos un puntero (direcci�n), no estamos pasando
    realmente la variable, sino una referencia a ella. A trav�s de su direcci�n
    podremos acceder a ella y leerla o modificarla.

  - Como regla, cuando haya que pasar un puntero (direcci�n) a una funci�n,
    podremos pasar el valor de tres formas:
      a) aplicando el operador & a una variable.
      b) pasando un puntero que apunte a una variable.
      c) pasando el nombre de un array, ya que es la direcci�n del primer
         elemento.

      Cuando pasamos un puntero (direcci�n) a una funci�n pasamos una referencia
      a una variable: �c�mo sabemos si tenemos que pasar la direcci�n de un solo
      dato, o la direcci�n de comienzo de un array? Esto debe venir especificado
      en la documentaci�n de la funci�n:
      Por ejemplo, el fichero de cabecera string.h contiene la siguiente
      funci�n:
        int strlen(char *str);
        "Devuelve la longitud de la cadena apuntada por str. La cadena debe
         terminar con el car�cter nulo (terminador de cadena).
         La funci�n no cuenta el nulo."
      Vemos que se especifica que str apunta a una cadena.
      �Para qu� puede servir pasar la referencia a un solo car�cter o n�mero?
      Veremos m�s adelante que, al acceder a trav�s de la direcci�n de una
      variable, podemos cambiar el valor de �sta.

 */

int mi_strlen(char* str);
int calculaLongitudCadena(char str[]);

/* mi_strlen calcula la longitud de una cadena de caracteres haciendo uso
de una funci�n ya existente: decimos que "encapsula" a dicha funci�n o que
"delega" el c�lculo en la funci�n strlen(). M�s avanzado el curso comentaremos
si esto puede ser de alguna utilidad... o no.
*/

int mi_strlen(char* str)
{
   int longitud;
   longitud = strlen( str );
   return longitud;
}

/* calculaLongitudCadena calcula por s� misma la longitud de una cadena.
La declaraci�n del par�metro str: char str[], es equivalente a la anterior:
char* str. En ambos casos se espera la direcci�n del primer elemento del array
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
     lo importante es que siempre pasemos la direcci�n del primer elemento
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
 
   /* Ahora pedimos al usuario una palabra y comprobamos si est� contenida
      en la variable cadena1. Ver el prototipo y la descripci�n de la funci�n
      strstr() m�s  abajo */

   printf("Introduce una palabra: ");
   scanf("%s", palabra);

   pChar = strstr(cadena1, palabra);
   if (pChar != NULL)
   {
      printf("La palabra '%s' se encuentra dentro de la cadena '%s'\n",palabra,
                                                                       cadena1);
      printf("El car�cter apuntado por pChar es: %c \n", *pChar);
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
   cadena apuntada por str1. Devuelve un puntero a la primera aparici�n dentro
   de la cadena apuntada por str1. El car�cter nulo final de str2 no se compara.
   Devuelve un puntero nulo si no hay coincidencia


*/

/* INFORMACI�N SOBRE FUNCIONES PARA MANEJO DE CADENAS.
  (Puede ampliarse la informaci�n utilizando el manual de Unix:
     Ejemplo:     man strlen
   )
Todas las funciones para manejo de cadenas tienen su prototipo en: 
#include <string.h>

Se muestra a continuaci�n los prototipos de algunas de las funciones,
acompa�adas de una breve descripci�n:

char *strcpy(const char *dest, const char *orig);
  Copia la cadena de caracteres apuntada por orig (incluyendo el car�cter
  terminador '\0') al vector apuntado por dest. Las cadenas no deben solaparse,
  y la de destino, debe ser suficientemente grande como para alojar la copia.

int strcmp(const char *s1, const char *s2);
  Compara las dos cadenas de caracteres s1 y s2. Devuelve un entero menor,
  igual o mayor que cero si se encuentra que s1 es, respectivamente, menor que,
  igual a, o mayor que s2.

char *strcat(char *str1, char *str2);
   Concatena una copia de str2 a str1 y a�ade un nulo al final. El car�cter
   nulo que ten�a str1 se sobreescribe con el primer car�cter de str2. La
   funci�n devuleve un puntero a str1. str1 debe ser suficientemente grande
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
  versi�n de strcmp() que ignora si son may�sculas o min�sculas .

strncasecmp(const char *s1, const char *s2, int n);
  versi�n insensible a may�sculas o min�sculas de strncmp() que compara los
  primeros n caracteres de s1.

char *strchr(const char *s, int c);
  Devuelve un puntero a la primera ocurrencia del car�cter c en la cadena
  de caracteres s.

char *strrchr(const char *s, int c);
  Encuentra la �ltima ocurrencia del caracter c en la cadena.

char *strstr(const char *s1, const char *s2);
  Localiza la primera ocurrencia de la cadena s2 en la cadena s1.

char *strpbrk(const char *s1, const char *s2);
  Regresa un apuntador a la primera ocurrencia en la cadena s1 de cualquier
  car�cter de la cadena s2, o un apuntador nulo si no hay un caracter de s2
  que exista en s1.

*/