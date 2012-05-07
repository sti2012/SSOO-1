# 
# Makefile
# Autores:     Jesús Carretero Pérez, 
#              Félix García Carballeira, 
#              Javier Fernandez Mu'noz, 
#              Alejandro Calderón Mateos
# Fecha:       06-2001
# Descripción: Makefile para agenda.
#


#--------------------------
# Configuración
#--------------------------

CC             = gcc
LIB_PATH       = -L/usr/lib
INCLUDE_PATH   = -I/usr/include
SOURCE_PATH    = .
CFLAGS         = -g  -Wall -ansi 
LIBLINK        = -lm
GTK_LIB_PATH     = `/usr/bin/gtk-config --libs`
GTK_INCLUDE_PATH = `/usr/bin/gtk-config --cflags`
OBJECTS          = agenda.o \
                   direcciones.o 


#--------------------------
# Reglas de compilación
#--------------------------

all: agenda.exe

%.o: %.c
	@echo "     $< ..."
	@$(CC)  $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@

agenda.exe: $(OBJECTS)
	@echo "     $@ ..." 
	@$(CC)  $(CFLAGS) $(INCLUDE_PATH)  \
		$(LIB_PATH) -o $@ $(OBJECTS)

clean:
	@echo "   rm *.o ..."
	@rm -fr *.o

cleane:
	@echo "   rm *.o ..."
	@echo "   rm *.exe ..."
	@rm -fr *.o
	@rm -fr *.exe


