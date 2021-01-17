#include <iostream>
#include <cstring>
using namespace std;

int lcsubstring_dp(string X, string Y){
    int x_len = X.length();
    int y_len = Y.length();
    int a[x_len + 1][y_len + 1];
    int i, j, max = 0;

    // set all the rows and columns to -1
    memset(a, -1, sizeof(a));    

    // set first row and first column to 0
    for(i=0; i<=x_len; i++){
        a[i][0] = 0;
    }
    for(j=0; j<=y_len; j++){
        a[0][j] = 0;
    }

    for(i=1; i<=x_len; i++){
        for(j=1; j<=y_len; j++){
            if (X[i-1] == Y[j-1]){
                a[i][j] = 1 + a[i-1][j-1];
            }
            else{
                a[i][j] = 0; // the only difference with longest common substring
            }
        }
    }

    // we'll return the longest substring and which can be anywhere
    for(i=1; i<=x_len; i++){
        for(j=1; j<=y_len; j++){
            if(a[i][j] > max){
                max = a[i][j];
            }
        }
    }

    return max;
}

int main(){
    string s1, s2;
    // s1 = "abcdgefdfg";
    // s2 = "af0fdg";

    s1 = "abcabc";
    s2 = "bcdx";
                     
    cout << lcsubstring_dp(s1, s2);

}