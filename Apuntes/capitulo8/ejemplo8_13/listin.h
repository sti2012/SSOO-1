//listin.h
#ifndef LISTIN  //Si no se incluy� anteriormente este archivo
#define LISTIN

#define MAX 120  //Longitud del array de estructuras
#define LNOMBRE 30  //Longitud de la cadena nombre
#define LDIRECC 40  //Longitud de la cadena direcci�n
#define LTFNO 12  //Longitud de la cadena tel�fono
#define ERROR -1  //C�digo para indicar que sucedi� un error

//Estructura que representa cada registro
typedef struct Registro{
    char nombre[LNOMBRE];
    char direccion[LDIRECC];
    char telefono[LTFNO];
    int clave;
}Ficha;

/*Recibe como argumento la clave de un registro
y devuelve el registro correspondiente*/
Ficha buscarUsuario (int clave);
/*Inicializa el list�n a partir de los datos del archivo que se le pasa
como argumento y devuelve el n�mero de registros que contiene
el list�n o ERROR si no se pudo cargar el archivo*/
int cargarListin(const char* archivo);
/*A�ade el registro al final del archivo y devuelve su n�mero de clave*/
int anhadirUsuario (Ficha* usuario);
/*Devuelve el n�mero de registros actuales*/
int obtenerNumeroRegistros ();
/*Guarda los cambios que pudiesen quedar sin realizar en el archivo*/
void guardarListin();
/*Modifica el usuario que se corresponde con la clave (primer argumento)
con los datos del registro que se pasa como segundo argumento*/
int modificarUsuario(int clave, Ficha* usuario);
/*Elimina el fichero asociado con el list�n*/
int borrarListin ();

#endif
