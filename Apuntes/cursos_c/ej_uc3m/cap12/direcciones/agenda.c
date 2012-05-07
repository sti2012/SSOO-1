/* 
 * Programa:    direcciones
 * Fichero:     agenda.c
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 12:
 *              Implementación del menu de direcciones
 */


#include "direcciones.h"

#define FICHERO "direcciones.agd" 

/*
 * Función listarDir
 */
void listarDir (const ListaDir *datos)
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
 * Función insertarDireccion
 */
void insertarDireccion (ListaDir *datos)
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
	} while ( (!strcmp(nombre,"\n")) || (!strcmp(nombre,"")) ) ;
	printf("\n");

        /* introducir la direccion */
	printf("Introduzca la direccion:\n");
	fflush(stdout);
	do {
		ret=fgets(direccion,TAM_MAX,stdin);
	} while ( (!strcmp(direccion,"\n")) || (!strcmp(direccion,"")) ) ;
        printf("\n");

        /* introducir el telefono */
	printf("Introduzca el telefono:\n");
	fflush(stdout);
	do {
		ret=fgets(telefono,TAM_MAX,stdin);
	} while ( (!strcmp(telefono,"\n")) || (!strcmp(telefono,"")) ) ;
        printf("\n");

	insertarDir(datos,nombre,direccion,telefono);
	printf("\n");
}

/*
 * Función consultarDireccion
 */
void consultarDireccion (ListaDir *datos)
{
	char *ret;
        int aux,pos;
        char nombre[TAM_MAX]; 
        char *direccion, *telefono;

	printf("Introduzca el nombre a consultar: ");
	fflush(stdout);
	do {
		ret=fgets(nombre,TAM_MAX,stdin);
	} while ( (!strcmp(nombre,"\n")) || (!strcmp(nombre,"")) ) ;

	aux = consultarPorNombre(datos,nombre,&pos,&direccion,&telefono);
        if (0 == aux) {
	    printf("[%2d] Nom: %s     Dir: %s     Tel: %s\n",
                                              pos,nombre,direccion,telefono);
        }
	printf("\n");
}

/*
 * Función borrarDireccion
 */
void borrarDireccion (ListaDir *datos)
{
	char *ret;
      	char nombre[TAM_MAX];

	printf("Introduzca el nombre a borrar: ");
	fflush(stdout);
	do {
		ret=fgets(nombre,TAM_MAX,stdin);
	} while ( (!strcmp(nombre,"\n")) || (!strcmp(nombre,"")) ) ;

	borrarDir(datos,nombre);
	printf("\n");
}

/*
 * Función main
 */
int main ()
{
    ListaDir datos;
    int opcion;
    int final = 0;

    datos=crearDir();
    leerArchivoDir(&datos,FICHERO);

    do{         
        /* Mostrar el menu de opciones */
        printf("\n");
        printf("Direcciones\n");
        printf("-----\n");
        printf("\n");
        printf(" 1.- Listar las direcciones\n");
        printf(" 2.- Insertar una direccion\n");
        printf(" 3.- Borrar una direccion\n");
        printf(" 4.- Consultar una direccion\n");
        printf(" 0.- Finalizar el programa\n\n");
        printf("\n");
        printf("\n");
        printf(" Introduzca su opción: ");
	fflush(stdout);
        scanf ("%d",&opcion);

        switch(opcion){
	    case 1:
                /* Listar las direcciones */
                listarDir(&datos);
    	        break;
	    case 2: 
                /* Insertar una direccion */
                insertarDireccion(&datos);
	        break;
	    case 3:
                /* Borrar una direccion */
                borrarDireccion(&datos);
                break;
	    case 4:
                /* Consultar una direccion */
                consultarDireccion(&datos);
                break;
	    case 0:
                /* Salir del menu */
                final=1;
                break;
	    default:
                /* la opción elegida no esta dentro de las indicadas */
	        printf("La opcion elegida es incorrecta\n\n");
        }  
        opcion = -1;
    }while (0 == final);  
    escribirArchivoDir(&datos,FICHERO);
    destruirDir(&datos);

    return(0);
}

