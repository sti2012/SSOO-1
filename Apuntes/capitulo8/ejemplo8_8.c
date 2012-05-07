//ejercicio8_8.c
#include<stdio.h>
#include<math.h>

int main (){
    float inicio,fin, paso;
    char nombreArchivo[100];
    FILE *fichero;

    printf("Introduzca el intervalo [inicio, fin]: ");
    scanf(" [%f,%f]", &inicio,&fin);
    printf("Introduzca el paso: ");
    scanf ("%f",&paso);
    printf ("Introduzca el nombre del archivo donde se almacenarán los datos");
    fflush(stdin);//para eliminar el carácter de nueva línea
    gets (nombreArchivo);

    if ((fichero =fopen(nombreArchivo,"w+"))==NULL){
        printf("\nError de apertura de fichero");
        exit(-1);
    }
    for (; inicio <= fin; inicio = inicio + paso){
        fprintf(fichero, "x=%.3f, seno(x)=%.3f\n", inicio, sin(inicio));
    }
    printf("Archivo generado con éxito\n");
    fflush(fichero);
    fclose(fichero);
    system("pause");
}
