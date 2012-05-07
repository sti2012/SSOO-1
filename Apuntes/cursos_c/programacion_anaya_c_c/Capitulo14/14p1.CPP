#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

class MalaFecha {};

class MalAnno : public MalaFecha {
  public:
    int anno;
    MalAnno (int a) : anno(a) {}
};

class MalMes : public MalaFecha {
  public:
    int mes;
    MalMes (int m) : mes(m) {}
};

class MalDia : public MalaFecha {
  public:
    int dia;
    MalDia (int d) : dia(d) {}
};

class NoBisiesto : public MalAnno {
  public:
    NoBisiesto (int a) : MalAnno(a) {}
};

class Fecha {
    int anno, mes, dia;
    // D¡as por mes en un a¤o normal
    static const int diasMeses[12];
    int diasMes () {
      int dm=diasMeses[mes-1];
      if (mes==2 && bisiesto()) dm++;
      return dm;
    }
    void ajustar ();
  public:
    Fecha (int anno, int mes, int dia,
           int ajuste=0) {
      this->anno = anno;
      this->mes = mes;
      this->dia = dia;
      if (ajuste) ajustar ();
      else {
        if (anno<1) throw MalAnno(anno);
        else if (mes<1 || mes>12)
          throw MalMes(mes);
        else if (dia<1) throw MalDia(dia);
        else if (dia>diasMes()) {
          if (dia==29) throw NoBisiesto(anno);
          else throw MalDia(dia);
        }
      }
    }

    int bisiesto () {
      return anno%4==0 &&
             ( anno<=1582 ||
               anno%100!=0 ||
               anno%400==0
             );
    }

    void listar () {
      cout << dia << "/" << mes << "/" << anno;
    }

    Fecha operator + (long dias);
    Fecha operator - (long dias);
    friend Fecha operator + (long dias, Fecha f1);
};

void Fecha::ajustar () {
  while (mes<1) {anno--; mes+=12;}
  while (mes>12) {anno++; mes-=12;}
  while (dia<1) {
    if (--mes==0) {mes=12; anno--;}
    dia+=diasMes();
  }
  while (dia>diasMes()) {
    dia-=diasMes();
    if (++mes>12) {mes=1; anno++;}
  }
}

Fecha Fecha::operator + (long dias) {
  Fecha f(anno, mes, dia+dias, 1);
  return f;
}

Fecha Fecha::operator - (long dias) {
  Fecha f(anno, mes, dia-dias, 1);
  return f;
}

Fecha operator + (long dias, Fecha f1) {
  Fecha f(f1.anno, f1.mes, f1.dia+dias, 1);
  return f;
}

const int Fecha::diasMeses[12]={31,28,31,30,31,30,31,31,30,31,30,31};

void main () {
  int anno,mes,dia;
  long incr;
  for (;;) {
    cout << "Escriba el dia (0 para salir): ";
    cin >> dia;
    if (dia==0) break;
    cout << "Escriba el mes: ";
    cin >> mes;
    cout << "Escriba el a¤o: ";
    cin >> anno;
    try {
      Fecha f(anno, mes, dia);
      cout << (f.bisiesto() ?
              "Ese a¤o es bisiesto" :
              "Ese a¤o no es bisiesto")
           << endl;
      cout << "¨Cu ntos d¡as quiere sumar y restar a esa fecha? ";
      cin >> incr;
      f.listar();
      cout << "+" << incr << "=";
      (incr + f).listar();
      cout << endl;
      f.listar();
      cout << "-" << incr << "=";
      (f - incr).listar();
      cout << endl;
    } catch (NoBisiesto n) {
      cout <<
        "Esa fecha es incorrecta, porque el a¤o "
        << n.anno << " no es bisiesto" << endl;
    } catch (MalaFecha) {
      cout << "Esa fecha es incorrecta" << endl;
    }
  }
}
