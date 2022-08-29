#include "PrimMST.h"

PrimMST::PrimMST(){
	
}

int PrimMST::getCantNodos()
{
	return cantNodos;
}
void PrimMST::setCantNodos(int _cantNodos)
{
	cantNodos = _cantNodos;
}

int PrimMST::llaveMinima(int llave[], bool revisado[])
{
	int min = 1000, indice; 
  
    for (int i = 0; i < cantNodos; i++) 
    {
    	if (revisado[i] == false && llave[i] < min) 
    	{
    		min = llave[i];
			indice = i; 
		}
	}
    return indice; 
}
void PrimMST::imprimir(int padre[], int grafi[V][V])
{
	int suma=0;
	cout<<"Conexiones \tPesos\n"; 
	for (int i = 1; i < cantNodos; i++)
	{
    	cout<<"    "<<padre[i]+1<<" - "<<i+1<<" \t  "<<grafi[i][padre[i]]<<" \n"; 	
    	suma+=grafi[i][padre[i]];
	}
	cout<<"\nLa suma de los pesos del camino mas corto es: "<<suma<<endl;
}    
void PrimMST::funcionPrim(int grafi[V][V])
{
    int padre[cantNodos],llaves[cantNodos];  
    bool revisado[cantNodos]; 
    
    for (int i = 0; i < cantNodos; i++) 
    {
    	llaves[i] = 1000;
		revisado[i] = false; 
	}
	
	llaves[0] = 0; 
    padre[0] = -1;
    
    for (int cont = 0; cont < (cantNodos - 1); cont++)
    { 
        int u = llaveMinima(llaves, revisado); 
        revisado[u] = true; 
        for (int i = 0; i < cantNodos; i++) 
        {
            if (grafi[u][i] && revisado[i] == false && grafi[u][i] < llaves[i]) 
            {
            	padre[i] = u;
				llaves[i] = grafi[u][i]; 
			}
		}
    }  
    imprimir(padre, grafi); 
}