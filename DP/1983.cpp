#include <bits/stdc++.h>
#define SIZE 401
using namespace std ;

vector<int> A[2] ;
int dp[SIZE][SIZE][SIZE] ; 
int N, R ; 
int A1_SIZE, A2_SIZE ;

int func(int n, int a1, int a2) { 
    if ( a1 == A1_SIZE || a2 == A2_SIZE ) return 0; 

    int& ret = dp[n][a1][a2]; 
    if ( ret != -1e9 ) return ret ; 

    // 단순 곱셈
    ret = func(n + 1, a1 + 1, a2 + 1) + A[0][a1] * A[1][a2];
    // A1에서 0을 썼을 경우 
    if ( N > n - a1 + A1_SIZE ) ret = max(ret, func(n + 1, a1, a2 + 1)) ;
    // A2에서 0을 썼을 경우 
    if ( N > n - a2 + A2_SIZE ) ret = max(ret, func(n + 1, a1 + 1, a2)) ;
    return ret ; 
}

int main(void) { 
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N ;
    for (int i = 0 ; i < 2 ; i++){ 
        for (int j = 0 ; j < N ; j++) { 
            int k ; cin >> k;
            if ( k != 0 ) A[i].push_back(k); 
        }
    }
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0; j < N ; j++) 
            for (int k = 0 ; k < N ; k++) 
                dp[i][j][k] = -1e9; 
    
    A1_SIZE = A[0].size(); 
    A2_SIZE = A[1].size();

    cout << func(0, 0, 0) << '\n';
    return 0 ; 
}