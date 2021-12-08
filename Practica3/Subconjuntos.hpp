#include<iostream>
#include<vector>
#include<map>
#include <algorithm>


using namespace std;

void cerraduraE(map<int, string>transiciones,int estadoActual,
vector<int> A){
  A.push_back(estadoActual);
  try{
        auto iter = transiciones.begin();
        while (iter != transiciones.end()) {
          auto transicion=iter->second;
          if(iter->first==estadoActual && transicion[0]=='E' ){
             if (*find(A.begin(), A.end(),iter->first ) != iter->first) {
                 cerraduraE(transiciones,iter->first,A);
            } 
          }
          ++iter;
      }
  }catch(...){
     
  }    
}
void calcularNucleos(AFN afn,vector<string> cerraduraNucleo,vector<int>nucleos,int posicionEpsilon,Automata afd){

}
vector<int>mover(map<int,string>transiciones,string estados,char simbolo){ //checar casting
  vector<int> posibles;
  
  for(auto estado:estados){
    auto iter = transiciones.begin();
    while (iter != transiciones.end()) {
          if(iter->first==int(estado)){
             string aux=iter->second;
             if(aux[4]!=',' and aux[4]!=']'){
                string estadoPosible=aux[3]+aux[4];
                posibles.push_back(int(estadoPosible));
              }else{
                posibles.push_back(int(aux[3]));
              }
          }
      }
      ++iter;
      }
  sort(posibles.begin(),posibles.end());
  return posibles;
}

Automata aplicarSubconjuntos(AFN afn){
  vector<int> A; //Vector que contendra la cerradura del estadoInicial
  vector<int> nucleos;
  vector<string> cerraduraNucleo; //cerradurasEpsilon de cada nucleo
  nucleos.push_back(afn.estadoInicial);
  cerraduraE(afn.transiciones,afn.estadoInicial,A);
  copy(A.begin(), A.end(), cerraduraNucleo.begin());
  int posicionEpsilon=0;
  Automata afd;
  calcularNucleos(afn,cerraduraNucleo,nucleos,posicionEpsilon,afd);
  copy(afn.alfabeto.begin(),afn.alfabeto.end(),afd.alfabeto.begin());
  auto iter = afd.transiciones.begin();
  while (iter != afd.transiciones.end()) {
      afd.nodos.push_back(iter->first);
      for(char elemento:cerraduraNucleo[iter->first]){
          if(int(elemento)==afn.estadoInicial){
          afd.estadoInicial=iter->first;
          }
          if(int(elemento)==afn.estadoFinal[0]){
          afd.estadoFinal.push_back(iter->first);
          }
          
      }
      ++iter;
      }
  return afd;

}
