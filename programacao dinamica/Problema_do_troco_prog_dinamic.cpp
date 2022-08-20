#include<bits/stdc++.h>
using namespace std;

//n e o numero de denominacoes
int troco(vector <int> & moedas, int n_d) {
 int n_moedas = moedas.size();
 int dp[n_d]; 
 dp[0] = 0;
  
  for(int i=1; i<=n_d; i++) {
      int troco = INT_MAX;
      for(int j=0; j<n_moedas; j++){
         if(moedas[j]<=i){
           
            troco = min(troco, dp[i-moedas[j]]+1);
            dp[i] =troco;
            cout<<dp[i]<<endl;
         }
       }
    }
return dp[n_d];
}
int main() {
  vector<int> D = {1, 5, 10, 25, 50 , 100};
  printf("%d\n", troco(D, 68)); //68= 50+10+5+1+1+1  total 6 moedas.
  return 0;
}