#include <bits/stdc++.h>
#define SIZE 110
using namespace std ;

string A, B, C ;

int dp[SIZE][SIZE][SIZE] ; 
int main() { 
    ios::sync_with_stdio(0) ; cin.tie(0) ; 

    cin >> A >> B >> C ; 

    for (int i = 1; i <= A.size(); i++) { 
        for (int j = 1; j <= B.size(); j++) { 
            for (int k = 1; k <= C.size(); k++) { 
                if ( A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1] ) { 
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1; 
                } else{ 
                    dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
                }
            }
        }
    }
    cout << dp[A.size()][B.size()][C.size()] << '\n';
    return 0;
}