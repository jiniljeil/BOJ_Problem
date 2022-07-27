#include <iostream> 

using namespace std ;

int dp[101][11] ; 
int N ; 
int main(void) { 
    ios::sync_with_stdio(false) ;
    cin.tie(0); 

    cin >> N ; 

    // N = 1 
    for (int i = 1 ; i <= 9; i++) { 
        dp[1][i] = 1;
    }
    
    // N >= 2 
    for (int i = 2; i <= N ; i++) { 
        for (int j = 0; j <= 9; j++) { 
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000  ;
        }
    }

    long long result = 0 ; 
    for (int i = 0 ; i <= 9 ; i++) { 
        result += dp[N][i] ; 
    }

    cout << result % 1000000000 << '\n'; 
    return 0 ; 
}