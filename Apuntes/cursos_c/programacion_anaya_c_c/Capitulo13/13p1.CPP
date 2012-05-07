#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Empleado {
  protected:
    string nombre;
  public:
    // Constructor
    Empleado (string n) { nombre = n; }
    // Funci¢n que escribe el nombre del empleado
    virtual void miNombre () {
      cout << "empleado llamado " << nombre;
    }
};

class Vendedor : public Empleado {
  public:
    // Constructor
    Vendedor (string n) : Empleado (n) { }
    // Funci¢n que escribe el nombre del empleado
    void miNombre () {
      cout << "vendedor llamado " << nombre;
    }
};

class Tecnico : public Empleado {
  public:
    // Constructor
    Tecnico (string n) : Empleado (n) { }
    // Funci¢n que escribe el nombre del empleado
    void miNombre () {
      cout << "t‚cnico llamado " << nombre;
    }
};

class Director : public Empleado {
  public:
    // Constructor
    Director (string n) : Empleado (n) { }
    // Funci¢n que escribe el nombre del empleado
    void miNombre () {
      cout << "director llamado " << nombre;
    }
};

class Despachos {
    int maxEmp;
    int numEmp;
    Empleado **emp;

  public:
    // Constructor
    Despachos (int maxE);

    // Destructor
    ~Despachos () {
      delete [] emp;
    }

    // Una funcion para asignar despacho
    int asigna (Empleado & empl);

    // Para saber qui‚n ocupa cada despacho
    void quien ();
};

Despachos::Despachos (int maxE) {
  maxEmp = maxE;
  numEmp = 0;
  emp = new Empleado * [maxEmp];
  for (int i=0; i<maxEmp; i++) emp[i] = NULL;
}

int Despachos::asigna (Empleado & empl) {
  int i;
  if (numEmp==maxEmp) return -1;
  numEmp++;
  for (i=0; i<maxEmp; i++)
    if (emp[i]==NULL) break;
  emp[i] = & empl;
  return i;
}

void Despachos::quien () {
  if (numEmp>0)
    for (int i=0; i<maxEmp; i++)
      if (emp[i]) {
        cout << "Despacho " << i <<
                " ocupado por el ";
        emp[i]->miNombre();
        cout << endl;
      }
}

void main (void) {
  Vendedor Juan ("Juan");
  Tecnico Pedro ("Pedro");
  Vendedor Rodrigo ("Rodrigo");
  Tecnico Maria ("Mar¡a");
  Despachos d (10);
  Director Luisa ("Luisa");
  Empleado Jose ("Jos‚");
  d.asigna (Juan);
  d.asigna (Pedro);
  d.asigna (Rodrigo);
  d.asigna (Maria);
  d.asigna (Luisa);
  d.asigna (Jose);
  d.quien ();
}
