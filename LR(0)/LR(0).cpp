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
       
