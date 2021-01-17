#include <iostream>
#include <cstring>
 
using namespace std;
int static t[1000][1000];

int find_lcs(string X, string Y, int m, int n){
    if (m == 0 || n == 0){
        return 0;
    }
    if (t[m][n] != -1){
        return t[m][n];
    }
    if (X[m] == Y[n]){
        return t[m][n] = 1 + find_lcs(X, Y, m-1, n-1);
    }

    return t[m][n] = max(find_lcs(X, Y, m-1, n), find_lcs(X, Y, m, n-1));

};

int find_lcs_without_dp(string X, string Y, int m, int n){
    if (m == 0 || n == 0){
        return 0;
    }

    if (X[m] == Y[n]){
        return 1 + find_lcs_without_dp(X, Y, m-1, n-1);
    }

    return max(find_lcs_without_dp(X, Y, m-1, n), find_lcs_without_dp(X, Y, m, n-1));

};


int main(){
    string s1;
    string s2;
    memset(t, -1, sizeof(t));
    s1 = "adfshdskdskbkdsbk";
    s2 = "abedfghdcbjsdjdsb t";
    int count;
    // cout << find_lcs(s1, s2, s1.length(), s2.length());
    cout << find_lcs_without_dp(s1, s2, s1.length(), s2.length());

    return 12;
}