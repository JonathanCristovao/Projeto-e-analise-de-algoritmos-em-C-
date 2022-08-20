//  Fibonacci em C++   
#include<bits/stdc++.h>
using namespace std;

int fib_pd(int n){
	// Fibonacci com a programação dinamica
	int f[n + 2];
	int i;
	f[0] = 0;
	f[1] = 1;
	for(i = 2; i <= n; i++){
		f[i] = f[i - 1] + f[i - 2];
	}
   return f[n];
   }
int fib_rec(int n){
    // Fibonacci sem a programação dinamica
    if(n<=1){
        return n;
    }else{
        return fib_rec(n-1)+fib_rec(n-2);
    }
}
int main (){
	
	int n = 6;
	//cout<<fib_rec(n);
	cout << fib_pd(n);
	return 0;
}
