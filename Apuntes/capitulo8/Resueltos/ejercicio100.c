/*
*ejemplo7_100.c
*/

#include <stdio.h>
#include <stdlib.h>

//el primer archivo que pasemos sera el archivo a copiar
//el segunfo archivo es el archivo de destino 
int main(int argc,char *argv[]) 
{                               
    int bandera=1;
    if (argc!=3)
    {
	printf("Error en la linea de comandos\n\n");
	printf("Formato que debe usar:\t %s <fichero origen> <fichero destino>\n",argv[0]);
	exit(0);
    }
    else 
    {    
        
         FILE *ficheroOriginal,*ficheroCopia;
         char buffer[20],n2[20];
	 int bytesLeidos;
               
         
         ficheroOriginal=fopen(argv[1],"rb");
         ficheroCopia=fopen(argv[2],"wb");
         if ((ficheroOriginal==NULL)||(ficheroCopia==NULL))
         {
                                  printf("Error, no se pudo terminar la operación.");
                                  system("pause");

         }
         else
         {
            //hasta que no se acabe el fichero original
             while (!feof(ficheroOriginal)) 
             {
                   //leemos del fichero original
bytesLeidos = fread(buffer,sizeof(char),20,ficheroOriginal);
//y escribimos el fichero copia los bytes que hemos leído
                 fwrite(buffer,sizeof(char),bytesLeidos ,ficheroCopia);
             
             }
            
         }
             
         fflush(ficheroOriginal);
         fflush(ficheroCopia);
         fclose(ficheroOriginal);
         fclose(ficheroCopia);     
    }
        
}     
         
         
         
         
         

    


