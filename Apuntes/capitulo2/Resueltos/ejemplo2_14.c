//ejemplo2_14.c
#include <stdio.h>
#include <stdlib.h>

int main (){
    char letra='D';
    if (letra>='A' && letra<='Z'){
        letra=letra-'A'+'a';
    }
    printf ("Letra: %c\n",letra);
    system("PAUSE");
}
