//ejercicio6_9.c
#include <stdio.h>
#include <stdlib.h>

int main (){
    char cad[200],cad2[200];
    int palindroma,tamSinEspacios,i;
    printf("Teclea la frase o palabra\n");
    gets(cad);
    tamSinEspacios=0;
    //eliminamos los espacios en blanco
    //el último carácter de la cadena es el carácter nulo
    for (i=0; cad[i] != 0;i++){
        if (cad[i] != ' '){
            cad2[tamSinEspacios]= cad[i];
            tamSinEspacios++;
        }
    }
    palindroma = 1;
    //mientras no demuestre que no es palindroma
    //o no llegue a la mitad del texto
    for (i=0; palindroma && i<=(tamSinEspacios/2); i++){
        if (cad2[i] != cad2[tamSinEspacios-1-i]){
            palindroma =0;
        }
    }
    if (palindroma){
        printf("Es palindroma\n");
    }
    else{
        printf("No es palindroma\n");
    }
    system("pause");
}
