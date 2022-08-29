#pragma once
#include <iostream>
#include <string>

using std::cout; 
using std::cin;
using std::endl; 
using std::string;

#define V 16

class PrimMST{
	private:
		int cantNodos;
		
	public:
		PrimMST();
		
		int llaveMinima(int[], bool[]);
		void funcionPrim(int[V][V]);
		void imprimir(int[], int[V][V]);
		void imprimirGrafi(int[V][V]);
		
		int getCantNodos();
		void setCantNodos(int);
};