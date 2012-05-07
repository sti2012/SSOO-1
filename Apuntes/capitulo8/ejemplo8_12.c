//ejemplo8_12.c
#include <stdio.h>
#include <stdlib.h>

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
    FILE* fichero;

    fichero = fopen( "nombres.dat", "r" );
    if (fichero!=NULL){
        //mientras no se alcance el final del fichero
        while (!feof(fichero)){
            if (fread( &registro, sizeof(registro), 1, fichero )!=0){
                printf( "Nombre: %s\n", registro.nombre );
                printf( "Apellido: %s\n", registro.direccion);
                printf( "Teléfono: %s\n\n", registro.telefono);
            }
        }
        fclose( fichero );
    }
    else{
        printf( "No se pudo abrir el fichero de entrada" );
    }
    system("pause");
    return 0;
}

