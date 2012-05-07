# 
# Makefile
# Autores:     Jesús Carretero Pérez, 
#              Félix García Carballeira, 
#              Javier Fernandez Mu'noz, 
#              Alejandro Calderón Mateos
# Fecha:       06-2001
# Descripción: Makefile para agenda GTK:
#


#--------------------------
# Configuración
#--------------------------

CC             = gcc
LIB_PATH       = -L/usr/lib
INCLUDE_PATH   = -I/usr/include
GTK_LIB_PATH     = `/usr/bin/gtk-config --libs`
GTK_INCLUDE_PATH = `/usr/bin/gtk-config --cflags`
SOURCE_PATH    = .
CFLAGS         = -g  -Wall -ansi
LIBLINK        = 
OBJECTS        = agenda.o \
		 datos_agenda.o \
                 citas.o fecha.o notas.o util.o \
                 menu_agenda.o menu_agenda_menus.o dialogos_con_fechas.o\
		 menu_intro.o menu_calendario.o dialogo_aviso.o\
		 menu_citas.o menu_notas.o \
		 dialogo_datos.o direcciones.o menu_direcciones.o


#--------------------------
# Reglas de compilación
#--------------------------

all: agenda.exe

%.o: %.c
	@echo "     $< ..."
	@$(CC)  $(CFLAGS) $(INCLUDE_PATH) $(GTK_INCLUDE_PATH) -c $< -o $@

agenda.exe: $(OBJECTS)
	@echo "     $< ..."
	@$(CC)  $(CFLAGS) $(INCLUDE_PATH) $(GTK_INCLUDE_PATH) \
	$(LIB_PATH) $(GTK_LIB_PATH) -o $@ $(OBJECTS)

clean:
	@echo "   rm *.o ..."
	@rm -fr *.o

cleane:
	@echo "   rm *.o ..."
	@echo "   rm *.exe ..."
	@rm -fr *.o
	@rm -fr *.exe


