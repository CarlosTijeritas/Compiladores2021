#include <iostream>
#include <vector>
#include <regex>
#include <string>
using namespace std;
int precedencia(char operador);
vector<char> marcarConcatenacion(vector<char> expresion);
vector<char> convertirPostfija(vector<char> expRegular);
