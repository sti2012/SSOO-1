/*
*ejemplox_81.c
*/
#include <stdio.h>
#include <stdlib.h>

// Definición de tipos
struct Elemento {
   int   columna;
   int   fila;
   float valor;
};

struct ElementoLista {
   struct Elemento elemento;
   struct ElementoLista *elementoSiguiente;
   struct ElementoLista *elementoAnterior;
};

typedef struct ElementoLista* MatrizDispersa;

// Funciones de utilidad
void imprimirElemento(const struct Elemento elemento) {
   printf("(%d,%d)=%f\n",
      elemento.fila,elemento.columna,elemento.valor);
}

void imprimirMatrizDispersa(const MatrizDispersa matriz) {
   MatrizDispersa restoMatriz=(MatrizDispersa) matriz;
   while (restoMatriz!=NULL) {
      imprimirElemento(restoMatriz->elemento);
      restoMatriz=restoMatriz->elementoSiguiente;
   }
}

struct ElementoLista* ultimoElementoMatriz(const MatrizDispersa matriz) {
   MatrizDispersa ultimoElemento=matriz;
   if (matriz==NULL) return NULL;
   while (ultimoElemento->elementoSiguiente!=NULL)
      ultimoElemento=ultimoElemento->elementoSiguiente;
   return ultimoElemento;
}

struct ElementoLista* findElemento(const MatrizDispersa matriz,
   int fila, int columna) {
   MatrizDispersa elementoActual=matriz;
   while (elementoActual!=NULL) {
      if (elementoActual->elemento.fila==fila &&
          elementoActual->elemento.columna==columna) {
          return elementoActual;
      } else {
          elementoActual=elementoActual->elementoSiguiente;
      }
   }
   return NULL;
}

MatrizDispersa appendElemento(const MatrizDispersa matriz,
   const struct Elemento* elemento) {
   struct ElementoLista* nuevoElemento=NULL;

   nuevoElemento=(struct ElementoLista*) malloc(
      sizeof(struct ElementoLista));
   nuevoElemento->elemento=*elemento;
   nuevoElemento->elementoAnterior=ultimoElementoMatriz(matriz);
   nuevoElemento->elementoSiguiente=NULL;
   
   if (matriz==NULL) return nuevoElemento;
   else {
      ultimoElementoMatriz(matriz)->elementoSiguiente=nuevoElemento;
      return matriz;
   }
}

MatrizDispersa deleteElemento(const MatrizDispersa matriz,
   int fila, int columna) {
   struct ElementoLista* elementoParaBorrar=
      findElemento(matriz,fila,columna);
   if (elementoParaBorrar==NULL) return matriz;
   if (elementoParaBorrar!=matriz) {
      if (elementoParaBorrar->elementoAnterior!=NULL)
         elementoParaBorrar->elementoAnterior->elementoSiguiente=
            elementoParaBorrar->elementoSiguiente;
      if (elementoParaBorrar->elementoSiguiente!=NULL)
         elementoParaBorrar->elementoSiguiente->elementoAnterior=
            elementoParaBorrar->elementoAnterior;
      free(elementoParaBorrar);
      return matriz;
   } else {
      MatrizDispersa restoMatriz=elementoParaBorrar->elementoSiguiente;
      free(elementoParaBorrar);
      return restoMatriz;
   }
}

int main() {
   MatrizDispersa M=NULL;
   struct Elemento e1={1,1,1.0};
   struct Elemento e2={100,100,1.0};
   
   M=appendElemento(M,&e1);
   M=appendElemento(M,&e2);
   printf("Añadidos los elementos (1,1) y (100,100)\n");
   imprimirMatrizDispersa(M);

   M=deleteElemento(M,2,2);
   printf("Debe ser igual que anteriormente puesto que (2,2) no existe\n");
   imprimirMatrizDispersa(M);

   M=deleteElemento(M,100,100);
   printf("Eliminamos (100,100)\n");
   imprimirMatrizDispersa(M);
   
   e1.fila=100;
   e1.columna=100;
   e1.valor=2.0;
   M=appendElemento(M,&e1);
   printf("Añadido (100,100) como 2.0\n");
   imprimirMatrizDispersa(M);

   system("PAUSE");	
   return 0;
}
