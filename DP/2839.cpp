#include <iostream> 
#include <algorithm>
using namespace std ;

int N ; 
int DP[5010] ; 

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N ; 

    DP[3] = 1; DP[5] = 1 ;
    for (int i = 6 ; i <= N; i++) {
        if ( DP[i - 3] ) DP[i] = DP[i - 3] + 1 ; 
        if ( DP[i - 5] ) DP[i] = DP[i] ? min(DP[i], DP[i - 5] + 1) : DP[i - 5] + 1 ; 
    }
    if ( DP[N] == 0 ) cout << -1 << '\n'; 
    else cout << DP[N] << '\n'; 
    return 0 ;
}