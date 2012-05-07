/* 
 * Programa:    prog12_11
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 12:
 *              Acceso directo de E/S a un listín telefónico usando registros.
 */

#include <stdio.h>

/* definición de la estructura de usuario */
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
        fprintf(stdout,"1.- Crear listín usuario \n");
        fprintf(stdout,"2.- Insertar usuarios en listín\n");
        fprintf(stdout,"3.- Extraer usuarios del listín\n");
        fprintf(stdout,"Selección: ");
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
            fprintf(stderr, "Opción no admitida \n");
        } /* fin del switch */
    } /* fin del while */
    return(0);   
}

/*
 * Creación del archivo listin. 
 * Si está creado se vacía el contenido.
 */
void crearListinUsuario(FILE **listin)
{
    /* Apertura, con creación si no existe, del archivo de salida */
    *listin = fopen("./listin", "w+");
    if (*listin == NULL)
    {
       fprintf(stderr, "Error creando listin \n");
    }
}

/*
 * Lee por la entrada estándar los datos del usuario 
 * y escribe el registro en la posición adecuada del archivo del listín. 
 * Para ello, debe acceder directamente a la posición del archivo acorde con su 
 * número de registro.
 */
void insertarUsuarios(FILE * listin)
{
    int leidos = 0;
    int escritos = 0;

    /* Lectura de usuarios.
     * Para cuando se alcanza se introduce un número de 
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
	  /* Calcular la nueva posición y saltar de acuerdo al número de registro */
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
 * escribe por la salida estándar.
 */
void extraerUsuarios(FILE * listin)
{
    int leidos = 0;

    /* Para cuando se alcanza se introduce un número de 
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
	/* Calcular la posición y saltar de acuerdo al número de registro */
        leidos = fseek(listin, usuario.numreg * sizeof(struct datosUsuario), SEEK_SET);
        /* Leer datos de un usuario desde el listín */
        leidos = fread((void *)&usuario, sizeof(struct datosUsuario), 
                  1, listin);
        if ( leidos <= 0)
               fprintf(stderr, "Error al leer el listin \n");
        /* Escribir datos de un usuario en la salida estándar */
        fprintf(stdout, "Usuario: ");
        fprintf(stdout, "%31s\n",usuario.nombre); 
        fprintf(stdout, "Telefono: ");
        fprintf(stdout, "%d\n", usuario.telefono); 

    } while ((usuario.numreg > 0) && !ferror(listin));
}


