/*
 * Programa: agenda
 * Modulo  : menu_direcciones
 * Fichero : menu_direcciones.h
 */

/*
 * FICHEROS INCLUDES
 */
#include "menu_direcciones.h"

/*
 * FUNCIONES PRIVADAS
 */

/*
 * Función listarMenuDir()
 *
 * Parámetros de entrada:
 *      ListaDir * datos: Lista de direcciones global de la agenda
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Muestra la lista de direcciones     
 */
void listarMenuDir (ListaDir *datos)
{
    int i, num, ret;
    char *nombre, *direccion, *telefono;

    num=numeroDir(datos);
    if (0 == num) {
        printf("<vacía>\n");
        return;
    }

    for (i=0; i<num; i++) {
        ret = consultarDir(datos,i,&nombre, &direccion, &telefono);
        if (0 == ret) {
            printf("[%2d] Nom: %s     Dir: %s     Tel: %s\n",
                                        i,nombre,direccion,telefono);
        }
    }
    printf("\n");
}

/*
 * Función insertarMenuDir()
 *
 * Parámetros de entrada:
 *      ListaDir * datos: Lista de direcciones global de la agenda
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      inserta una direccion en la lista de direcciones     
 */
void insertarMenuDir (ListaDir *datos)
{
    char nombre[TAM_MAX];
    char direccion[TAM_MAX];
    char telefono[TAM_MAX];
    char *ret;

    /* introducir el nombre */
    printf("Introduzca el nombre:\n");
    fflush(stdout);
    do {
        ret=fgets(nombre,TAM_MAX,stdin);
        if ('\n' == nombre[strlen(nombre)-1]) {
            nombre[strlen(nombre)-1]='\0';
        }
    } while ( (!strcmp(nombre,"\n")) || (!strcmp(nombre,"")) ) ;
    printf("\n");

    /* introducir la direccion */
    printf("Introduzca la direccion:\n");
    fflush(stdout);
    do {
        ret=fgets(direccion,TAM_MAX,stdin);
        if ('\n' == direccion[strlen(direccion)-1]) {
            direccion[strlen(direccion)-1]='\0';
        }
    } while ( (!strcmp(direccion,"\n")) || (!strcmp(direccion,"")) ) ;
    printf("\n");

    /* introducir el telefono */
    printf("Introduzca el telefono:\n");
    fflush(stdout);
    do {
        ret=fgets(telefono,TAM_MAX,stdin);
        if ('\n' == telefono[strlen(telefono)-1]) {
            telefono[strlen(telefono)-1]='\0';
        }
    } while ( (!strcmp(telefono,"\n")) || (!strcmp(telefono,"")) ) ;
    printf("\n");

    insertarDir(datos,nombre,direccion,telefono);
    printf("\n");
}

/*
 * Función consultarMenuDir()
 *
 * Parámetros de entrada:
 *      ListaDir * datos: Lista de direcciones global de la agenda
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Pregunta el nombre de una direccion de la lista y la muestra 
 *      por pantalla     
 */
void consultarMenuDir (ListaDir *datos)
{
    char *ret;
    int aux,pos;
    char nombre[TAM_MAX]; 
    char *direccion, *telefono;

    printf("Introduzca el nombre a consultar: ");
    fflush(stdout);
    do {
        ret=fgets(nombre,TAM_MAX,stdin);
        if ('\n' == nombre[strlen(nombre)-1]) {
            nombre[strlen(nombre)-1]='\0';
        }
    } while ( (!strcmp(nombre,"\n")) || (!strcmp(nombre,"")) ) ;

    aux = consultarDirPorNombre(datos,nombre,&pos,&direccion,&telefono);
    if (0 == aux) {
        printf("[%2d] Nom: %s     Dir: %s     Tel: %s\n",
                                              pos,nombre,direccion,telefono);
    }
    printf("\n");
}

/*
 * Función borrarMenuDir()
 *
 * Parámetros de entrada:
 *      ListaDir * datos: Lista de direcciones global de la agenda
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      borra una direccion de la lista de direcciones     
 */
void borrarMenuDir (ListaDir *datos)
{
    char *ret;
    char nombre[TAM_MAX];

    printf("Introduzca el nombre a borrar: ");
    fflush(stdout);
    do {
        ret=fgets(nombre,TAM_MAX,stdin);
        if ('\n' == nombre[strlen(nombre)-1]) {
            nombre[strlen(nombre)-1]='\0';
        }
    } while ( (!strcmp(nombre,"\n")) || (!strcmp(nombre,"")) ) ;

    borrarDir(datos,nombre);
    printf("\n");
}

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función menuDir()
 */
void menuDir (ListaDir *datos)
{
    int opcion;
    int final = 0;

    do{         
        /* Mostrar el menu de opciones */
        opcion = -1;
        printf("\n");
        printf("Direcciones\n");
        printf("-----\n");
        printf("\n");
        printf(" 1.- Listar las direcciones\n");
        printf(" 2.- Insertar una direccion\n");
        printf(" 3.- Borrar una direccion\n");
        printf(" 4.- Consultar una direccion\n");
        printf(" 0.- Volver al menú anterior\n\n");
        printf("\n");
        printf("\n");
        printf(" Introduzca su opción: ");
        fflush(stdout);
        scanf ("%d",&opcion);

        switch(opcion){
        case 1:
            /* Listar las direcciones */
            listarMenuDir(datos);
            break;
        case 2: 
            /* Insertar una direccion */
            insertarMenuDir(datos);
            break;
        case 3:
            /* Borrar una direccion */
            borrarMenuDir(datos);
            break;
        case 4:
            /* Consultar una direccion */
            consultarMenuDir(datos);
            break;
        case 0:
            /* Salir del menu */
            final=1;
            break;
        default:
            /* la opción elegida no esta dentro de las indicadas */
            printf("La opcion elegida es incorrecta\n\n");
        }  
   }while (0 == final);  
}

