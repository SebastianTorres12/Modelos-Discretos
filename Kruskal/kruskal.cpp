#include "Kruskal.h"


vector<vector<int>> Kruskal::getAdy()
{
	return ady;
}

void Kruskal::setAdy(vector<vector<int>> ad)
{
	ady=ad;
}
int Kruskal::getCn()
{
	return cn;
}
void Kruskal::setCn(int c)
{
	cn=c;
}

vector<vector<int>> Kruskal:: kruskal(){
    vector< vector<int> > adyacencia = this->ady;
    vector< vector<int> > arbol(cn);
    vector<int> pertenece(cn); // indica a que árbol pertenece el nodo
    
    for(int i = 0; i < cn; i++){
        arbol[i] = vector<int> (cn, 0);
        pertenece[i] = i;
    }

    int nodoA;
    int nodoB;
    int arcos = 1;
    while(arcos < cn){
        // Encontrar  el arco mínimo que no forma ciclo y guardar los nodos y la distancia.
        int min = (int) INFINITY;
        for(int i = 0; i < cn; i++)
            for(int j = 0; j < cn; j++)
                if(min > adyacencia[i][j] && adyacencia[i][j]!=0 && pertenece[i] != pertenece[j]){
                    min = adyacencia[i][j];
                    nodoA = i;
                    nodoB = j;
                }
        
        // Si los nodos no pertenecen al mismo árbol agrego el arco al árbol mínimo.
        if(pertenece[nodoA] != pertenece[nodoB]){
            arbol[nodoA][nodoB] = min;
            arbol[nodoB][nodoA] = min;

            // Todos los nodos del árbol del nodoB ahora pertenecen al árbol del nodoA.
        	int temp = pertenece[nodoB];
        	pertenece[nodoB] = pertenece[nodoA];
        	for(int k = 0; k < cn; k++)
        		if(pertenece[k] == temp)
        			pertenece[k] = pertenece[nodoA];
            
            arcos++;
        }
    }
    return arbol;
}
