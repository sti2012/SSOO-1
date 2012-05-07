/* 
 * Programa:    prog12_11
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 12:
 *              Acceso directo de E/S a un list�n telef�nico usando registros.
 */

#include <stdio.h>

/* definici�n de la estructura de usuario */
struct datosUsuario {
    int numreg;
    char nombre[32];
    unsigned int telefono;    
} usuario;

void crearListinUsuario(FILE ** listin);
void insertarUsuarios(FILE * listin);
void extraerUsuarios(FILE * listin);

int main(void)
{
    FILE * listin;
    int seleccion = -1;

    while (seleccion != 0)
    {
        fprintf(stdout,"0.- Salir \n");
        fprintf(stdout,"1.- Crear list�n usuario \n");
        fprintf(stdout,"2.- Insertar usuarios en list�n\n");
        fprintf(stdout,"3.- Extraer usuarios del list�n\n");
        fprintf(stdout,"Selecci�n: ");
        fscanf(stdin, "%d", &seleccion);

        switch (seleccion)
        {
        case 0:
            return (0);
            break;
        case 1:
            crearListinUsuario(&listin);
            break;
        case 2:
            insertarUsuarios(listin);
            break;
        case 3:
            extraerUsuarios(listin);
            break;
        default:
            fprintf(stderr, "Opci�n no admitida \n");
        } /* fin del switch */
    } /* fin del while */
    return(0);   
}

/*
 * Creaci�n del archivo listin. 
 * Si est� creado se vac�a el contenido.
 */
void crearListinUsuario(FILE **listin)
{
    /* Apertura, con creaci�n si no existe, del archivo de salida */
    *listin = fopen("./listin", "w+");
    if (*listin == NULL)
    {
       fprintf(stderr, "Error creando listin \n");
    }
}

/*
 * Lee por la entrada est�ndar los datos del usuario 
 * y escribe el registro en la posici�n adecuada del archivo del list�n. 
 * Para ello, debe acceder directamente a la posici�n del archivo acorde con su 
 * n�mero de registro.
 */
void insertarUsuarios(FILE * listin)
{
    int leidos = 0;
    int escritos = 0;

    /* Lectura de usuarios.
     * Para cuando se alcanza se introduce un n�mero de 
     * registro negativo
     * o cuando hay un error de entrada.
     */
    do
    {
        /* Leer datos de un usuario */
        fprintf(stdout, "Numero registro: ");
        leidos = fscanf(stdin, "%d",&usuario.numreg); 
        if (usuario.numreg == 0) {
            break;
        }
        fprintf(stdout, "Usuario: ");
        leidos += fscanf(stdin, "%31s",usuario.nombre); 
        fprintf(stdout, "Telefono: ");
        leidos += fscanf(stdin, "%d", &usuario.telefono); 
        fscanf(stdin, "%*[^\n]");
	  /* Calcular la nueva posici�n y saltar de acuerdo al n�mero de registro */
        leidos = fseek(listin, usuario.numreg * sizeof(struct datosUsuario), SEEK_SET);
        if ( leidos != 0)
               fprintf(stderr, "Error al hacer fseek \n");
        /* Escribir datos de un usuario en listin */
        escritos = fwrite((void *)&usuario, sizeof(struct datosUsuario), 
                  1, listin);
        if ( escritos != 1)
               fprintf(stderr, "Error al escribir el usuario en listin \n");
    } while ((usuario.numreg > 0) && !ferror(listin));
}

/*
 * Lee del listin el usuario cuyos datos se piden y los 
 * escribe por la salida est�ndar.
 */
void extraerUsuarios(FILE * listin)
{
    int leidos = 0;

    /* Para cuando se alcanza se introduce un n�mero de 
     * registro negativo o cuando hay un error de entrada.
     */
    do
    {
        /* Leer numreg de un usuario */
        fprintf(stdout, "Numero registro: ");
        leidos = fscanf(stdin, "%d",&usuario.numreg); 
        if (usuario.numreg == 0) {
            break;
        }
        fscanf(stdin, "%*[^\n]");
	/* Calcular la posici�n y saltar de acuerdo al n�mero de registro */
        leidos = fseek(listin, usuario.numreg * sizeof(struct datosUsuario), SEEK_SET);
        /* Leer datos de un usuario desde el list�n */
        leidos = fread((void *)&usuario, sizeof(struct datosUsuario), 
                  1, listin);
        if ( leidos <= 0)
               fprintf(stderr, "Error al leer el listin \n");
        /* Escribir datos de un usuario en la salida est�ndar */
        fprintf(stdout, "Usuario: ");
        fprintf(stdout, "%31s\n",usuario.nombre); 
        fprintf(stdout, "Telefono: ");
        fprintf(stdout, "%d\n", usuario.telefono); 

    } while ((usuario.numreg > 0) && !ferror(listin));
}


