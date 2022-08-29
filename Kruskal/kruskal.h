#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;

class Kruskal
{
	private:
		int cn;
		vector<vector<int>> ady;
	public:
		vector<vector<int>> getAdy();
		void setAdy(vector<vector<int>>);
		int getCn();
		void setCn(int);
		vector<vector<int>> kruskal();
};
