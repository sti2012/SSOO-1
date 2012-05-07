/*
 * Programa:    prog_11_01
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 11:
 *              Programa de la cola de la peluquer�a.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *  Definici�n del tipo 'struct Cliente' junto con
 *  las operaciones 'establecerNombre' y 'consultarNombre'
 */
struct Cliente {
  char nombre[1001];
};

void establecerNombre ( struct Cliente * cliente, char *nombre )
{
    strcpy(cliente->nombre,nombre);
}

char * consultarNombre ( struct Cliente * cliente )
{
    return (char *)(cliente->nombre);
}


/*
 *  Definici�n de la cola mediante los
 *  tipos 'struct ElementoCola' y 'struct Cola' junto con
 *  las operaciones 'primeroEnCola', 'siguienteAlaCola' y
 *  'suTurno'
 */
struct ElementoCola {
  struct Cliente        cliente;
  struct ElementoCola * siguiente;
};

struct Cola {
  struct ElementoCola *ultimo;
  struct ElementoCola *primero;
};

struct ElementoCola * primeroEnCola ( struct Cola *cola, char *nombre )
{
    struct ElementoCola * individuo;

    /*  reserva de memoria  */
    individuo=malloc(sizeof(struct ElementoCola));
    if (NULL==individuo) {
        perror("malloc:");
        return NULL;
    }

    /*  valores para el nuevo elemento  */
    individuo->siguiente=NULL;
    establecerNombre(&(individuo->cliente),nombre);

    /*  inserci�n del primero  */
    cola->primero=individuo;
    cola->ultimo=individuo;

    return individuo;
}

struct ElementoCola * siguienteAlaCola ( struct Cola *cola, char *nombre )
{
    struct ElementoCola * individuo;

    /*  reserva de memoria  */
    individuo=malloc(sizeof(struct ElementoCola));
    if (NULL==individuo) {
        perror("malloc:");
        return NULL;
    }

    /*  valores para el nuevo elemento  */
    individuo->siguiente=NULL;
    establecerNombre(&(individuo->cliente),nombre);

    /*  dar la vez en la cola  */
    (cola->ultimo)->siguiente=individuo;
    cola->ultimo=individuo;

    return individuo;
}

void suTurno ( struct Cola *cola, char *nombre )
{
    struct ElementoCola * individuo;

    /*  si hay alguien, es su turno... */
    if (NULL!=cola->primero) {

        /*  salir de la cola  */
        individuo=cola->primero;
        cola->primero=individuo->siguiente;
        if (NULL == cola->primero) {
            cola->ultimo = NULL;
        }

        /*  copiar valores  */
        strcpy(nombre,consultarNombre(&(individuo->cliente)));

        /*  liberar la memoria  */
        free(individuo);
    }
}


/*
 * Programa principal
 */
int main(void)
{
    struct Cola colaPeluqueria;
    struct ElementoCola * individuo;
    char   nombre[1001];

    /*  Dar valor a los miembros de la cola  */
    colaPeluqueria.primero=NULL;
    colaPeluqueria.ultimo=NULL;

    /*  "Rosa" es la primera en la cola...  */
    individuo=primeroEnCola(&colaPeluqueria,"Rosa");
    printf("primera: %s\n",consultarNombre(&(individuo->cliente)));

    /*  "Mar�a" va detras...  */
    individuo=siguienteAlaCola(&colaPeluqueria,"Mar�a");
    printf("siguiente: %s\n",consultarNombre(&(individuo->cliente)));

    /*  El siguiente es "Jes�s"...  */
    individuo=siguienteAlaCola(&colaPeluqueria,"Jes�s");
    printf("siguiente: %s\n",consultarNombre(&(individuo->cliente)));

    /*  ... Y de la misma forma para el resto de clientes.  */
    printf("\n");

    /*  El turno primero toca a "Rosa"...  */
    suTurno(&colaPeluqueria,nombre);
    printf("el turno es de: %s\n",nombre);

    /*  Luego "Mar�a"...  */
    suTurno(&colaPeluqueria,nombre);
    printf("el turno es de: %s\n",nombre);

    /*  Luego "Jes�s"...  */
    suTurno(&colaPeluqueria,nombre);
    printf("el turno es de: %s\n",nombre);

    /*  ... Y de la misma forma para el resto de clientes.  */
    printf("\n");

    return (0);
}

