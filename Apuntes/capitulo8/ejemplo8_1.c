//ejemplo8_1.c
#include <stdio.h
#define MAX 200  //n�mero m�ximo de caracteres que se podr�n introducir
int main (){
    char caracteres[MAX], c='a';
    int contador = 0;

    //leemos los caracteres
    while (c != '0'){
        c = getchar();
        if (c != '0'){
            //se almacena el car�cter y se incrementa el contador
            caracteres[contador] = c;
            ++contador;
        }
    }
    //imprimir los caracteres en orden inverso
    for (; contador>=0; --contador){
        putchar(caracteres[contador]);
    }
    system("pause");
    return 0;
}
