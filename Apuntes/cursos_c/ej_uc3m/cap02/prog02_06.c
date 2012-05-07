/* ***************************************************** 
 *
 *  M�dulo: Agenda.c
 * 
 ******************************************************
 *  Autores: Alberto Miedes Fern�ndez
 *           Jes�s carretero P�rez
 *
 *  Organizaci�n: Universidad Carlos III de Madrid
 *  Fecha de creaci�n: 22-04-2001
 *  Versi�n: 1.0
 *
 *  Descripcion: 
 *  M�dulo que se ejecuta en primer lugar al ejecutar el programa
 *  Contiene el men� principal.
 *
 *  Funciones p�blicas: 
 *  main
 *
 *  Funciones privadas: 
 *  No tiene
 *	
 *  Atributos p�blicos: 
 *  No tiene
 *
 *  Atributos privados: 
 *  No tiene
 *
 *  Referencias a otros archivos:
 *  agendausuario.h
 *
 *  Directivas de compilaci�n:
 *	UNIX	Source code for UNIX versions only
 *	WIN32	Source code for WINDOWS versions only
 *
 ****************************************************** */

/*
 * INCLUDES
 */
#include "agendausuario.h"


/*
 * DEFINICI�N DE LA FUNCI�N PRINCIPAL 
 */

/* ***************************************************** 
 *
 *  Funci�n: main
 *
 * ***************************************************** 
 *  Autores: Alberto Miedes Fern�ndez
 *           Jes�s carretero P�rez
 *
 *  Organizaci�n: Universidad Carlos III de Madrid
 *  Fecha de creaci�n: 22-04-2001
 *
 *  Actualizaci�n:
 *    
 *  Descripcion:
 *  Funci�n inicial del programa. En ella se realiza la carga de todos los  
 *  datos presentes en los ficheros a memoria din�mica y se presenta el menu
 *  inicial del programa, en el que se da la opci�n de ver los datos de  
 *  un usuario, crear uno nuevo o borrar uno ya existente. Por �ltimo, al 
 *  finalizar la ejecuci�n del programa se graban todos los datos presentes 
 *  en la memoria din�mica a memoria secundaria, con el fin de su posterior 
 *  almacenamiento y consulta.
 *
 *  Par�metros de entrada:
 *  No tiene
 *
 *  Par�metros de entrada/salida:
 *  Devuelve 0
 *
 *  Salida:
 *  Por pantalla para el usaurio. 
 *
 *  Llamadas a funciones de otros m�dulos:
 *  inicializarListaUsuarios
 *  inicializarListaDatos
 *  inicializarListaNotas
 *  inicializarListaCitas
 *  existeArchivo
 *  leerArchivoUsuarios
 *  leerArchivoDatos
 *  leerArchivoCitas
 *  leerArchivonotas
 *  escribirCadena
 *  liberarCadena
 *  saltoLinea
 *  solicitarCadena
 *  leerCadena
 *  pasarCadenaaEntero
 *  entrar 
 *  crear
 *  borrar
 *  cargarArchivoUsuarios
 *  cargarArchivoDatos
 *  cargarArchivoCitas
 *  cargarArchivoNotas
 *  
 *  Llamadas a funciones privadas:
 *  No hay
 *
 ****************************************************** */
int main(void)
{
    /*
     * Declaraci�n de variables locales
     */
    int opcion;
    TTipoBooleano salir=false;
    char *cadena;  
    TListaUsuarios *listaUsuarios;
    TListaDatos *listaDatos;
    TListaCitas *listaCitas;
    TListaNotas *listaNotas;
    
    /*
     * Iniciaci�n de las listas de la agenda 
     */
    inicializarListaUsuarios(&listaUsuarios);
    inicializarListaDatos(&listaDatos);
    inicializarListaNotas(&listaNotas);
    inicializarListaCitas(&listaCitas);
    /*
     * lectura de datos de las listas de la agenda 
     */
    if (existeArchivo(archivoUsuarios)==true) leerArchivoUsuarios(&listaUsuarios);
    if (existeArchivo(archivoDatos)==true) leerArchivoDatos(&listaDatos);
    if (existeArchivo(archivoCitas)==true) leerArchivoCitas(&listaCitas);
    if (existeArchivo(archivoNotas)==true) leerArchivoNotas(&listaNotas); 
    /*
     * Men� principal de la agenda 
     */
    saltoLinea();
    escribirCadena("Bienvenido a su agenda electronica.\n");
    saltoLinea();
    cadena=solicitarCadena(sizeof(int));
    do{
        saltoLinea();
        escribirCadena("1.- Entrar en la agenda de un usuario");  
        saltoLinea();
        escribirCadena("2.- Crear un nuevo usuario"); 
        saltoLinea();
        escribirCadena("3.- Borrar un usuario");     
        saltoLinea();
        escribirCadena("0.- Salir del programa");
        saltoLinea();     
        leerCadena(cadena);    
        opcion=pasarCadenaaEntero(cadena);
        /*
         * Efectuar la operaci�n solicitada por el usuario 
         */
        switch(opcion){
            case 1:	 
	        entrar(listaUsuarios,&listaDatos,&listaCitas,&listaNotas);
	        break;
            case 2: 
	        crear(&listaUsuarios);
	        break;
	    case 3:
	        borrar(&listaUsuarios,&listaDatos,&listaCitas,&listaNotas);
	        break;
	    case 0: 
	        cargarArchivoUsuarios(&listaUsuarios);
	        cargarArchivoDatos(&listaDatos);  
	        cargarArchivoNotas(&listaNotas);
	        cargarArchivoCitas(&listaCitas);
	        salir=true;
	        saltoLinea();
	        break;
	    default:
	        escribirCadena("La opcion elegida es incorrecta");
	        saltoLinea();
	        saltoLinea();
	        /* se ha elegido una opci�n que no esta dentro de las indicadas */
        }  
    }while (salir==false);
    /*
     * liberaci�n de memoria asignada previamente 
     */
    liberarCadena(cadena);
    return(0);
}
