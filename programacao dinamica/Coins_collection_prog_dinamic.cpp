// robo coletor de moedas programacao dinamica c++
#include <bits/stdc++.h>
using namespace std;

int Coin(vector<vector<int>> c, int n){
	int m =6;
	int i,j;
	int f[m][n];
	f[0][0]= c[0][0];
	f[1][1]= c[1][1];

    for (i=2;i<m;i++){
	    f[1][i]=f[1][i - 1]+ c[1][i];
	    f[i][1]=f[i - 1][1]+c[i][1];
	}
	for(i=2;i<n;i++){
		for(j=2;j<m;j++){
			f[i][j]=max(f[i - 1][j] , f[i][j - 1] ) + c[i][j];  
        cout<<f[i][j]<< " " ;
		}
		cout<<""<<endl;
	}
	
return f[n-1][m-1];  

}

int main(){
	// grafo com os custos de cada caminho
	vector<vector<int>> c {{0, 0, 0, 0, 1,0},
                               {0, 1, 0, 1, 0,0},
                               {0, 0, 0, 1, 0,1},
                               {0, 0, 1, 0, 0,1},
                               {1, 0, 0, 0, 1,0}};
	int linha = 5;		//matriz[linha][coluna]
	cout<<Coin(c, linha)<< endl;
	return 0;
}
				 

