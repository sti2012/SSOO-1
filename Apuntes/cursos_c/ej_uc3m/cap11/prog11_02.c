/*
 * Programa:    prog_11_02
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 11:
 *              Programa de ejemplo de uso de una pila.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *  Definici�n de la pila de enteros
 */
typedef int TipoElemento;

struct ElementoPila 
{
  TipoElemento          elemento;
  struct ElementoPila * siguiente;
};

typedef struct ElementoPila * TipoPila;


/*
 *  Definici�n de las operaciones 
 *  con una pila
 */
void crearVacia (TipoPila *pila)
{
  (*pila)=NULL;
}

int esVacia (TipoPila pila)
{
  return (NULL==pila);
}

TipoElemento cima (TipoPila pila)
{
  return pila->elemento;
}

int insertar (TipoPila *pila, TipoElemento elemento)
{
    struct ElementoPila *eltoPila;

    /* crea una duplica de 'elemento' */
    eltoPila=malloc(sizeof(struct ElementoPila));
    if (NULL==eltoPila) {
      perror("malloc:"); 
      return (0);
    }
    eltoPila->elemento=elemento;

    /* inserta la duplica en la pila */
    eltoPila->siguiente=(*pila);
    (*pila)=eltoPila;

    return (1);
}

int borrar (TipoPila *pila, TipoElemento *elemento)
{
    struct ElementoPila *eltoPila;

    /* extraer de la pila */
    eltoPila=(*pila);
    (*pila)=eltoPila->siguiente;

    /* copiar y liberar memoria */
    (*elemento)=eltoPila->elemento;
    free(eltoPila);

    return (1);
}

void vaciar (TipoPila *pila)
{
    TipoElemento elemento;

    while(!esVacia((*pila))) {
         borrar(pila,&elemento);
    }
}


/*
 *  Programa principal
 */
int main (void)
{
    TipoPila pila;
    int i;

    /* iniciar la pila */
    crearVacia(&pila);

    /* almacenar valores */
    for (i=0; i<10; i++) {
         insertar(&pila,i);
         printf("insertado %d\n",i);
    }

    /* extraer los valores almacenados */
    while(!esVacia(pila)) {
         borrar(&pila,&i);
         printf("borrado %d\n",i);
    }

    return (0);
}

