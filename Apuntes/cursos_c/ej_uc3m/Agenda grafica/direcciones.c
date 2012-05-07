/*
 * Programa: agenda
 * Modulo  : direcciones
 * Fichero : direcciones.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "direcciones.h"

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función crearDir
 */
ListaDir crearDir (void)
{
    return (NULL);
}

/*
 * Función destruirDir
 */
void destruirDir (ListaDir * datos)
{
    ListaDir auxDatos = *(datos);

    /*
     *  Libera la memoria de
     *  cada nota
     */
    while (NULL != auxDatos) {
        *(datos) = auxDatos->resto;
        free (auxDatos->nombre);
        free (auxDatos->direccion);
        free (auxDatos->telefono);
        free (auxDatos);
        auxDatos = *(datos);
    }
}

/*
 * Función insertarDir
 */
int insertarDir (ListaDir *datos, char *nombre, 
                      char *direccion, char *telefono)
{
    char *copia;
    ListaDir auxDatos = *(datos);

    /*
     * Añadir una nueva nota
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
        while (NULL != auxDatos->resto) {
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
    copia=stringDup(nombre);
    auxDatos->nombre=copia;
    copia=stringDup(direccion);
    auxDatos->direccion=copia;
    copia=stringDup(telefono);
    auxDatos->telefono=copia;
    return (0);
}

/*
 * Función borrarDir
 */
int borrarDir   (ListaDir *datos, char *nombre)
{
    ListaDir auxDatos, auxDatos2;
    int valor=-1;

    if (NULL != *(datos)) {        /* si lista vacia, terminar */
        auxDatos = *(datos);

        if (0 == strcmp(nombre, (*datos)->nombre)) {            
            *(datos) = (*datos)->resto;
            free (auxDatos->nombre);
            free (auxDatos->direccion);
            free (auxDatos->telefono);
            free (auxDatos);
            valor=0;
        } else {                        /* si es otra posición */
            while ((NULL != auxDatos->resto) && 
                             (0 != strcmp(nombre, auxDatos->resto->nombre)) ) {
                auxDatos = auxDatos->resto;
            }
            if (NULL != auxDatos->resto) {      /* si esa posición existe */
                auxDatos2 = auxDatos->resto;
                auxDatos->resto = auxDatos->resto->resto;
                free (auxDatos2->nombre);
                free (auxDatos2->direccion);
                free (auxDatos2->telefono);
                free (auxDatos2);
                valor=0;
            }
        }
    }
    return(valor);
}

/*
 * Función consultarDir
 */
int  consultarDir (const ListaDir *datos, int posicion, 
                    char **nombre, char **direccion, char **telefono)
{
    int i;
    int ret;
    ListaDir auxDatos = *(datos);
    
    i = 0;
    /*
     * Buscar la posición indicada
     */
    while ((NULL != auxDatos) && (i < posicion )) {  
        auxDatos = auxDatos->resto;
        i = i + 1;
    }
    /*
     * Si esa posición existe se devuelve, si no, NULL
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
 * Función consultarDirPorNombre
 */
int consultarDirPorNombre (const ListaDir *datos, char *nombre, 
                           int *pos, char **direccion, char **telefono)
{
    int i=0;
    int ret;
    ListaDir auxDatos = *(datos);
    
    /*
     * Buscar la posición indicada
     */
    while ((NULL != auxDatos) && (0 != strcmp(nombre, auxDatos->nombre))) {  
        auxDatos = auxDatos->resto;
        i = i + 1;
    }
    /*
     * Si esa posición existe se devuelve, si no, NULL
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
 * Función numeroDir
 */
int numeroDir (const ListaDir *datos)
{
    int cont = 0;
    ListaDir auxDatos = *(datos);
    
    /*
     * Calcular el número de posiciones
     */
    while (NULL != auxDatos) {  
        auxDatos = auxDatos->resto;
        cont = cont + 1;
    }
    return (cont);

}

/*
 * Función escribirArchivoDir
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
            fprintf(desc," Nom: %s\n Dir: %s\n Tel: %s\n",
                                               nombre,direccion,telefono);
        }
    }
    fclose(desc);
    return (0);
}

/*
 * Función leerArchivoDir
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
        if ('\n' == nombre[strlen(nombre)-1]) {
            nombre[strlen(nombre)-1]='\0';
        }
        fscanf(desc," Dir: ");
        fgets(direccion,TAM_MAX,desc);
        if ('\n' == direccion[strlen(direccion)-1]) {
            direccion[strlen(direccion)-1]='\0';
        }
        fscanf(desc," Tel: ");
        fgets(telefono,TAM_MAX,desc);
        if ('\n' == telefono[strlen(telefono)-1]) {
            telefono[strlen(telefono)-1]='\0';
        }

        if (0 == feof(desc)) {
            insertarDir(datos,nombre, direccion, telefono);
        }

        fscanf(desc,"\n");
    }
    fclose(desc);
    return (0);
}


    
