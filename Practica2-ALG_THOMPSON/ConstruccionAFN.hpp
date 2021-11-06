#include "AFN.hpp"
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
bool existeEnAlfabeto(vector<char> v, char busqueda);
AFN unir(AFN pReferencia,AFN sReferencia,int n);
AFN concatenar(AFN pReferencia,AFN sReferencia,int n);
AFN cerradura(AFN pReferencia,int n);
AFN construyeAFN(vector<char>expresionPostfija);
