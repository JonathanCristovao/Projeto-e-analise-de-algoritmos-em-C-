#include <bits/stdc++.h>
using namespace std;

void imprime_tabuleiro(vector<vector<int>> &t, int N){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(t[i][j] != 0){
				cout <<" Q ";
			}else{
				cout <<" - ";
		    }}
		cout <<"\n";
	}
}
bool verificar_ataque(vector<vector<int> > & tab, int N, int lin, int col){
	int i, j;
	// verifica se ocorre ataque na linha ou coluna 
	for(i = 0; i < N; i++){
		if(tab[lin][i] == 1 ||tab[i][col] == 1)
			return false;
	}
	// diagonal 1
	for(i = lin, j = col; i >= 0 && j >= 0; i--, j--){
		if(tab[i][j] == 1)
			return false;
	}
	for(i = lin, j = col; i<N && j<N; i++, j++){
		if(tab[i][j] == 1)
			return false;
	}
   // diagonal 2
	for(i = lin, j = col; i >= 0 && j < N; i--, j++){
		if(tab[i][j] == 1)
			return false;
	}
	for(i = lin, j = col; i < N && j >= 0; i++, j--){
		if(tab[i][j] == 1)
			return false;
	}
	return true;
}

void n_rainhas(vector<vector<int> > & tab, int N, int col){ 
	if(col == N){
		cout << "Solucao: " <<endl;
		imprime_tabuleiro(tab, N);
		return; 
	}
		for(int i = 0; i < N; i++){
			// verifica se é seguro colocar a rainha naquela coluna
			if(verificar_ataque(tab, N, i, col)){ // se a condicao for verdade
				tab[i][col] = 1; // insere a rainha
			    n_rainhas(tab, N, col + 1); // chamada recursiva
				tab[i][col] = 0; //remove a rainha
		    }
	    }
}
int main(){
	int N = 4; // número de rainhas
    vector<vector<int>> tab {{0,0,0,0},
	                        {0,0,0,0},
					        {0,0,0,0},
	                        {0,0,0,0}};
	n_rainhas(tab, N, 0);
	return 0;
}
