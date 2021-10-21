#include <iostream>
using namespace std;

class Transicion{
public:
  int estadoActual;
  int estadoTransicion;
  char simboloT;
  bool EpsilonT;
  Transicion(int estado1, int estado2, char simbolo);
  Transicion(int estado1, int estado2, char simbolo, bool isEpsilon);
};
