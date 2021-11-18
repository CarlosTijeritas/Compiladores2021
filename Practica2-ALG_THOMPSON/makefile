a.out: main.o Automata.o AFN.o Postfija.o ConstruccionAFN.o
	g++ main.o Automata.o AFN.o Postfija.o ConstruccionAFN.o -Wall
main.o: main.cpp
	g++ -c main.cpp -Wall
Automata.o: Automata.cpp
	g++ -c Automata.cpp -Wall
AFN.o: AFN.cpp
	g++ -c AFN.cpp -Wall
Postfija.o: Postfija.cpp
	g++ -c Postfija.cpp -Wall
ConstruccionAFN.o: ConstruccionAFN.cpp
	g++ -c ConstruccionAFN.cpp -Wall
clean:
	rm main.o Automata.o AFN.o Postfija.o ConstruccionAFN.o a.out
run:
	./a.out
indent:
	indent main.cpp AFN.cpp Postfija.cpp ConstruccionAFN.cpp Automata.hpp AFN.hpp Postfija.hpp ConstruccionAFN.hpp  -linux
