#include <bits/stdc++.h> 
#define SIZE 1010
#define DIV 1000000003 
using namespace std ; 

typedef long long ll ;

int N, K; 
ll ans ; 
ll dp[SIZE][SIZE] ;

int main() { 
    ios::sync_with_stdio(0) ; cin.tie(0) ;

    cin >> N >> K ;

    for (int i = 1 ; i <= N ; i++) { 
        dp[i][1] = i ; dp[i][0] = 0 ; 
    }

    dp[3][2] = 0 ; 
    for (int i = 4 ; i <= N ; i++) { 
        for (int j = 2 ; j <= K ; j++) { 
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % DIV ; 
        }
    }

    cout << dp[N][K] << '\n'; 
    return 0 ;
}