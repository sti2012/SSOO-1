/*
 * Programa: agenda
 * Modulo  : menu_notas
 * Fichero : menu_notas.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "menu_notas.h"

/*
 * FUNCIONES PRIVADAS
 */

/*
 * Funci�n listarMenuNotas()
 *
 * Par�metros de entrada:
 *      ListaNotas * notas: Lista de notas global de la agenda
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      Muestra la lista de notas     
 */
void listarMenuNotas (ListaNotas *notas)
{
    int i, n;

    n=numeroNotas(notas);
    if (n==0) {
        printf("<vac�a>\n");
        return;
    }

    for (i=1; i<=n; i++) {
        printf("[%d] %s\n",i,consultarNotas(notas,i));
    }
    printf("\n");
}

/*
 * Funci�n insertarMenuNotas()
 *
 * Par�metros de entrada:
 *      ListaNotas * notas: Lista de notas global de la agenda
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      inserta una nota en la lista de notas     
 */
void insertarMenuNotas (ListaNotas *notas)
{
    char nota[NOTA_MAX];
    char *ret;

    printf("Introduzca el contenido de la nota:\n");
    fflush(stdout);
    do {
        ret=fgets(nota,NOTA_MAX,stdin);
        if ('\n' == nota[strlen(nota)-1]) {
            nota[strlen(nota)-1]='\0';
        }
    } while ( (!strcmp(nota,"\n")) || (!strcmp(nota,"")) ) ;

    insertarNotas(notas,nota);
    printf("\n");
}

/*
 * Funci�n borrarMenuNotas()
 *
 * Par�metros de entrada:
 *      ListaNotas * notas: Lista de notas global de la agenda
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      borra una nota de la lista de notas     
 */
void borrarMenuNotas (ListaNotas *notas)
{
    int indice;

    printf("Introduzca la posici�n de la nota a borrar: ");
    fflush(stdout);
    scanf("%d",&indice);
    borrarNotas(notas,indice);
    printf("\n");
}
 
/*
 * FUNCIONES P�BLICAS
 */

/*
 * Funci�n menuNotas()
 */
void menuNotas (ListaNotas *notas)
{
    int opcion;
    int final = 0;

    do{         
        /* Mostrar el menu de opciones */
        opcion = -1;
        printf("\n");
        printf("Notas\n");
        printf("-----\n");
        printf("\n");
        printf(" 1.- Listar las notas\n");
        printf(" 2.- Insertar una nota\n");
        printf(" 3.- Borrar una nota\n");
        printf(" 0.- Volver al men� anterior\n\n");
        printf("\n");
        printf("\n");
        printf(" Introduzca su opci�n: ");
        fflush(stdout);
        scanf ("%d",&opcion);

        switch(opcion){
        case 1:
            /* Listar las notas */
            listarMenuNotas(notas);
            break;
        case 2: 
            /* Insertar una nota */
            insertarMenuNotas(notas);
            break;
        case 3:
            /* Borrar una nota */
            borrarMenuNotas(notas);
            break;
        case 0:
            /* Salir del menu */
            final=1;
            break;
        default:
            /* la opci�n elegida no esta dentro de las indicadas */
            printf("La opcion elegida es incorrecta\n\n");
        }  
   }while (0 == final);  
}

