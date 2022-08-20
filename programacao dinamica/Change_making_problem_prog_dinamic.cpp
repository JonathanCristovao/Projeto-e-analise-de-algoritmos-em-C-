
#include<bits/stdc++.h>
using namespace std;

//n e o numero de denominacoes
int ChangeMaking(vector <int> & D, int n) {
  int f[n+1];
  int i, j;
  f[0] = 0;

  for(j=1; j<=n; j++) {
    int min_value = INT_MAX;
   cout<<"f["<<j<<"]="<<endl;;
	  
    for(i=1; i<=n; i++){
       if(j >= D[i]){
        min_value = min(f[j-D[i]]+1 ,min_value);
       }
    }
    cout<<min_value<<endl;
    f[j] = min_value;
  }
  return f[n];
}

int main() {
  vector<int> D = {0,1,3,4};
  cout<<"Minimo de moedas: "<<ChangeMaking(D,6); 
  return 0;
}
