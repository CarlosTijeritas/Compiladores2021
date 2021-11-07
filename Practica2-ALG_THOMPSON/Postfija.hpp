#include <iostream>
#include <vector>

using namespace std;

vector<char> convertirPostfija(String expRegular){
    vector<char> operadores;
    vector<char> expresionPostfija;
    const regex exp_auxiliar="[.*|(]";
    for(char caracter:expRegular){
       if(regex_match(caracter,exp_auxiliar)){
           if(operadores.size()==0 or caracter=='('){
              continue;
           }
