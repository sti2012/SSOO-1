//ejemplo7_4_1.c
#include <stdio.h>
#include <stdlib.h>
#define MAX 120  //Longitud del array de estructuras
#define LNOMBRE 30  //Longitud de la cadena nombre
#define LDIRECC 40  //Longitud de la cadena dirección
#define LTFNO 12  //Longitud de la cadena telefono

//Estructura que representa cada registro
typedef struct Registro{
    char nombre[LNOMBRE];
    char direccion[LDIRECC];
    char telefono[LTFNO];
}Ficha;

int numeroRegistros = 0;//número de registros introducidos
Ficha listin[MAX];//array donde se almacenan los registros

int imprimeMenu();
void imprimirListin ();
void introducirUsuario();
void buscarUsuario ();
void imprimirUsuario (Ficha usuario);

int main (){
    int opc = 0, salir = 0;
    while (salir != 1){
        switch (opc=imprimeMenu()){
        case 1:
            introducirUsuario();
            break;
        case 2:
            buscarUsuario();
            break;
        case 3:
            imprimirListin();
            break;
        case 4:
            salir = 1;
        }
    }
    return 0;
}

/*Imprime el menú y devuelve la opcion del usuario*/
int imprimeMenu(){
    int c=0;
    char retorno;
    printf("---------------- Listín telefónico: -------------\n\n");
    printf("\t\t1.Introducir usuario   \n");
    printf("\t\t2.Buscar usuario       \n");
    printf("\t\t3.Imprimir lístin      \n");
    printf("\t\t4.Salir                \n\n");

    do{
        printf("-------Introducir opción [1-4]: ");
        scanf ("%i",&c);
        scanf("%c",&retorno);
    }
    while (c<0 || c>4);
    system("cls");
    return c;
}

/*Lista los usuarios controlando el llenado de pantalla*/
void imprimirListin(){
    register int i=0,j;
    printf("---------------- Listín telefónico: -------------\n\n");
    for (j=0; j<numeroRegistros ; j++){
        if (i==5){
            i=1;
            system("pause");
            printf("---------------- Listín telefónico: -------------\n\n");
        }
        else{
            i++;
        }
        imprimirUsuario (listin[j]);
    }
}

/*Pide un nombre de usuario y lo busca en el listin*/
void buscarUsuario (){
    char nombreABuscar[LNOMBRE];
    register int i;
    printf("\n\n\n\t Introduzca el nombre a buscar");
    gets(nombreABuscar );
    printf("\n");
    for (i=0; i<MAX; i++){
        if (strcmp(listin[i].nombre,nombreABuscar)==0){
            imprimirUsuario (listin[i]);
            break;
        }
    }
    if (i==MAX){
        printf ("El usuario no se encuentra\n");
    }
}

/*Comprueba si hay espacio en el array y, si lo hay, pide los datos*/
void introducirUsuario(){
    char cad[255];
    int i;
    Ficha usuario;

    if (numeroRegistros==MAX){
        printf("El listín telefónico está lleno, no se puede introducir\n");
    }
    else{
        printf("Introduzca el nombre: ");
        gets(cad);
        strcpy(usuario.nombre,cad);
        printf("Introduzca la dirección: ");
        gets(cad);
        strcpy(usuario.direccion,cad);
        printf("Introduzca el teléfono: ");
        gets(cad);
        strcpy(usuario.telefono,cad);
        listin[numeroRegistros]=usuario;
        numeroRegistros++;
        printf ("El usuario ha sido introducido con éxito\n");
    }
}

/*Imprime un usuario por consola*/
void imprimirUsuario (Ficha usuario){
    printf("NOMBRE:     %s\n", usuario.nombre);
    printf("DIRECCION:  %s\n", usuario.direccion);
    printf("TELEFONO:   %s\n", usuario.telefono);
}
