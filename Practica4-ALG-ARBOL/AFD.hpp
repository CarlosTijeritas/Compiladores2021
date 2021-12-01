#include <iostream>
#include <map>
#include<vector>

using namespace std;
class AFD{
    public:
         vector <int> nodos;
         vector <char> alfabeto;
         map<int, string> transiciones;
         int estadoInicial;
         vector <int>  estadoFinal;
         AFD(){
         }
        template<typename Map>
        void imprimirTransiciones(Map& m) { 
            
            }      
        
        void mostrarAFD();

  };
