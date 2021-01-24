#include<iostream>
#include <cstring>
using namespace std;

int dp[101][101];

int KS(int V[], int W[], int c, int n){
    if(n==0 || c==0){ return 0; } // base condition

    if (dp[c][n] != -1){
        return dp[c][n];
    }

    if (W[n-1] > c){
        return dp[c][n] = KS(V, W, c, n-1);
    }

    else{ // if (W[n-1] <= c) 
        return dp[c][n] = max(
                            V[n-1] + KS(V, W, c-W[n-1], n-1), 
                            KS(V, W, c, n-1)
                            );
    }   
    
}

int main(){
    int n=5, c=7;
    int V[] = {10, 5, 3, 10, 3};
    int W[] = {2, 3, 4, 1, 5};
    memset(dp, -1, sizeof(dp));

    int max_profit = KS(V, W, c, n);
    cout << max_profit;
    return max_profit;
    // return 1;
}