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
