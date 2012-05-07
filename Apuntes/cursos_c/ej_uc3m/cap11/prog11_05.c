/*
 * Programa:    prog_11_05
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 11:
 *              Programa de ejemplo de uso de un arbol binario.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *  Definición del arbol binario de enteros 
 */
typedef int TipoElemento;
typedef struct ElementoArbol * TipoArbol;

struct ElementoArbol
{
  TipoElemento    elemento;
  TipoArbol       hijoIzq;
  TipoArbol       hijoDer;
};


/*
 *  Definición de las operaciones 
 *  con un arbol
 */
void crearVacio (TipoArbol *arbol)
{
        (*arbol)=NULL;
}

int esVacio (TipoArbol arbol)
{
        return (NULL==arbol);
}

TipoElemento  raiz (TipoArbol arbol)
{
        return arbol->elemento;
}

TipoArbol      hijoIzquierdo   (TipoArbol arbol)
{
        return arbol->hijoIzq;
}

TipoArbol      hijoDerecho   (TipoArbol arbol)
{
        return arbol->hijoDer;
}
TipoArbol construir (TipoArbol hijoIzq, TipoElemento raiz, TipoArbol hijoDer)
{
    struct ElementoArbol *eltoArbol;

    /* reserva memoria */
    eltoArbol=malloc(sizeof(struct ElementoArbol));
    if (NULL==eltoArbol) {
      perror("malloc:"); 
      return (NULL);
    }

    /* valores para el elemento del arbol */
    eltoArbol->elemento=raiz;
    eltoArbol->hijoIzq=hijoIzq;
    eltoArbol->hijoDer=hijoDer;
    
    return (eltoArbol);
}



/*
 * Programa principal
 */
int main(void)
{
    TipoArbol      arbol, arbol1, arbol2, hijoIzq, hijoDer;
    TipoElemento   elemento;


    /* Crear los arboles vacios  */
    crearVacio(&hijoIzq);
    crearVacio(&hijoDer);

    /* Construir un arbol con un elemento */
    arbol1 = construir (hijoIzq,1,hijoDer);
    

    /* Crear los arboles vacios  */
    crearVacio(&hijoIzq);
    crearVacio(&hijoDer);

    /* Construir otro arbol con un elemento */
    arbol2 = construir (hijoIzq,9,hijoDer);

    /* Construir un arbol con los otros arboles como ramas */
    arbol = construir (arbol1,5,arbol2);

    /* mostrar la raiz del arbol */
    elemento = raiz(arbol);
    printf ("La raiz del árbol es: %d\n",elemento);

    /* mostrar la raiz del subarbol izquierdo */
    hijoIzq = hijoIzquierdo(arbol);
    elemento = raiz(hijoIzq);
    printf ("La raiz del subárbol izquierdo es: %d\n",elemento);

    return (0);
}

