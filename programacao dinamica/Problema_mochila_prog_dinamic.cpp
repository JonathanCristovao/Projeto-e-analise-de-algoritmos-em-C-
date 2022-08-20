#include <bits/stdc++.h>
using namespace std;

int MFKnapsack(vector<int>& p, vector<int> &v, int n,int W){ 
 int i, j;
   int F[n][W];
   
   for (i = 0; i <= n; i++){
        for (j = 0; j <= W; j++){
           
           if (i==0 || j==0){
               F[i][j] = 0;
            }
           else if(p[i-1] <= j){
                 F[i][j] = max(v[i-1] + F[i-1][j-p[i-1]], F[i-1][j]);
           }else{
                 F[i][j] = F[i-1][j];
        }}
   }
   return F[n][W];
}
int main(){
	vector <int> p={2,1,3,2};
    vector<int> v={12,10,20,15};
    int p_mochila = 5;// peso maximo na mochila
    cout<< MFKnapsack(p,v,4,p_mochila);

	return 0;
}
