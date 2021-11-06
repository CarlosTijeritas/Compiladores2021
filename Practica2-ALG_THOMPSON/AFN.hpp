#include <iostream>
#include <map>
#include<vector>
#include "Automata.hpp"
class AFN:public Automata{
    public:
        AFN(char simbolo,int n):Automata(){
          this->nodos.push_back(n);
          this->nodos.push_back(n+1);
          this->alfabeto.push_back(simbolo);
          string str(1,simbolo);
          string valorNodo(std::to_string(this->nodos[1]));
          string value=str +" : [" +valorNodo+"]";
          this->transiciones.insert(make_pair(nodos[0],value));
          this->estadoInicial = this->nodos[0];
          this->estadoFinal.push_back(this->nodos[1]);
        }
          
            
};
