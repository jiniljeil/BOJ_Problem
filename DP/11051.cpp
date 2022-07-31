#include <iostream> 
#include <cstring> 
#define SIZE 1000
using namespace std ;

int N, K ; 
int dp[SIZE + 1][SIZE + 1] ; 

int main(void) { 
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; 

    cin >> N >> K ; 

    memset(dp, 0, sizeof(dp)) ; 
    
    dp[0][0] = 1; 
    dp[1][0] = 1; 
    dp[1][1] = 1;  

    for (int i = 2 ; i <= SIZE ; i++ ) { 
        dp[i][0] = 1; 
        for (int j = 1; j < i ; j++) { 
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007; 
        }
        dp[i][i] = 1 ; 
    }

    cout << dp[N][K] << '\n'; 
    return 0 ;
}