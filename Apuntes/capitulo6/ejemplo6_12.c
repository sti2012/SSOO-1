//ejemplo6_12.c
#include <stdio.h>
#include <string.h>

int main (){
    char meses[][15]={"enero","febrero","marzo","abril","mayo","junio","julio",
                      "agosto","septiembre","octubre","noviembre","diciembre"};
    int duracion[]={31,28,31,30,31,30,31,31,30,31,30,31};
    char mes[15];
    int i, encontrado=0;
    printf("Introduzca el mes: ");
    gets(mes);
    for (i=0;i<12;i++){
        if (stricmp(mes,meses[i])==0){
            encontrado=1;
            break;
        }
    }
    if (!encontrado) printf("Ese mes no existe \n");
    else printf("Ese mes tiene %i días\n",duracion[i]);
}

