//ejemplo3_8_2.c
#include <stdio.h>

int main(){
    char c;
    for ( c = 0; c < 127; c++){
        printf("El valor: %i se corresponde con el carácter %c\n", (int)c,c);
    }
    system("pause");
}
