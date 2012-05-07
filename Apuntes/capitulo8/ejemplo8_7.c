//ejercicio8_7.c
#include<stdio.h>
#include<stdlib.h>
#define N 100

int main (){
    int opcion;
    FILE *fich;
    char cadena[N], nombreFichero[N];
    printf ("Introduzca el nombre del fichero a abrir: ");
    scanf (" %s",nombreFichero);
    system("cls");
    do{
        system("cls");
        printf("\n\n\t\t----------MENU----------");
        printf("\n\t\t1.Listar contenido del archivo");
        printf("\n\t\t2.Añadir texto al archivo");
        printf("\n\t\t3.Salir del programa");
        do{  //hasta que la acción sea correcta
            printf("\n\nIntroduzca la opción deseada:");
            scanf(" %d",&opcion);
        }
        while ((opcion<1)||(opcion>3));

        switch (opcion){
        case 1: {
            if ((fich=fopen(nombreFichero,"r"))==NULL){
                printf("\nError de apertura de fichero");
                exit(-1);
            }
            while (fgets(cadena,N,fich) != NULL){
                printf("%s",cadena);
            }
            fclose(fich);
            printf("\n");
            system("pause");
            break;
        }
        case 2:{
            if ((fich=fopen(nombreFichero,"a+"))==NULL){
                printf("\nError de apertura de fichero");
                exit(-1);
            }
            printf("\nIntroduzca texto, para terminar escriba salir:\n");
            do{
              //eliminamos cualquier residuo del buffer de entrada de la consola
                fflush(stdin);
                gets(cadena);
                if (stricmp (cadena, "salir") ==0){
                    break;
                }
                fputs(cadena, fich);
                fputs("\n", fich); //añadimos un carácter de nueva línea
            }
            while (1);
            fflush(fich);
            fclose(fich);
            break;
        }
      }
    }
    while (opcion!=3);
    system("pause");
    return 0;
}
