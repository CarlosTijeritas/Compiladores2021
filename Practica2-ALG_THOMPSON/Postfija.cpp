#include "Postfija.hpp"

using namespace std;

int precedencia(char operador){
    int precedencia=0;
     if (operador == '*'){
        precedencia=3;
     }
     else if(operador == '.'){
        precedencia=2;
     }
     else if(precedencia=='('){
        precedencia=0;
     }
     else if(operador == '|'){
        precedencia=1;
     }
     else if(operador == ')'){
       precedencia=4;
     }
    return precedencia;
}

vector<char> marcarConcatenacion(vector<char> expresion){
   vector <char>expresionMarcada;
   expresionMarcada.push_back(expresion[0]);
   for(int i=1;i<expresion.size();i++){
      string aux(1,expresion[i-1]);
      string aux_2(1,expresion[i]);
      if(regex_match(aux,regex("[a-z]")) and regex_match(aux_2,regex("[a-z]"))){
        expresionMarcada.push_back('.');
      }
      expresionMarcada.push_back(expresion[i]);
       if(regex_match(aux,regex("[)]")) and regex_match(aux_2,regex("[*]"))){
        expresionMarcada.push_back('.');
      }
      
   }
   return expresionMarcada;
}


vector<char> convertirPostfija(vector<char> expRegular){
    expRegular=marcarConcatenacion(expRegular);
    vector<char> operadores;
    vector<char> expresionPostfija;
    
    for(char caracter:expRegular){
       string caracterComparar(1,caracter);
       if(regex_match(caracterComparar,regex("[.*|(]"))){
           if(operadores.size()==0 or caracter=='('){
              
           }
           else{
              while (precedencia(caracter) <= precedencia(operadores[operadores.size()-1])){
                    char operadorAgregado=operadores[operadores.size()-1];
                    expresionPostfija.push_back(operadorAgregado);
                    operadores.pop_back();

                    if (operadores.size()==0){
                          break;
                    }
               }
            }  operadores.push_back(caracter);
          }
          else if(caracter==')'){
             while(true){
               char tope=operadores[operadores.size()-1];
               
               if(tope=='('){
                  operadores.pop_back();
                  break;
                }

               expresionPostfija.push_back(tope);
               operadores.pop_back();
               if(operadores.size()==0){
                 break;
               }
             }
          }
          else{
              expresionPostfija.push_back(caracter);
          }
          
          
        
       }
    while (operadores.size() != 0){
      expresionPostfija.push_back(operadores[operadores.size()-1]);
      operadores.pop_back();
    }
      
    return expresionPostfija;
  
    }
