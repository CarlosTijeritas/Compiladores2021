#include "AFD.hpp"
#include <iostream>
#include <map>
#include<vector>

using namespace std;
        
        void AFD::mostrarAFD(){
            cout<<"Alfabeto:{ ";
            for(char caracter:this-> alfabeto){
               cout<<caracter<<"   ";
            }
            cout<<"}"<<endl;
            cout<<"Nodos:[";
            for(int nodo:this->nodos){
               cout<<nodo<<" ";
            }
            cout<<"]"<<endl;
            cout<<"Transiciones:"<<endl;
            auto iter = transiciones.begin();
              while (iter != transiciones.end()) {
                 cout << iter->first << "->"
                    << iter->second << "\n";
                     ++iter;
                     }
            cout<<endl;
            cout<<"Estado inicial: "<<this->estadoInicial<<endl;
            cout<<"Estado Final: [";
            for(auto estado:this->estadoFinal){
               cout<<estado<<" ";
            }
            cout<<"]"<<endl;
        }
