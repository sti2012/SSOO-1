# 
# Makefile
# Autores:     Jes�s Carretero P�rez, 
#              F�lix Garc�a Carballeira, 
#              Javier Fernandez Mu'noz, 
#              Alejandro Calder�n Mateos
# Fecha:       06-2001
# Descripci�n: Makefile para los ejemplo del Cap�tulo 9:
#


#--------------------------
# Configuraci�n
#--------------------------

CC             = gcc
LIB_PATH       = -L/usr/lib
INCLUDE_PATH   = -I/usr/include
SOURCE_PATH    = .
CFLAGS         = -g  -Wall -ansi
LIBLINK        = 


#--------------------------
# Reglas de compilaci�n
#--------------------------

all: prog07_09.exe

%.o: %.c
	@echo "     $< ..."
	@$(CC)  $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@

prog07_09.exe: prog07_09.o leyohm.o
	@echo "     $@ ..." 
	@$(CC)  $(CFLAGS) $(LIB_PATH) -o $@  prog07_09.o leyohm.o $(LIBLINK)


clean:
	@echo "   rm *.o ..."
	@rm -fr *.o

cleane:
	@echo "   rm *.o ..."
	@echo "   rm *.exe ..."
	@rm -fr *.o
	@rm -fr *.exe



