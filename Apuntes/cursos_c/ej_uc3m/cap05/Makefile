# 
# Makefile
# Autores:     Jes�s Carretero P�rez, 
#              F�lix Garc�a Carballeira, 
#              Javier Fernandez Mu'noz, 
#              Alejandro Calder�n Mateos
# Fecha:       06-2001
# Descripci�n: Makefile para los ejemplo del Cap�tulo 1:
#


#--------------------------
# Configuraci�n
#--------------------------

CC             = gcc
LIB_PATH       = -L/usr/lib
INCLUDE_PATH   = -I/usr/include
SOURCE_PATH    = .
CFLAGS         = -O2 -Wall -ansi
LIBLINK        = 
CAP_01_EXE     = prog05_01.exe prog05_02.exe prog05_03.exe prog05_04.exe \
		 prog05_05.exe prog05_06.exe prog05_07.exe prog05_08.exe \
		 prog05_09.exe prog05_10.exe prog05_11.exe


#--------------------------
# Reglas de compilaci�n
#--------------------------

all: $(CAP_01_EXE)

%.o: %.c
	@echo "     $< ..."
	@$(CC)  $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@

%.exe: %.o
	@echo "     $@ ..." 
	@$(CC)  $(CFLAGS) $(LIB_PATH) -o $@  $<  $(LIBLINK)


clean:
	@echo "   rm *.o ..."
	@rm -fr *.o

cleane:
	@echo "   rm *.o ..."
	@echo "   rm *.exe ..."
	@rm -fr *.o
	@rm -fr *.exe



