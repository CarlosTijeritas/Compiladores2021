/* P->aXPa
   P->bPX
   P->dX
   X->c
*/
//checar error***
#include<iostream>
using namespace std;
char entrada[100]="acdc";
int actual=0;
void consumir(char caracter){
	if(caracter==entrada[actual]){
		actual++;
	}
	else{
	  exit(-1);
	}
}
void X(void){
  	switch(entrada[actual]){
		/*seleccionamos la produccion*/
		case 'c':
		    consumir('c');
		   
		    break;
    default:
      exit(-1);
			
	}
}
void P(void){
	switch(entrada[actual]){
		/*seleccionamos la produccion*/
		case 'a':
		    consumir('a');X();P();consumir('a');
		   
		    break;
		case 'b':
		    consumir('b');P();X();
		    break;
		case 'c':
		    X();
		    break;
    case 'd':
        consumir('d');P();
    default:
      exit(-1);
			
	}
}
int main(){
  P(); //mando a llamar a mi simbolo inicial
  return 0;
}
