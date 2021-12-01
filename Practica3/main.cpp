#include <iostream>
#include "ConstruccionAFN.hpp"
#include "Postfija.hpp"
#include "Subconjuntos.hpp"
using namespace std;

int main(){
  
  vector<char> expresion={'(','a','b',')','*','c','|','d'};
 // cout<<"La ER solo puede contener los siguientes caracteres: [a-z], '(','|',')','*'"<<endl;
  //cout<<"La expresion regular a transformar a AFN por Algoritmo de Thompson es: ";
  //for(auto car:expresion){
    //cout<<car;
  //}
  //cout<<endl;
  cout<<"EL AFN A CONVERTIR A AFD ES:"<<endl;
  auto afn=construyeAFN(convertirPostfija(expresion));
  afn.mostrarAutomata();
  cout<<"EL AFD EQUIVALENTE ES:"<<endl;
  auto afd=aplicarSubconjuntos(afn);
  afd.mostrarAutomata();
  return 0;
}
