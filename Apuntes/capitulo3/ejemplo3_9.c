//ejemplo3_9.c
#include <stdio.h>
#include <time.h>//Funci�n time

int main(){
    int i = 0;
    //inicializaci�n de la rutina de generaci�n de n�meros aleatorios
    srand(time(NULL));
    for (i = 0; i < 100; i++){
        char c = (char)(rand()%26 + 'a');//generamos el car�cter aleatorio
        printf("%c: ",c);
        switch (c){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("es una vocal\n");
            break;
        default:
            printf("es una consonante\n");
        }
    }
    system("pause");
}

