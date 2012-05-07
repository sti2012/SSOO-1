/*
 * Programa: agenda
 * Modulo  : notas
 * Fichero : notas.h
 */

#include "notas.h"


/*
 * FUNCIONES P�BLICAS
 */

/*
 * Funci�n crearNotas
 */
ListaNotas crearNotas (void)
{
    return (NULL);
}

/*
 * Funci�n destruirNotas
 */
void destruirNotas (ListaNotas * notas)
{
    ListaNotas auxNotas = (*notas);

    /*
     *  Libera la memoria de
     *  cada nota
     */
    while (NULL != auxNotas) {
        (*notas) = auxNotas->resto;
        free (auxNotas->notas);
        free (auxNotas);
        auxNotas = (*notas);
    }
}

/*
 * Funci�n insertarNotas
 */
int insertarNotas (ListaNotas * notas, char *mensaje)
{
    char *copia;
    ListaNotas auxNotas = (*notas);
   
    /*
     * A�adir una nueva nota
     */
    if (NULL == (*notas)) {
        (*notas) = malloc(sizeof(Nota));
        if (NULL == (*notas)) {
            perror("malloc:");
            return -1;
        }
        auxNotas = (*notas);
        auxNotas->resto = NULL;
    } else {    
        while (NULL != auxNotas->resto) {
            auxNotas = auxNotas->resto;
        }
        auxNotas->resto = malloc(sizeof(Nota));
        if (NULL == (*notas)) {
            perror("malloc:");
            return -1;
        }
        auxNotas = auxNotas->resto;
        auxNotas->resto = NULL;

    }      
    /*
     *  Inserta una copia.
     */
    copia=stringDup(mensaje);
    auxNotas->notas=copia;
    return 0;
}

/*
 * Funci�n borrarNotas
 */
int  borrarNotas (ListaNotas * notas, int posicion)
{
    int i;
    ListaNotas auxNotas, auxNotas2;
    int valor=-1;

    
    if ((posicion > 0) && (NULL != (*notas))) { /* si lista vacia, terminar */
        auxNotas = (*notas);

        if (1 == posicion) {            /* si es la primera posici�n */
            (*notas) = (*notas)->resto;
            free (auxNotas->notas);
            free (auxNotas);
            valor=0;
        } else {                        /* si es otra posici�n */
            i = 1;
            while ((NULL != auxNotas->resto) && (i < (posicion-1) )) {  
                auxNotas = auxNotas->resto;
                i = i + 1;
            }
            if (NULL != auxNotas->resto) {      /* si esa posici�n existe */
                auxNotas2 = auxNotas->resto;
                auxNotas->resto = auxNotas->resto->resto;
                free (auxNotas2->notas);
                free (auxNotas2);
                valor=0;
            }
        }
    }
    return(valor);
}

/*
 * Funci�n consultarNotas
 */
char *consultarNotas (const ListaNotas *notas, int posicion)
{
    int i;
    ListaNotas auxNotas = (*notas);
    char *auxTexto;
    
    i = 1;
    /*
     * Buscar la posici�n indicada
     */
    while ((NULL != auxNotas) && (i < posicion )) {  
        auxNotas = auxNotas->resto;
        i = i + 1;
    }
    /*
     * Si esa posici�n existe se devuelve, si no, NULL
     */
    if (NULL != auxNotas) {       
        auxTexto = auxNotas->notas;
    } else {
        auxTexto = NULL;
    }
    return (auxTexto);
}

/*
 * Funci�n numeroNotas
 */
int numeroNotas (const ListaNotas *notas)
{
    int cont = 0;
    ListaNotas auxNotas = (*notas);
    
    /*
     * Calcular el n�mero de posiciones
     */
    while (NULL != auxNotas) {  
        auxNotas = auxNotas->resto;
        cont = cont + 1;
    }
    return (cont);

}

/*
 * Funci�n escribirArchivoNotas
 */
int escribirArchivoNotas(const ListaNotas *notas, char *archivo)
{
 
    FILE *desc;
    int i,num;
 
    desc = fopen(archivo, "w");
    if (NULL == desc) {
        perror("fopen: ");
        return (-1);
    }
    num=numeroNotas(notas);
 
    for (i=0; i<num; i++) {
            fprintf(desc,"Nota: %s\n",consultarNotas(notas,i));
    } 
    fclose(desc);
    return (0);
}    

/*
 * Funci�n leerArchivoNotas
 */
int leerArchivoNotas(ListaNotas *notas, char *archivo)
{
 
    FILE *desc;
    char texto[NOTA_MAX];
 
    desc = fopen(archivo, "r");
    if (NULL == desc) {
        perror("fopen: ");
        return (-1);
    }
    while (0 == feof(desc)) {
        fscanf(desc," Nota: ");
        fgets(texto,NOTA_MAX,desc);
        if ('\n' == texto[strlen(texto)-1]) {
            texto[strlen(texto)-1]='\0';
        }
        if (0 == feof(desc)) {
            insertarNotas(notas,texto);
        }
        fscanf(desc,"\n");
 
    }
    fclose(desc);
    return (0);
}             
