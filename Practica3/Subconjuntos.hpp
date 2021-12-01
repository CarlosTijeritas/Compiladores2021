#inxlude<iostream>
#include<vector>
#include<map>

using namespace std;

AFD aplicarSubconjuntos(AFN automata){
  vector<int> A; //Vector que contendra la cerradura del estadoInicial
  vector<int> nucleos;
  vector<int> cerradurasNucleo; //cerradurasEpsilon de cada nucleo
  nucleos.push_back(AFN.estadoInicial);
  cerraduraE(AFN.transiciones,AFN.estadoInicial,A);
  copy(A.begin(), A.end(), cerraduraE.begin());
  int posicionEpsilon=0;
  AFD afd=new AFD();
  calcularNucleos(AFN,cerraduraNucleos,nucleos,posicionEpsilon,afd);
  copy(AFN.alfabeto.begin(),AFN.alfabeto.end(),afd.alfabeto.begin());
  auto iter = transiciones.begin();
  while (iter != transiciones.end()) {
      afd.nodos.push_back(iter->first);
      for(auto elemento:cerraduraNucleo[iter->first]){
        if(elemento==AFN.estadoInicial){
          afd.estadoInicial=iter->first;
        }
        if(elemento==AFN.estadoFinal){
          afd.estadoFinal.push_back(iter->first);
        }
      }
      ++iter;
      }
  return afd;

}
