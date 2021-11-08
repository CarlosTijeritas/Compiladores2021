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
        pReferencia.transiciones.merge(sReferencia.transiciones);
        map<int, string> transiciones_epsilon;
        int numNodos=pReferencia.nodos.size();
        string transicion_1="E : [" +to_string(pReferencia.estadoInicial)+" , "+to_string(sReferencia.estadoInicial)+"]";
        transiciones_epsilon.insert(make_pair(pReferencia.nodos[numNodos-2],transicion_1));
        string transicion_2="E : [" +to_string(pReferencia.nodos[numNodos-1])+"]";
        transiciones_epsilon.insert(make_pair(pReferencia.estadoFinal[0],transicion_2));
        string transicion_3="E : [" +to_string(pReferencia.nodos[numNodos-1])+"]";
        transiciones_epsilon.insert(make_pair(sReferencia.estadoFinal[0],transicion_3));
        pReferencia.transiciones.merge(transiciones_epsilon);
        pReferencia.estadoInicial=pReferencia.nodos[numNodos-2];
        pReferencia.estadoFinal[0]=pReferencia.nodos[numNodos-1];
        return pReferencia;
}
  
