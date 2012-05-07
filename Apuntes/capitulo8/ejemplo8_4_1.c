//ejercicio8_4_1.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int contenidaEn(char cadena[], char subcadena[]);
int main (){
    char cadena[200], subcadena[200];
    printf(" Introduzca la cadena: ");
    scanf (" %s",cadena);
    printf(" Introduzca la subcadena:");
    scanf (" %s",subcadena);
    int veces = contenidaEn(cadena, subcadena);
    printf("\nLa subadena aparece %d veces en la cadena\n",veces);
    system("pause");
}

int contenidaEn(char cadena[], char subcadena[]){
    int j,k;
    int longCadena;
    int longSubcadena;
    int cont = 0;

    longCadena = strlen (cadena);
    longSubcadena = strlen (subcadena);
    for (j=0; j<longCadena; j++){
        //comprobamos si a partir de la posición j se encuentra la subcadena
        for (k=0; k<longSubcadena; k++){
            //si falla un carácter podemos abandonar la búsqueda y pasar j+1
            if (subcadena[k]!=cadena[k+j]){
                break;
            }
            else{
       //si k ha variado entre 0 y longSubcadena-1 hemos encontrado una ocurrencia
                if (k==(longSubcadena-1)){
                    cont++;
                }
            }
        }
    }
    return cont;
}
