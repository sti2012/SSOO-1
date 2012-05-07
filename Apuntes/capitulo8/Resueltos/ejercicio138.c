/*
*ejemplox_138.c
*/

#include <stdio.h>
#include <stdlib.h>

int *creaArray(unsigned int tamano);
void destruyeArray(int *array);
void imprimeArray(int *array, unsigned int tamano);
void insercionDirecta(int *array, unsigned int tamano);

int main()
{
    int *array;
    unsigned int tamano;
    
    printf("Introduzca el tamaño del array a ordenar: ");
    scanf("%u", &tamano);

    array = creaArray(tamano);
    printf("El array sin ordenar es:\n");
    imprimeArray(array, tamano);
    
    insercionDirecta(array, tamano);
    printf("El array ordenado es:\n");
    imprimeArray(array, tamano);
    
    destruyeArray(array);
    
    system("PAUSE");	
    return 0;
}
 

int *creaArray(unsigned int tamano)
{
    int i, valor;
    int *array;
    
    if (tamano <= 0) {
        printf("Introduzca el tamaño del array a ordenar: ");
        scanf("%u", &tamano);
    }
    
    array = (int *)malloc(tamano * sizeof(int));
    if (array == NULL) {
        printf("Error en la asignación de memoria!\n");
        exit(0);
    }
    
    printf("Introduzca %d valores para llenar el array:\n", tamano);
    for (i=0; i<tamano; i++) {
        printf("  valor % 3d: ", i);
        scanf("%d", &valor);
        array[i]= valor;
    } 
    return array;
}  

void destruyeArray(int *array)
{
     free(array);
}
 
void imprimeArray(int *array, unsigned int tamano)
{
    int i;
    char sep='[';

    for(i=0; i<tamano; i++) {
        printf("%c%d", sep, array[i]);
        sep = ',';
    }
    printf("]\n");
}

void insercionDirecta(int *array, unsigned int tamano)
{
    int auxiliar;
    int i, j;
    i=0;
    while(i<tamano-1){
        i++;
        auxiliar=array[i];
        j=i-1;
        while(array[j]>auxiliar && j>0){
                array[j+1]=array[j];
                j--;
        }                              
        if(array[j]>auxiliar){
                array[j+1]=array[j];
                array[j]=auxiliar;       
        }else {
              array[j+1]=auxiliar;
              }
    }
}  
