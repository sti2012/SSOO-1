//ejemplo7_6.c
int main (){

    enum diasemana {lunes, martes, miercoles, jueves, viernes, sabado, domingo };

    int dia;

    for ( dia = lunes; dia <= domingo; dia++ ){
        if ( dia!= sabado|| dia != domingo ){
            printf("El d�a %d es laborable\n",dia);
        }
        else{
            printf("El d�a %d no es laborable\n",dia);
        }
    }
    return 0;
}
