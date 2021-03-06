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
vector<int>mover(map<int,string>transiciones,string estados,char simbolo){
  vector<int> posibles;
  
  for(auto estado:estados){
    auto iter = transiciones.begin();
    while (iter != transiciones.end()) {
          if(iter->first==int(estado)){
             string aux=iter->second;
             int estadoPosible;
             if(aux[4]!=',' and aux[4]!=']'){
                estadoPosible=int(aux[3]);
                posibles.push_back(estadoPosible);
              }
          }
      }
      ++iter;
      }
  sort(posibles.begin(),posibles.end());
  return posibles;
}
void calcularNucleos(AFN afn,vector<string> cerraduraNucleo,vector<int>nucleos,int posicionEpsilon,Automata afd){
  map<int,string> aux;
  bool bandera=false;
  for(auto simbolo:afn.alfabeto){
      auto posiblesMover=mover(afn.transiciones,cerraduraNucleo[posicionEpsilon],simbolo);
      int indicePosiblesMover;
      for(int i=0;i<posiblesMover.size();i++){
           for(int nucleo:nucleos){
                if(posiblesMover[i]==nucleo){
                    bandera=true;
                    indicePosiblesMover++;
                    break;
                }
                indicePosiblesMover++;
            }
          if(bandera==false){
            nucleos.push_back(posiblesMover[i]);
            vector<int>cerraduraParcial;
            cerraduraE(afn.transiciones,posiblesMover[i],cerraduraParcial);
            for(int j=0;j<cerraduraParcial.size();j++){
                cerraduraNucleo.push_back(str(cerraduraParcial));
            }
            calcularNucleos(afn,cerraduraNucleo,nucleos,cerraduraNucleo.size()-1,afd);
          }
      }
      aux.insert(make_pair(simbolo,indicePosiblesMover));
  }
  afd.transiciones.insert(make_pair(posicionEpsilon,aux));
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



