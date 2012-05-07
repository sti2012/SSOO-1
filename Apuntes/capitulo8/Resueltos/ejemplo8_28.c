//ejemplo7_28.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    int bandera=1;
    if (argc!=3){
        printf("Error en la linea de comandos\n\n");
        printf("Formato que debe usar:\t %s <fichero origen> <fichero destino>\n",argv[0]);
        exit(0);
    }
    else{
        FILE *fichero1,*fichero2;
        char dato1,dato2;

        fichero1=fopen(argv[1],"rb");
        fichero2=fopen(argv[2],"rb");
        if ((fichero1==NULL)||(fichero2==NULL)){
            printf("Error, no se pudo terminar la operación.");
            system("pause");
        }
        else{
            //mientras no lleguemos al final de alguno de los ficheros
            //o descubramos que no son iguales
            while ( (!feof(fichero1))&&(!feof(fichero2))&&(bandera)){
                fread(&dato1,sizeof(char),1,fichero1);
                fread(&dato2,sizeof(char),1,fichero2);
                if (!(dato1==dato2))
                    bandera=0;
            }
            //si llegamos al final de ambos ficheros sin encontrar ninguna diferencia
            if ((bandera==1)&&(feof(fichero1))&&(feof(fichero2)))
                 printf("\narchivos iguales\n");
            else  printf("\narchivos distintos\n");
            system("pause");
        }
        fflush(fichero1);
        fflush(fichero2);
        fclose(fichero1);
        fclose(fichero2);
    }
}



