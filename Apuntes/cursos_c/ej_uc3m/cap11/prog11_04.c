
/*
 *  Programa prog11_04
 *  Ejemplo de uso de una lista.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *  Definición del tipo 'struct Cliente'
 *  junto con una lista de este tipo de elementos
 */
typedef struct Cliente TipoElemento;
typedef struct ElementoLista * TipoLista;

struct Cliente {
  char nombre[1001];
};

struct ElementoLista
{
  TipoElemento   elemento;
  TipoLista       resto ;
};


/*
 *  Definición de las operaciones 
 *  con una lista
 */
void crearVacia (TipoLista *lista)
{
        (*lista)=NULL;
}

int esVacia (TipoLista lista)
{
        return (NULL==lista);
}

TipoElemento * primero (TipoLista lista)
{
        return &(lista->elemento);
}

TipoLista      resto   (TipoLista lista)
{
        return lista->resto;
}

void modificar (TipoLista *lista, TipoElemento elemento)
{
        (*lista)->elemento=elemento;
}

int insertar (TipoLista *lista, TipoElemento  elemento)
{
    struct ElementoLista *eltoLista;

    /* reserva memoria */
    eltoLista=malloc(sizeof(struct ElementoLista));
    if (NULL==eltoLista) {
      perror("malloc:"); 
      return (0);
    }

    /* valores para el elemento de la lista */
    eltoLista->elemento=elemento;
    eltoLista->resto=NULL;

    /* inserta en la lista */
    eltoLista->resto=(*lista);
    (*lista)=eltoLista;

    return (1);
}

void borrar (TipoLista *lista, TipoElemento elemento)
{
    struct ElementoLista *eltoLista;
    struct ElementoLista *eltoSiguiente;

    /* lista vacia */
    if (NULL==(*lista)) {
	    return;
    }

    /* primero de la lista */
    if (strcmp(elemento.nombre, (*lista)->elemento.nombre) == 0){
            eltoLista=(*lista);
	    (*lista)=(*lista)->resto;
	    free(eltoLista);
	    return;
    }

    /* en el resto de la lista */
    eltoLista=(*lista);
    eltoSiguiente=eltoLista->resto;
    while(NULL!=eltoSiguiente) {
            if (strcmp(elemento.nombre, eltoSiguiente->elemento.nombre) == 0) {
		    eltoLista->resto=eltoSiguiente->resto;
		    free(eltoSiguiente);
		    return;
	    }
            eltoLista=eltoSiguiente;
            eltoSiguiente=eltoLista->resto;
    }

    /* no está en la lista */
    return;
}


/*
 * Programa principal
 */
int main(void)
{
    char   *nombre[] = { "Rosa", "María", NULL };
    int     i;
    TipoLista      listaPeluqueria;
    TipoElemento  *cliente;


    /*  Dar valor a los miembros de la lista  */
    crearVacia(&listaPeluqueria);

    /*  Insertar clientes */
    printf("\n");
    for (i=0; NULL!=nombre[i]; i++) {

        cliente=malloc(sizeof(struct Cliente));
        if (NULL!=cliente) {
            strcpy(cliente->nombre,nombre[i]);
            insertar(&listaPeluqueria,*cliente);
            printf("ha llegado un cliente de nombre %s...\n",
                   nombre[i]);
        }

    }

    /*  Extraer clientes */
    printf("\n");
    while (!esVacia(listaPeluqueria)) {

        cliente=primero(listaPeluqueria);
        printf("se sirve al cliente de nombre %s...\n",
               cliente->nombre);
        borrar(&listaPeluqueria,*cliente);

    }

    return (0);
}

