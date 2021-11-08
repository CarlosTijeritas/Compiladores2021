#include <iostream>
#include "ConstruccionAFN.hpp"
using namespace std;

int main(){
  
  vector<char> expresion={'a', 'b', '.', '*', 'c', '.', 'd', '|'};
  auto afn=construyeAFN(expresion) ;
  afn.mostrarAutomata();
  //afn.convertirAFN();
  return 0;
}
