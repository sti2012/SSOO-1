/*
*ejemplox_111.c
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char linea[1024];
    FILE* fh_in;

    // Apertura del archivo
    fh_in=fopen("quijote.txt","r");
    if (fh_in==NULL) {
        printf("No puedo abrir el archivo quijote.txt\n");
        system ("PAUSE") ;
        return 1;
    }
    
    fscanf(fh_in," %[^\n]",linea);
    while (!feof(fh_in)) {
        printf("%s\n",linea);
        fscanf(fh_in," %[^\n]",linea);
    }
    fclose(fh_in);
    
    system("PAUSE") ;
    return 0 ;
}
