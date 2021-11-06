#include "ConstruccionAFN.hpp"

using namespace std;

bool existeEnAlfabeto(vector<char> v, char busqueda) {
    return find(v.begin(), v.end(), busqueda) != v.end();
}
AFN unir(AFN pReferencia,AFN sReferencia,int n){
        pReferencia.nodos.insert(pReferencia.nodos.end(),sReferencia.nodos.begin(),sReferencia.nodos.end()); 
        pReferencia.alfabeto.insert(pReferencia.alfabeto.end(),sReferencia.alfabeto.begin(),sReferencia.alfabeto.end()); 
        pReferencia.nodos.push_back(n);
        pReferencia.nodos.push_back(n+1);
  
