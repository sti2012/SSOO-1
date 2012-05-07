//ejemplo2_7.c
#include <stdio.h>

int main (){
    int var;
    printf("Un char ocupa %d bytes\n", sizeof(char));
    printf("Un signed char ocupa %d bytes\n", sizeof(signed char));
    printf("Un unsigned char ocupa %d bytes\n", sizeof(unsigned char));
    printf("Un int ocupa %d bytes\n", sizeof (int)); /* sin paréntesis */
    printf("Un signed int ocupa %d bytes \n", sizeof(signed int));
    printf("Un unsigned int ocupa %d bytes \n", sizeof(unsigned int));
    printf("Un short ocupa %d bytes \n", sizeof(short));
    printf("Un signed short ocupa %d bytes\n", sizeof(signed short));
    printf("Un unsigned short ocupa %d bytes\n", sizeof(unsigned short));
    printf("Un long ocupa %d bytes\n", sizeof(long));
    printf("Un signed long ocupa %d bytes\n", sizeof(signed long));
    printf("Un unsigned long ocupa %d bytes\n", sizeof(unsigned long));
    printf("Un long long ocupa %d bytes\n", sizeof(long long));
    printf("Un signed long long ocupa %d bytes\n", sizeof(signed long long));
    printf("Un unsigned long long ocupa %d bytes\n", sizeof(unsigned long long));
    printf("Un float ocupa %d bytes\n", sizeof(float));
    printf("Un double ocupa %d bytes\n", sizeof(double));
    printf("Un long double ocupa %d bytes\n", sizeof(long double));
    printf("La variable 'var' ocupa %d bytes\n", sizeof(var));
    system("pause");

}
