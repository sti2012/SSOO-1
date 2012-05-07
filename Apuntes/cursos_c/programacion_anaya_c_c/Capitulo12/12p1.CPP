class Curso;
class Cliente;

class Empleado {
    char *nombre;
    short departamento;
  protected:
    long sueldo;
  public:
    // Constructor
    Empleado (char *n, long s, short d)
    {
      nombre = n;
      sueldo = s;
      departamento = d;
    }
  };

class Tecnico : public Empleado {
    Curso **cursos;
    short maxCursos, nCursos;
  public:
    // Constructor
    Tecnico (char *n, long s, short d, short nc) :
    Empleado (n, s, d)
    {
      cursos = new Curso *[nc];
      maxCursos = nc;
      nCursos = 0;
    }
    ~Tecnico () { delete[] cursos; }
    // M‚todo que a¤ade un curso a la lista de cursos
    void nuevoCurso (Curso * c);
    long aumento (double ipc);
  };

class Vendedor : public Empleado {
    Cliente **clientes;
    short maxClientes, nClientes;
  public:
    // Constructor
    Vendedor (char *n, long s, short d, short nc) :
    Empleado (n, s, d)
    {
      clientes = new Cliente *[nc];
      maxClientes = nc;
      nClientes = 0;
    }
    ~Vendedor () { delete[] clientes; }
    // M‚todo que a¤ade un cliente a la lista de clientes
    void miCliente (Cliente * c);
    long aumento (double ipc);
  };

class Director : public Empleado {
    Empleado **empleados;
    short maxEmpleados, nEmpleados;
  public:
    // Constructor
    Director (char *n, long s, short d, short ne) :
    Empleado (n, s, d)
    {
      empleados = new Empleado *[ne];
      maxEmpleados = ne;
      nEmpleados = 0;
    }
    // M‚todo que a¤ade un empleado a la lista de empleados
    void miEmpleado (Empleado * e);
    long aumento (double ipc);
  };

long Tecnico::aumento (double ipc) {
  return long (sueldo*ipc);
}

long Vendedor::aumento (double ipc) {
  return long (sueldo*ipc*0.5);
}

long Director::aumento (double ipc) {
  return long (sueldo*ipc*0.25);
}
