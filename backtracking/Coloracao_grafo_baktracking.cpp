// Problema de coloracao de grafos com m cores usando backtracking
#include <bits/stdc++.h>
using namespace std;

void printSolution(int color[],int n){
	cout << "As cores atribuidas sao:"<<"\n";
	for(int i = 0; i < n; i++)
		cout <<" "<< color[i] <<" "<< "\n";
}
bool verificar_cor(vector<vector<int>> &g,int color[],int v, int c){
	for(int i = 0; i < g.size(); i++)
		if (g[v][i] && c == color[i])
     		return false;
	return true;
}
void coloracao_grafo(vector<vector<int>> &g, int m,int color[], int v,int n){
	
   printSolution(color,n);
   for(int c = 1; c <= m; c++){
		if (verificar_cor( g, color,v, c)){
			color[v] = c;
		  coloracao_grafo(g, m, color, v + 1,n);
			color[v] = 0;
		}
	}
}
int main(){
   vector<vector<int>> g{{ 0, 1, 1, 1 },   //  (3)---(2)
						 { 1, 0, 1, 0 },   //   |   / |
						 { 1, 1, 0, 1 },   //   | /   |
					     { 1, 0, 1, 0 }};  //  (0)---(1)             
						
	int m = 3; // numero de cores
	int n = g.size();
   int color[n];
	for(int i = 0; i < n; i++)
		color[i] = 0;
	coloracao_grafo(g,m,color,0,n);
	return 0;
}