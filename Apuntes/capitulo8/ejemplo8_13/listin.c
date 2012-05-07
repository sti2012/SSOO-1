//listin.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listin.h"
#define TEST 1

//número total de registros introducidos
static int numeroRegistros = 0;
static FILE* fichero;
static char nombreFichero [200];

static FILE* inicializar (const char* archivo){
    fichero = fopen(archivo, "wb");
    if (fichero == NULL){
        return NULL;
    }
    if (TEST){
        Ficha ultimoRegistro;
        strcpy (ultimoRegistro.nombre, "Un nombre cualquiera");
        strcpy (ultimoRegistro.direccion, "Una dirección cualquiera");
        strcpy (ultimoRegistro.telefono, "123456789");
        int i;
        for (i = 0; i < 3; i++){
            ultimoRegistro.clave = i;
            fwrite (&ultimoRegistro, sizeof(Ficha), 1, fichero);
            numeroRegistros++;
        }
    }
    fflush (fichero);
    fclose (fichero);
    //devolvemos un manejador al fichero creado abierto para lectura
    return fopen(archivo, "rb+");
}

int cargarListin(const char* archivo){
    fichero = fopen(archivo, "rb+");
    if (fichero == NULL){  //si el fichero no existe
        //para probar el programa, creamos uno con registros aleatorios
        fichero = inicializar (archivo);
        //si no se pudo crear el fichero devolvemos el código de error
        if (fichero == NULL){
            return ERROR;
        }
    }
    //situamos el apuntador justo antes del último registro
    fseek (fichero, -sizeof (Ficha), SEEK_END);
    Ficha ultimoRegistro;
    fread (&ultimoRegistro, sizeof (Ficha), 1, fichero);
    numeroRegistros = ultimoRegistro.clave +1;
    strcpy (nombreFichero, archivo);
    return (numeroRegistros + 1);
}

int anhadirUsuario (Ficha* usuario){
    //situamos el apuntador justo después del último registro
    fseek (fichero, numeroRegistros*sizeof (Ficha), SEEK_SET);
    usuario->clave = numeroRegistros;
    fwrite (usuario, sizeof (Ficha), 1, fichero);
    numeroRegistros++;
    return (numeroRegistros-1);
}

int modificarUsuario(int clave, Ficha* usuario){
    if (clave > numeroRegistros){
        return ERROR;
    }
    usuario->clave = clave;
    //situamos el apuntador justo antes del registro
    fseek (fichero, clave*sizeof (Ficha), SEEK_SET);
    fwrite (usuario, sizeof (Ficha), 1, fichero);
    return 1;
}

Ficha buscarUsuario (int clave){
    Ficha registroClave;
    if (clave > numeroRegistros){
        registroClave.clave = ERROR;
    }
    else{
        //situamos el apuntador justo antes del registro con número clave
        fseek (fichero, clave*sizeof (Ficha), SEEK_SET);
        fread (&registroClave, sizeof (Ficha), 1, fichero);
    }
    return registroClave;
}

int obtenerNumeroRegistros (){
    return numeroRegistros;
}

void guardarListin(){
    fflush (fichero);
    fclose (fichero);
}

int borrarListin (){
    fclose(fichero);
    if (remove (nombreFichero) != 0){  //si no se pudo borrar
        return ERROR;
    }
    return 1;  //si se borró
}
