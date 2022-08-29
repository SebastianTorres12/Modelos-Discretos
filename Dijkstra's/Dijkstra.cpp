#include<stdio.h>
#include <iostream>
#include<conio.h>
#define INFINITO 9999
#define MAX 16

void dijkstra(int G[MAX][MAX],int n,int nodo_Origen);

int main()
{
	int G[MAX][MAX],i,j,n,u,opc;
	printf("Ingresa no. de vertices:");
	scanf("%d",&n);
	printf("\nIngresa la matriz de adyacencia:\n"); //FORMA DE REPRESENTACION
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
			
	do{
		system("cls");
		printf("\nIngresa el nodo de partida o nodo Origen:");
		scanf("%d",&u);
		dijkstra(G,n,u);
		printf("\n\nDesea Salir? \n1.Si 2.No\n");
		scanf("%d",&opc);
	}while(opc!=1);
	
	
	return 0;
}

void dijkstra(int G[MAX][MAX],int n,int nodo_Origen)
{

	int coste[MAX][MAX],distancia[MAX],predecesor[MAX];
	int visitado[MAX],count,mindistancia,nodosiguiente,i,j;
	
	//predecesor[] matriz que guarda el predecesor de cada nodo
	//te da el numero de nodos visitados
	//creamos la matriz coste
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				coste[i][j]=INFINITO;
			else
				coste[i][j]=G[i][j];
	
	//inicilizamos predecesor[],distancia[] y visitado[]
	for(i=0;i<n;i++)
	{
		distancia[i]=coste[nodo_Origen][i];
		predecesor[i]=nodo_Origen;
		visitado[i]=0;
	}
	
	distancia[nodo_Origen]=0;
	visitado[nodo_Origen]=1;
	count=1;
	//count sirve para contar el numero de nodos visitados
	while(count<n-1)
	{
		mindistancia=INFINITO;
		
		//nodosiguiente recibe el nodo de la minima distancia
		for(i=0;i<n;i++)
			if(distancia[i]<mindistancia&&!visitado[i])
			{
				mindistancia=distancia[i];
				nodosiguiente=i;
			}
			//verifica is existe un mejor camino alrededor de nodosiguiente		
			visitado[nodosiguiente]=1;
			for(i=0;i<n;i++)
				if(!visitado[i])
					if(mindistancia+coste[nodosiguiente][i]<distancia[i])
					{
						distancia[i]=mindistancia+coste[nodosiguiente][i];
						predecesor[i]=nodosiguiente;
					}
		count++;
	}

	//Imprimimos el camino y la distanca de cada nodo
	for(i=0;i<n;i++)
		if(i!=nodo_Origen)
		{
			printf("\nCosto del recorrido %d = %d",i,distancia[i]);
			printf("\nCamino= %d ",i);
			
			j=i;
			do
			{
				j=predecesor[j];
				printf("<- %d",j);
			}while(j!=nodo_Origen);
	}
} 
