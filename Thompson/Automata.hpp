#include <iostream>

class Automata{

public:
    std::vector<Estado*> estadosAutomata;
    std::vector<char> alfabetoAutomata;
    Estado* estadoInicialAutomata;
    Estado* estadoFinalAutomata;
    std::vector<Transicion*> tablaTransicionesAutomata;
    Automata();
    Automata(vector<Estado*> estados,vector<char> alfabeto, Estado* estadoInicial, std::vector<Transicion*> tablaTransiciones);
    std::vector<Estado*> getEstados();
    std::vector<Transicion*> getTablaTransiciones();
    std::vector<char> getAlfabeto();
    Estado* obtenerEstadoInicial();
    Estado* obtenerEstadoFinal();
};
