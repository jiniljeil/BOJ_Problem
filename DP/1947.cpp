#include <iostream> 
#define SIZE 1000010
#define DIV 1000000000
using namespace std ;

// 교란 순열
// An = ( n - 1 ) * ( An-1 + An-2)
long long int dp[1000010] ; 
long long int N ; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0); 

    cin >> N ;
    
    dp[1] = 0; 
    dp[2] = 1; 
    for (int i = 3 ; i <= N ; i++ ) {
        dp[i] = (i - 1) * (dp[i - 1] % DIV + dp[i - 2] % DIV) % DIV;
    }
    cout << dp[N]; 
    return 0 ;
}