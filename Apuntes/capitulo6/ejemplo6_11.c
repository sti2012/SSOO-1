//ejemplo6_11.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    char cad1[20]= "hola",cad2[20]= "HOLA";
    if (strcmp(cad1,cad2)!=0){
        printf("Para strcmp no son iguales \n");
    }
    if (stricmp(cad1,cad2)==0){
        printf("Para stricmp son iguales \n");
    }
    if (strcmp(cad1,strlwr(cad2))==0){
        printf("cad1 y strlwr(cad2) son iguales para strcmp\n");
    }
    //la función strlwr ha modificado el valor de cad2
    printf ("cad2: %s",cad2);
    //volvemos a almacenar en cad2 su valor original
    strcpy(cad2, "HOLA");
    if (strcmp(strupr(cad1),cad2)==0){
        printf("strupr (cad1) y cad2 son iguales para strcmp\n");
    }
    //ejemplo de concatenación
    printf ("Ambas cadenas concatenadas: %s",strcat(cad1,cad2));
    system("pause");
}
