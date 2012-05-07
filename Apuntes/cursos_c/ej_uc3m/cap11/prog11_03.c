
/*
 *  Programa prog11_03
 *  La cola de la peluquería (segunda parte).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *  Definición del tipo 'struct Cliente'
 *  junto con la cola de este tipo de elementos
 */
struct Cliente {
  char nombre[1001];
};

  typedef struct Cliente TipoElemento;

struct ElementoCola {
  TipoElemento          elemento;
  struct ElementoCola * siguiente;
};

struct Cola {
  struct ElementoCola *ultimo;
  struct ElementoCola *primero;
};

  typedef struct Cola    TipoCola;


/*
 *  Definición de la cola junto
 *  con sus operaciones
 */
void crearVacia (TipoCola * cola)
{
    cola->primero=NULL;
    cola->ultimo=NULL;
}

int esVacia (TipoCola cola)
{
    return ( (NULL==cola.primero) && (NULL==cola.ultimo) );
}

TipoElemento * primero (TipoCola cola)
{
    if (esVacia(cola)) {
        return NULL;
    }

    return (&(cola.primero->elemento));		
}

TipoCola * insertar (TipoCola * cola, TipoElemento elto)
{
    struct ElementoCola * individuo;

    /*  reserva de memoria  */
    individuo=malloc(sizeof(struct ElementoCola));
    if (NULL==individuo) {
        perror("malloc:");
        return NULL;
    }

    /*  valores para el nuevo elemento  */
    /*
    memcpy((void *) &(individuo->elemento), (const void *) &elto, sizeof(TipoElemento));  
    */
    individuo->elemento = elto;
    individuo->siguiente=NULL;

    /*  dar la vez en la cola  */
    if (esVacia(*cola)) {
        cola->primero=individuo;
        cola->ultimo=individuo;

    } else {
        (cola->ultimo)->siguiente=individuo;
        cola->ultimo=individuo;
    }

    return cola;
}

void quitar (TipoCola *cola)
{
    struct ElementoCola * individuo;

    if (! esVacia(*cola)) {

        /*  salir de la cola  */
        individuo=cola->primero;
        cola->primero=individuo->siguiente;
        if (cola->ultimo==individuo) {
            cola->ultimo=NULL;
        }

        /*  liberar la memoria  */
        free(individuo);
    }
}


/*
 * Programa principal
 */
int main(void)
{
    char   *nombre[] = { "Rosa", "María", "Pepe", "Carlos", "Juan", "Antonio", NULL };
    int     i;
    TipoCola      colaPeluqueria;
    TipoElemento *cliente;


    /*  Dar valor a los miembros de la cola  */
    crearVacia(&colaPeluqueria);

    /*  Insertar clientes */
    printf("\n");
    for (i=0; NULL!=nombre[i]; i++) {

        cliente=malloc(sizeof(struct Cliente));
        if (NULL!=cliente) {
            strcpy(cliente->nombre,nombre[i]);
            insertar(&colaPeluqueria,*cliente);
            printf("ha llegado un cliente de nombre %s...\n",
                   nombre[i]);
        }

    }

    /*  Extraer clientes */
    printf("\n");
    cliente=primero(colaPeluqueria);
    while (NULL!=cliente) {

        printf("se sirve al cliente de nombre %s...\n",
               cliente->nombre);
        quitar(&colaPeluqueria);
        cliente=primero(colaPeluqueria);

    }

    return (0);
}

