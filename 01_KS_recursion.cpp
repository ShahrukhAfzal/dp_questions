#include <iostream>

using namespace std;

int KS(int V[], int W[], int n, int c){
    // base condition
    if(n==0 || c==0){
        return 0;
    }

    // choice diagram
    if (W[n-1] > c){
        return KS(V, W, n-1, c);
    }
    else{
        return max(V[n-1] + KS(V, W, n-1, c-W[n-1]), KS(V, W, n-1, c));
    }
}


int main(){
    int V[10] = {10, 5, 3, 10, 3};
    int W[10] = {4, 3, 4, 1, 5};
    int n=5, c=7;
    int result;
    result = KS(V, W, n, c);
    cout << result;
}