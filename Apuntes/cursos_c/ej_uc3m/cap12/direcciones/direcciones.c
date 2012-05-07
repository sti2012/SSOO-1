/* 
 * Programa:    direcciones
 * Fichero:     direcciones.c
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 12:
 *              Implementaci�n del m�dulo direcciones grabando las mismas en un
 *              archivo
 */
#include <stdlib.h>
#include "direcciones.h"


/*
 * Funci�n crearDir
 */
ListaDir crearDir (void)
{
    return (NULL);
}

/*
 * Funci�n destruirDir
 */
void destruirDir (ListaDir * datos)
{
    ListaDir auxDatos = *(datos);

    /*
     *  Libera la memoria de
     *  cada nota
     */
    while (NULL != auxDatos){
        *(datos) = auxDatos->resto;
        free (auxDatos->nombre);
        free (auxDatos->direccion);
        free (auxDatos->telefono);
        free (auxDatos);
        auxDatos = *(datos);
    }
}

/*
 * Funci�n insertarDir
 */
int    insertarDir (ListaDir *datos, char *nombre, 
                      char *direccion, char *telefono)
{
    char *copia;
    ListaDir auxDatos = *(datos);

    /*
     * A�adir una nueva nota
     */
    if (NULL == *(datos)) {
        *(datos) = malloc(sizeof(Dir));
        if (NULL == *(datos)) {
		perror("malloc:");
		return (-1);
	}
        auxDatos = *(datos);
        auxDatos->resto = NULL;
    } else {    
        while (NULL != auxDatos->resto){
            auxDatos = auxDatos->resto;
        }
        auxDatos->resto = malloc(sizeof(Dir));
        if (NULL == *(datos)) {
		perror("malloc:");
		return (-1);
	}
        auxDatos = auxDatos->resto;
        auxDatos->resto = NULL;

    }      
    /*
     *  Inserta una copia.
     */
    copia=malloc(sizeof(nombre)+1);
    if (NULL == copia) {
		perror("malloc:");
		return (-1);
    }
    strcpy(copia,nombre);
    auxDatos->nombre=copia;
    copia=malloc(sizeof(direccion)+1);
    if (NULL == copia) {
		perror("malloc:");
		return (-1);
    }
    strcpy(copia,direccion);
    auxDatos->direccion=copia;
    copia=malloc(sizeof(telefono)+1);
    if (NULL == copia) {
		perror("malloc:");
		return (-1);
    }
    strcpy(copia,telefono);
    auxDatos->telefono=copia;
    return (0);
}

/*
 * Funci�n borrarDir
 */
void     borrarDir   (ListaDir *datos, char *nombre)
{
    ListaDir auxDatos, auxDatos2;

    if (NULL != *(datos)) {        /* si lista vacia, terminar */
        auxDatos = *(datos);

        if (0 == strcmp(nombre, (*datos)->nombre)) {            
            *(datos) = (*datos)->resto;
            free (auxDatos->nombre);
            free (auxDatos->direccion);
            free (auxDatos->telefono);
            free (auxDatos);
        } else {                        /* si es otra posici�n */
            while ((NULL != auxDatos->resto) && 
                             (0 != strcmp(nombre, auxDatos->resto->nombre)) ) {
                auxDatos = auxDatos->resto;
            }
            if (NULL != auxDatos->resto) {      /* si esa posici�n existe */
                auxDatos2 = auxDatos->resto;
                auxDatos->resto = auxDatos->resto->resto;
                free (auxDatos2->nombre);
                free (auxDatos2->direccion);
                free (auxDatos2->telefono);
                free (auxDatos2);
            }
        }
    }
}

/*
 * Funci�n consultarDir
 */
int  consultarDir (const ListaDir *datos, int posicion, 
                    char **nombre, char **direccion, char **telefono)
{
    int i;
    int ret;
    ListaDir auxDatos = *(datos);
    
    i = 0;
    /*
     * Buscar la posici�n indicada
     */
    while ((NULL != auxDatos) && (i < posicion )) {  
        auxDatos = auxDatos->resto;
        i = i + 1;
    }
    /*
     * Si esa posici�n existe se devuelve, si no, NULL
     */
    if (NULL != auxDatos) {       
        *nombre = auxDatos->nombre;
        *direccion = auxDatos->direccion;
        *telefono = auxDatos->telefono;
        ret = 0;
    } else {
        ret = -1;
    }
    return (ret);
}

/*
 * Funci�n consultarPorNombre
 */
int    consultarPorNombre (const ListaDir *datos, char *nombre, 
                           int *pos, char **direccion, char **telefono)
{
    int i=0;
    int ret;
    ListaDir auxDatos = *(datos);
    
    /*
     * Buscar la posici�n indicada
     */
    while ((NULL != auxDatos) && (0 != strcmp(nombre, auxDatos->nombre))) {  
        auxDatos = auxDatos->resto;
        i = i + 1;
    }
    /*
     * Si esa posici�n existe se devuelve, si no, NULL
     */
    if (NULL != auxDatos) {       
        *direccion = auxDatos->direccion;
        *telefono = auxDatos->telefono;
        *pos = i;
        ret = 0;
    } else {
        ret = -1;
    }
    return (ret);
}

/*
 * Funci�n numeroDir
 */
int numeroDir (const ListaDir *datos)
{
    int cont = 0;
    ListaDir auxDatos = *(datos);
    
    /*
     * Calcular el n�mero de posiciones
     */
    while (NULL != auxDatos) {  
        auxDatos = auxDatos->resto;
        cont = cont + 1;
    }
    return (cont);

}

/*
 * Funci�n escribirArchivoDir
 */
int escribirArchivoDir(const ListaDir *datos, char *archivo)
{

    FILE *desc;
    int i,num,ret;
    char *nombre, *direccion, *telefono;

    desc = fopen(archivo, "w");
    if (NULL == desc) {
        perror("fopen: ");
        return (-1);
    }
    num=numeroDir(datos);

    for (i=0; i<num; i++) {
        ret = consultarDir(datos,i,&nombre, &direccion, &telefono);
        if (0 == ret) {
            fprintf(desc," Nom: %s Dir: %s Tel: %s\n",
                                               nombre,direccion,telefono);
        }
    }
    fclose(desc);
    return (0);
}

/*
 * Funci�n leerArchivoDir
 */
int leerArchivoDir(ListaDir *datos, char *archivo)
{

    FILE *desc;
    char nombre[TAM_MAX], direccion[TAM_MAX], telefono[TAM_MAX];

    desc = fopen(archivo, "r");
    if (NULL == desc) {
        perror("fopen: ");
        return (-1);
    }
    while (0 == feof(desc)) {
        fscanf(desc," Nom: ");
        fgets(nombre,TAM_MAX,desc);
        fscanf(desc," Dir: ");
        fgets(direccion,TAM_MAX,desc);
        fscanf(desc," Tel: ");
        fgets(telefono,TAM_MAX,desc);
        fscanf(desc,"\n");

        if (0 == feof(desc)) {
            insertarDir(datos,nombre, direccion, telefono);
        }
    }
    fclose(desc);
    return (0);
}


    
