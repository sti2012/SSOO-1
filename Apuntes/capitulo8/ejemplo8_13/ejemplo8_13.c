//ejemplo8_13.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listin.h"

static int imprimeMenu();
static void imprimirListin ();
static int mostrarUsuario ();
static void modificar ();
static void introducirUsuario();
static void imprimirUsuario (const Ficha *usuario);
static void eliminarFichero ();

int main (){
    int opc = 0, salir = 0;
    char nombreFichero[200];
    printf ("Introduzca el nombre del fichero a abrir: ");
    scanf (" %s",nombreFichero);
    if (cargarListin(nombreFichero) == ERROR){
        printf("\nError de apertura de fichero");
        exit(-1);
    }
    while (salir != 1){
        switch (opc=imprimeMenu()){
        case 1:{
            introducirUsuario();
            break;
        }
        case 2:{
            mostrarUsuario();
            break;
        }
        case 3:{
            modificar();
            break;
        }
        case 4:{
            imprimirListin();
            break;
        }
        case 5:{
            eliminarFichero ();
            salir = 1;
            break;
        }
        case 6:{
            guardarListin();
            salir = 1;
        }
      }
    }
    return 0;
}

/*Imprime el men� y devuelve la opcion del usuario*/
static int imprimeMenu(){
    int c=0;
    char retorno;
    printf("------------------------ List�n telef�nico: ---------------------\n");
    printf("\n\t\t\t���������������������������\n");
    printf("\t\t\t�1.Introducir usuario        �\n");
    printf("\t\t\t�2.Buscar usuario            �\n");
    printf("\t\t\t�3.Modificar usuario         �\n");
    printf("\t\t\t�4.Imprimir list�n           �\n");
    printf("\t\t\t�5.Eliminar list�n y salir   �\n");
    printf("\t\t\t�6.Salir                     �\n");
    printf("\t\t\t����������������������������ͼ\n");
    do{
        printf("-------Introducir opcion [1-4]: ");
        scanf ("%i",&c);
        //eliminamos el retorno de carro del buffer
        scanf("%c",&retorno);
    }
    while (c<0 || c>6);
    system("cls");
    return c;
}

static void eliminarFichero (){
    char eliminar;

    printf ("�Est� seguro que desea eliminar el list�n al completo? s/n: ");
    scanf (" %c", & eliminar);
    if (eliminar == 's' || eliminar == 'S'){
        if (borrarListin () == ERROR){
            printf ("\n\nNo se puede eliminar el list�n\n");
        }
        else{
            printf ("\n\nList�n eliminado\n\n");
        }
    }
    system("pause");
}

/*Lista los usuarios controlando el llenado de pantalla*/
static void imprimirListin(){
    register int i=0,j, numeroRegistros;
    numeroRegistros = obtenerNumeroRegistros();
    printf("\n--------------------- List�n telef�nico: ---------------------\n");
    for (j=0; j<numeroRegistros ; ++j){
        if (i==4){
            i=1;
            printf ("\n\n");
            system("pause");
            system("cls");
            printf("\n--------------------- List�n telef�nico ---------------------\n");
        }
        else{
            ++i;
        }
        Ficha usuario = buscarUsuario (j);
        imprimirUsuario(&usuario);
    }
    printf ("\n\n");
    system("pause");
    system("cls");
}

/*Pide un nombre de usuario y lo busca en el listin.
Devuelve la clave del usuario que ha visualizado.*/
static int mostrarUsuario (){
    int clave;
    register int i;
    printf("\n\n\n\t Introduce la clave: ");
    scanf ("%d", &clave);
    printf("\n");
    Ficha usuario = buscarUsuario (clave);
    if (usuario.clave == ERROR){
        printf ("El usuario no se encuentra\n");
    }
    else{
        imprimirUsuario(&usuario);
    }
    return usuario.clave;
}

/*Comprueba si hay espacio en el array para un nuevo registro
y, si lo hay, pide los datos*/

static void introducirUsuario(){
    char cad[255];
    Ficha usuario;

    printf("Introduce el nombre: ");
    gets(cad);
    strcpy(usuario.nombre,cad);
    printf("Introduce la direcci�n: ");
    gets(cad);
    strcpy(usuario.direccion,cad);
    printf("Introduce el tel�fono: ");
    gets(cad);
    strcpy(usuario.telefono,cad);
    printf ("El usuario ha sido introducido con �xito\n");
    printf ("Su clave es: %d\n", anhadirUsuario(&usuario));
    system("pause");
    system("cls");
}

static void modificar (){
    int clave;
    char cad[255];
    Ficha usuario;

    clave = mostrarUsuario ();
    if (clave == ERROR){
        return;
    }
    printf("Introduce el nuevo nombre: ");
    fflush(stdin);
    gets(cad);
    strcpy(usuario.nombre,cad);
    printf("Introduce la nueva direcci�n: ");
    gets(cad);
    strcpy(usuario.direccion,cad);
    printf("Introduce el nuevo tel�fono: ");
    gets(cad);
    strcpy(usuario.telefono,cad);
    printf ("El usuario ha sido introducido con �xito\n");
    modificarUsuario(clave, &usuario);
    system("pause");
    system("cls");

}

/*Imprime un usuario por consola*/
static void imprimirUsuario (const Ficha *usuario){
    printf("NOMBRE:     %s\n", usuario->nombre);
    printf("DIRECCION:  %s\n", usuario->direccion);
    printf("TELEFONO:   %s\n", usuario->telefono);
    printf("CLAVE:     %d\n", usuario->clave);
    printf("--------------------------------------------------------------------\n");
}
