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
            
            }      
        
        void mostrarAutomata();

  };
