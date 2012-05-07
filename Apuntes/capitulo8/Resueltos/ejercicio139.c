/*
*ejemplox_139.c
*/
#include <stdio.h>
#include <stdlib.h>

int *creaArray(unsigned int tamano);
void destruyeArray(int *array);
void imprimeArray(int *array, unsigned int tamano);
void burbuja(int *array, unsigned int tamano);

int main()
{
    int *array;
    unsigned int tamano;
    
    printf("Introduzca el tamaño del array a ordenar: ");
    scanf("%u", &tamano);

    array = creaArray(tamano);
    printf("El array sin ordenar es:\n");
    imprimeArray(array, tamano);
    
    burbuja(array, tamano);
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

void burbuja(int *array, unsigned int tamano)
{
     int control = 1;
     int auxiliar,j;
        
     for (auxiliar = 0; auxiliar < tamano-1 && control; auxiliar++){
        control = 0;
        
        for (j = 0; j < tamano-auxiliar-1; j++)
        {
            if (array[j] > array[j+1]){
                int aux;
                control = 1;
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;};
        }
    }
}  
