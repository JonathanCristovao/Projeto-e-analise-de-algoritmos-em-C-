// Problema ciclo hamiltoniano usando backtracking em C++
#include <bits/stdc++.h>
using namespace std;

void printSolution(int sol[],int n){
	cout << "Solucao: \n";
	for (int i = 0; i < n; i++)
		cout << sol[i] << " ";
	
	cout << sol[0] << " "<< endl;
}
bool verificar_vertice(vector<vector<int>> &g,int sol[], int pos,int v){
	if (g[sol[pos-1]][v] == 0) //verificar se o vertice e adjacente ao adicionado
		return false;
	
   for (int i = 0; i < pos; i++)
		if (sol[i] == v)
			return false;

	return true;
}
void ciclo_ham(vector<vector<int>> &g,int sol[], int pos){
	int n = g.size();
	if (pos == n){
		if (g[sol[pos - 1]][sol[0]] == 1)
      printSolution(sol,n);
    }
	for (int v = 1; v < n; v++){
	
		if (verificar_vertice(g,sol, pos,v)){ 
			sol[pos] = v;
			ciclo_ham(g, sol, pos + 1);
			sol[pos] = -1;
		}
	}
}
int main(){
	vector<vector<int>> g {{0, 1, 0, 1, 0},     //  (0)--(1)--(2)
						   {1, 0, 1, 1, 1},     //  |    / \   |
						   {0, 1, 0, 0, 1},     //  |   /   \  |   
						   {1, 1, 0, 0, 1},     //  |  /     \ |
						   {0, 1, 1, 1, 0}};    //  (3)-------(4) 
	int n = g.size();
   int sol[n];
	for (int i = 0; i < n; i++)
		sol[i] = -1;

	sol[0] = 0;
	ciclo_ham(g,sol,1);

	return 0;
}