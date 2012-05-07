//ejemplo6_13.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//número máximo de líneas que se podrán leer
#define MAX 20

int contarVocales(char* cadena);
void leerTexto(char* texto []);
//número de líneas leídas
int lineas=0;

int main (){
    char *texto [MAX];
    int j, vocales[MAX];

    printf ("Teclea el texto:\n");
    leerTexto(texto);
    for (j=0;j<lineas;j++){
        vocales[j]= contarVocales(texto[j]);
        printf("%s : %d\n", texto [j], vocales[j]);
        //eliminamos la memoria reservada para texto[j]
        //ya que no vamos a emplear la de nuevo
        free(texto[j]);
    }
    system("pause");
    return 0;
}

//lee el texto
void leerTexto(char* texto []){
//éste será el tamaño máximo de línea que se puede introducir
    char temporal[121] ;
    int tam;

    do{
        gets(temporal);
        if (strcmp (temporal, "X")){
            //cantidad de memoria que necesitamos
            tam=(strlen(temporal)+1)*sizeof(char);
            texto[lineas]=(char *) malloc(tam);
            strcpy(texto[lineas],temporal);
            lineas++;
        }
    }
    while (strcmp (temporal, "X")!=0);
}

//Cuenta las vocales
int contarVocales(char* cadena){
    int num=0,j;
    for (j=0; j < strlen(cadena);j++){
        switch (tolower(cadena [j])){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            num++;
        }
    }
    return num;
}
