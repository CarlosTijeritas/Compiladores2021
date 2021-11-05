#include <iostream>
#include <map>
#include<vector>

using namespace std;
class Automata{
    public:
         vector <int> nodos;
         vector <char> alfabeto;
         map<int, string> transiciones;
         int estadoInicial;
        vector <int>  estadoFinal;
        Automata(){
        }
        template<typename Map>
        void imprimirTransiciones(Map& m) { 
            for (auto &item : m) {
                cout << item.first << ":" << item.second <<endl;
            }      
        }
        void mostrarAutomata(){
            cout<<"Alfabeto:{ ";
            for(auto caracter:this->alfabeto){
               cout<<caracter;
            }
            cout<<"}"<<endl;
            cout<<"Nodos:[";
            for(auto nodo:this->nodos){
               cout<<nodo;
            }
            cout<<"]"<<endl;
            cout<<"Transiciones:";
            imprimirTransiciones(this->transiciones);
            cout<<endl;
            cout<<"Estado inicial: "<<this->estadoInicial<<endl;
        }

  };
