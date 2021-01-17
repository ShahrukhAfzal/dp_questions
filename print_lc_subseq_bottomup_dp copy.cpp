#include <iostream>
#include <cstring>
#include<bits/stdc++.h> 

using namespace std;

string lcs_dp(string X, string Y){
    int x_len = X.length();
    int y_len = Y.length();
    int a[x_len + 1][y_len + 1];
    int i, j;

    // set all the rows and columns to -1
    memset(a, -1, sizeof(a));    

    // set first row and first column to 0
    for(i=0; i<=x_len; i++){
        a[i][0] = 0;
    }
    for(j=0; j<=y_len; j++){
        a[0][j] = 0;
    }

    // cout << x_len << " " << y_len << endl; 
    for(i=1; i<=x_len; i++){
        // cout << i << endl;
        for(j=1; j<=y_len; j++){
            if (X[i-1] == Y[j-1]){
                a[i][j] = 1 + a[i-1][j-1];
            }
            else{
                a[i][j] = max(a[i-1][j], a[i][j-1]);
            }
        }
    }

    string lcs = "";
    --i;
    --j;
    while(i > 0 &&  j > 0){
        if (X[i-1] == Y[j-1]){
            lcs.push_back(X[i-1]);
            i--;
            j--;
        }
        else{
            if (a[i-1][j]> a[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }

    return lcs;
}

int main(){
    string s1, s2;
    s1 = "abcdefdfg";
    s2 = "affdg";
    
    // s1 = "abcabc";
    // s2 = "bcd";
    string op_str;        
    op_str = lcs_dp(s1, s2);
    reverse(op_str.begin(), op_str.end()) ;
    cout << op_str;
}