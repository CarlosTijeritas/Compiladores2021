/*EJERCICIO ANALISIS SINTACTICO POR DESCENSO RECURSIVO*/
/* P->aXPa
   P->bPX
   P->cX
   X->d
*/
/*ENTRADA: UNA CADENA
  SALIDA: VALIDACION DE LA CADENA(SI SE ACEPTO NO IMPRIME NADA,EN CASO CONTRARIO MUESTRA UN MENSAJE DE ERROR)*/

#include<iostream>
using namespace std;
char entrada[100]="adcda";
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
		    consumir('d');
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
		    consumir('c');X();
		    break;
    case 'd':
        consumir('d');
        break;
    default:
      cout<<"Ocurrio un Error"<<endl;
      exit(-1);
			
	}
}
int main(){
  P(); //mando a llamar a mi simbolo inicial
  return 0;
}
