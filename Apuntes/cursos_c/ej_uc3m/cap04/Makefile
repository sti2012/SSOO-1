# 
# Makefile
# Autores:     Jes�s Carretero P�rez, 
#              F�lix Garc�a Carballeira, 
#              Javier Fernandez Mu'noz, 
#              Alejandro Calder�n Mateos
# Fecha:       06-2001
# Descripci�n: Makefile para los ejemplo del Cap�tulo 2:
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
CAP_02_EXE     = prog04_01.exe   \
			prog04_02.exe \
			prog04_03.exe \
			prog04_04.exe \
			prog04_05.exe \
			prog04_06.exe \
			prog04_07.exe \
			prog04_08.exe


#--------------------------
# Reglas de compilaci�n
#--------------------------

all: $(CAP_02_EXE)

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



