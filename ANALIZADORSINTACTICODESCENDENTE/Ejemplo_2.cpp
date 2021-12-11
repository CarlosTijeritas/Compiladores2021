/*FLORES MARTINEZ CARLOS ALBERTO*/
/*EJERCICIO ANALISIS SINTACTICO POR DESCENSO RECURSIVO*/
/* P->dXzAP
   P->zAd
   A->fX
   X->xy

*/
/*ENTRADA: UNA CADENA
  SALIDA: VALIDACION DE LA CADENA(SI SE ACEPTO NO IMPRIME NADA,EN CASO CONTRARIO MUESTRA UN MENSAJE DE ERROR)*/

#include<iostream>
using namespace std;
char entrada[100]="dxyzfxyzfxyd";
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
		    consumir('x');
        consumir('y');
}
void A(void){
        consumir('f');
        X();
}

void P(void){
	switch(entrada[actual]){
		/*seleccionamos la produccion*/
    case 'd':
        consumir('d');X();consumir('z');
        A();P();
        break;
    case 'z':
        consumir('z');A();consumir('d');
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
