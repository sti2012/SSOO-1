/*
*ejemplox_47.c
*/
#include <stdio.h>
#include <stdlib.h>

const char* calcularHoroscopo(int fecha) {
if       (fecha>= 321 && fecha<= 420) return "aries";
else if  (fecha>= 421 && fecha<= 520) return "tauro";
else if  (fecha>= 521 && fecha<= 621) return "géminis";
else if  (fecha>= 622 && fecha<= 722) return "cáncer";
else if  (fecha>= 723 && fecha<= 823) return "leo";
else if  (fecha>= 824 && fecha<= 923) return "virgo";
else if  (fecha>= 924 && fecha<=1023) return "libra";
else if  (fecha>=1024 && fecha<=1122) return "escorpio";
else if  (fecha>=1123 && fecha<=1221) return "sagitario";
else if  (fecha>=1222 && fecha<= 120) return "capricornio";
else if  (fecha>= 121 && fecha<= 220) return "acuario";
else if  (fecha>= 221 && fecha<= 320) return "piscis";
else return "desconocido, es usted del planeta Tierra?";
}

int main()
{
   int fecha;
   printf("Introduzca su fecha de nacimiento en el formato (mmdd)\n"
          "Por ejemplo, 0906 que sería el día 6 del mes 9:\n");
   scanf(" %d",&fecha);
   printf("Su horóscopo es %s\n",calcularHoroscopo(fecha));
   system("PAUSE");	
   return 0;
}
