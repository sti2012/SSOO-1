/* EJERCICIO 25.2 
     Explica razonadamente por qu� en la funci�n scanf(), utilizamos a veces
     operador '&' precediendo a la variable donde se va a guardar lo que leemos
     por teclado. �Por qu� no se utiliza el '&' cuando pasamos a dicha funci�n
     arrays?
*/

#include <stdio.h>
#include <string.h>

/*  PROGRAMA 25: PUNTEROS Y PASO DE PAR�METROS A FUNCIONES (Segunda Parte)

    OBJETIVOS: saber utilizar correctamente el paso de par�metros a funciones,
    sabiendo en qu� casos pueden modificarse las variables pasadas y en qu�
    casos no.
    
    Cuando se pasan par�metros a una funci�n, estos se copian en la pila del 
    programa. Si pasamos una variable que vale 7, el valor 7 se copiar�
    en la pila. Este valor ser� utilizado, como una variable local, en la
    funci�n llamada. Ejemplo: 
            ...
            int contador, resul;
            contador = 7;
            resul = doble(contador);
            ...
            // la funcion doble tiene el siguiente c�digo 
            int doble(int numero)
            {
                numero = numero*numero;
                return numero;
            }
    El valor copiado en la pila es asignado a la variable 'numero'. Aunque en
    la funci�n se modifique, lo �nico que cambia es el valor que se copi�, no
    el de la variable original ('contador').
    
    Los valores que se pasan como par�metros se copian en la pila y, al volver
    de la funci�n, tales copias dejan de existir.
    
    Si queremos que una funci�n modifique el valor de variables que est�n fuera
    de dicha funci�n debemos pasar como par�metro una referencia a la variable:
    su direcci�n. A trav�s de la direcci�n de memoria de la variable pasada,
    la funci�n puede acceder al contenido de dicha variable y modificarlo.
    
    Para los dos casos mencionados se utilizan los siguientes t�rminos:
    - Paso de par�metros por valor: se copia el valor de las variables. Las 
      variables no son modificadas.
    - Paso de par�metros por referencia: se pasa la direcci�n de la variable y
      esta puede ser modificada.
      
      F�jate que siempre se hace una copia de algo, pero en el caso de paso
      por referencia, lo que se copia en la pila es una direcci�n...
      
      Como las referencias son direcciones, en el prototipo de las funciones
      aparecer�n punteros. Estudia detenidamente los prototipos de las funciones
      y su funcionamiento en el siguiente programa...
    
 */

/* swap = intercambio */

void noSwap(int a, int b);
void swap(int* a, int* b);
void rellenaCadena(char*  cadena);

void noSwap(int a, int b)
{
  int aux;
  printf("Estamos en noSwap\n");
  printf("\ta vale: %d. b vale: %d \n", a, b );
  aux = a;
  a = b;
  b = aux;
  printf("\tTras el cambio:\n");
  printf("\ta vale: %d. b vale: %d \n", a, b );
  printf("Salimos de noSwap\n");
}


void swap(int* a, int* b)
{
     int aux;
     printf("Estamos en swap\n");
     printf("\t*a vale: %d. *b vale: %d \n", *a, *b );
     aux = *a;
     *a = *b;
     *b = aux;
     printf("\tTras el cambio:\n");
     printf("\t*a vale: %d. *b vale: %d \n", *a, *b );
     printf("Salimos de swap\n");
}

void rellenaCadena(char*  cadena)
{
     strcpy(cadena, "Esto se copia...");
     
}

int main()
{
    int x, y;
    char vector[20];
    
    x = 5;
    y = 20;
    
    printf("x vale: %d. y vale: %d \n", x, y );

    printf("\nLlamada a noSwap\n");
    noSwap(x, y );
    printf("x vale: %d. y vale: %d \n", x, y );
    
    printf("\nLlamada a swap\n");
    swap(&x, &y );  /* importante: pasamos las direcciones de x e y */
    printf("x vale: %d. y vale: %d \n", x, y );
    
    
    rellenaCadena(vector);
    printf("\nLa cadena contiene ahora: %s \n", vector);
    
    system("pause");
       
}

/* RESULTADO DE LA EJECUCI�N: 
x vale: 5. y vale: 20 

Llamada a noSwap
Estamos en noSwap
	a vale: 5. b vale: 20 
	Tras el cambio:
	a vale: 20. b vale: 5 
Salimos de noSwap
x vale: 5. y vale: 20 

Llamada a swap
Estamos en swap
	*a vale: 5. *b vale: 20 
	Tras el cambio:
	*a vale: 20. *b vale: 5 
Salimos de swap
x vale: 20. y vale: 5 

La cadena contiene ahora: Esto se copia... 
*/