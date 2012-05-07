//ejemplo8_11.c
#include <stdio.h>
#include <stdlib.h>
#define MAX 120  //longitud del array de registros
#define LNOMBRE 30  //longitud de la cadena nombre
#define LDIRECC 40  //longitud de la cadena dirección
#define LTFNO 12  //longitud de la cadena telefono

//Estructura que representa cada registro
struct Registro{
    char nombre[LNOMBRE];
    char direccion[LDIRECC];
    char telefono[LTFNO];
}registro;

int main (){
    FILE *fichero;

    fichero = fopen( "nombres.dat", "a+" );
    if (fichero!=NULL){
        do{
            printf( "\nIntroduzca el nombre: " );
            gets(registro.nombre);
            if (strcmp(registro.nombre,"")){
                printf( "Introduzca la dirección: " );
                gets(registro.direccion);
                printf( "Teléfono: " );
                gets(registro.telefono);
                fwrite( &registro, sizeof(registro), 1, fichero );
            }
        }
        while (strcmp(registro.nombre,"")!=0);
        fflush (fichero);
        fclose( fichero );
    }
    else{
        printf( "Error al abrir el fichero" );
    }
    return 0;
}
