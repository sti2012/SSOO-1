#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

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
    Fecha (int anno, int mes, int dia) {
      this->anno = anno;
      this->mes = mes;
      this->dia = dia;
      ajustar ();
    }
    int bisiesto () {
      return anno%4==0 &&
           ( anno<=1582 ||
             anno%100!=0 ||
             anno%400==0
           );
     }
     void escribir () {
       cout << dia << "/" << mes << "/" << anno;
     }
     Fecha operator + (long dias);
     Fecha operator - (long dias);
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
  Fecha f(anno, mes, dia+dias);
  return f;
}

Fecha Fecha::operator - (long dias) {
  Fecha f(anno, mes, dia-dias);
  return f;
}

const int Fecha::diasMeses[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

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
    Fecha f(anno, mes, dia);
    cout << (f.bisiesto() ?
            "Ese a¤o es bisiesto" :
            "Ese a¤o no es bisiesto")
         << endl;
    cout<<"¨Cu ntos d¡as sumar  y restar  a
           esa fecha? ";
    cin >> incr;
    f.escribir();
    cout << "+" << incr << "=";
    (f + incr).escribir();
    cout << endl;
    f.escribir();
    cout << "-" << incr << "=";
    (f - incr).escribir();
    cout << endl;
  }
}
