#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Nodo{
  int value;
  Nodo* sig;
  };

struct Pila{
   Nodo *tope=nullptr;
   int tam=0;
   bool esVacio(){
   if(tam==0){ return true;
   }
   return false;
   };
   
   int tamP(){
      return tam; }
   int topeP(){
      return tope->value; }
   void push(int x){
       tam++;
       Nodo* CurrentNode=new Nodo();
       CurrentNode->value=x;
       if(tope==nullptr){
            tope=CurrentNode;
        }else{
        Nodo* NodoAux=tope;
        tope=CurrentNode;
        tope->sig=NodoAux;
        CurrentNode=nullptr;
        }
        return;
        }
        void pop(){
	       if(tope==nullptr)return;
               tam--;
               Nodo* NodoEliminar=tope;
               tope=tope->sig;
               delete NodoEliminar;
               return;
               }
        
 };
int main(){
  vector<char> terminales;
string reglas;
map<char,string> noTerminales;
int numTerminales=0,numNoTerminales=0;
char terminal,noTerminal,simboloInicial;
cout<<"Ingresa el numero de simbolos terminales: ";
cin>>numTerminales;
cout<<"Ingresa los simbolos terminales"<<endl;
for(int i=0;i<numTerminales;i++){
  cout<<"terminal["<<i<<"]:";
  cin>>terminal;
  terminales.push_back(terminal);
}
cout<<"Ingresa el numero de simbolos noTerminales: ";
cin>>numNoTerminales;
for(int j=0;j<numNoTerminales;j++){
  cout<<"noTerminal["<<j<<"]: ";
  cin>>noTerminal;
  cout<<"\nIngresa sus producciones para este noTerminal:";
  cin>>reglas;
  noTerminales.insert(make_pair(noTerminal,reglas));
}
cout<<"Simbolo Inicial: ";
cin>>simboloInicial;


}
       
