/*
*ejemplox_82.c
*/
#include <stdio.h>
#include <stdlib.h>

// Definición de tipos
typedef struct {
   char nombre[100];
   int  cantidad;
} Articulo;

struct ArticuloLista {
   Articulo articulo;
   struct ArticuloLista *articuloSiguiente;
   struct ArticuloLista *articuloAnterior;
};

typedef struct ArticuloLista* Almacen;

// Funciones de utilidad
void imprimirArticulo(const Articulo articulo) {
   printf("Articulo=%s, Cantidad=%d\n",
      articulo.nombre,articulo.cantidad);
}

void imprimirAlmacen(const Almacen almacen) {
   Almacen restoAlmacen=almacen;
   printf("Estado actual del almacén\n");
   while (restoAlmacen!=NULL) {
      imprimirArticulo(restoAlmacen->articulo);
      restoAlmacen=restoAlmacen->articuloSiguiente;
   }
   printf("\n");
}

struct ArticuloLista* ultimoArticuloAlmacen(const Almacen almacen) {
   Almacen ultimoArticulo=almacen;
   if (almacen==NULL) return NULL;
   while (ultimoArticulo->articuloSiguiente!=NULL)
      ultimoArticulo=ultimoArticulo->articuloSiguiente;
   return ultimoArticulo;
}

struct ArticuloLista* findArticulo(const Almacen almacen,
   const char *nombre) {
   Almacen articuloActual=almacen;
   while (articuloActual!=NULL) {
      if (strcmp(articuloActual->articulo.nombre,nombre)==0) {
          return articuloActual;
      } else {
          articuloActual=articuloActual->articuloSiguiente;
      }
   }
   return NULL;
}

Almacen appendArticulo(const Almacen almacen, const char *nombre) {
   struct ArticuloLista* nuevoArticulo=findArticulo(almacen,nombre);
   if (nuevoArticulo==NULL || almacen==NULL) {
      nuevoArticulo=(struct ArticuloLista*) malloc(
         sizeof(struct ArticuloLista));
      strcpy(nuevoArticulo->articulo.nombre,nombre);
      nuevoArticulo->articulo.cantidad=1;
      nuevoArticulo->articuloAnterior=ultimoArticuloAlmacen(almacen);
      nuevoArticulo->articuloSiguiente=NULL;
      if (almacen==NULL) return nuevoArticulo;
      else {
         ultimoArticuloAlmacen(almacen)->articuloSiguiente=nuevoArticulo;
         return almacen;
      }
   } else {
      nuevoArticulo->articulo.cantidad++;
      return almacen;
   }
}

Almacen deleteArticulo(const Almacen almacen, const char *nombre) {
   struct ArticuloLista* articuloParaBorrar=
      findArticulo(almacen,nombre);
   if (articuloParaBorrar==NULL) return almacen;
   articuloParaBorrar->articulo.cantidad--;
   if (articuloParaBorrar->articulo.cantidad==0) {
      if (articuloParaBorrar!=almacen) {
         if (articuloParaBorrar->articuloAnterior!=NULL)
            articuloParaBorrar->articuloAnterior->articuloSiguiente=
               articuloParaBorrar->articuloSiguiente;
         if (articuloParaBorrar->articuloSiguiente!=NULL)
            articuloParaBorrar->articuloSiguiente->articuloAnterior=
               articuloParaBorrar->articuloAnterior;
         free(articuloParaBorrar);
         return almacen;
      } else {
         Almacen restoAlmacen=articuloParaBorrar->articuloSiguiente;
         free(articuloParaBorrar);
         return restoAlmacen;
      }
   }
   return almacen;
}

Almacen entradaArticuloEnAlmacen(const Almacen almacen) {
   char nombre[100]="";
   printf("Introduzca articulo que entra:");
   scanf("%s",nombre);
   return appendArticulo(almacen,nombre);
}

Almacen salidaArticuloDeAlmacen(const Almacen almacen) {
   char nombre[100]="";
   printf("Introduzca articulo que sale:");
   scanf("%s",nombre);
   return deleteArticulo(almacen,nombre);
}

int main() {
   enum Opcion {Entrada=1, Salida, Terminar} opcion;
   Almacen almacen=NULL;
   do {
      printf("1.- Entrada en almacen\n"
             "2.- Salida  de almacen\n"
             "3.- Terminar programa\n"
             "Opción:");
      scanf("%d",&opcion);
      switch (opcion) {
         case Entrada:
              almacen=entradaArticuloEnAlmacen(almacen);
              imprimirAlmacen(almacen);
              break;
         case Salida:
              almacen=salidaArticuloDeAlmacen(almacen);
              imprimirAlmacen(almacen);
              break;
      }
   } while (opcion!=Terminar);
   system("PAUSE");	
   return 0;
}
