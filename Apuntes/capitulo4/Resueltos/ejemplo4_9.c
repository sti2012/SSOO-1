//ejemplo4_9.c
#include <stdio.h>
#include <stdlib.h>

int main (){
    float f=1.0F;
    unsigned char *ptr=(unsigned char *)&f;

    if (*ptr==0x3F && *(ptr+1)==0x80 && *(ptr+2)==0x00 && *(ptr+3)==0x00){
        printf("Su máquina es big endian\n");
    }
    else if (*ptr==0x00 && *(ptr+1)==0x00 && *(ptr+2)==0x80 && *(ptr+3)==0x3F){
        printf("Su máquina es little endian\n");
    }
    else{
        printf("Tipo de máquina desconocido\n");
    }
    system("PAUSE");
}
