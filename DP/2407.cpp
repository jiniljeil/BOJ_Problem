#include <iostream>
#include <cmath> 
#define MAX 101 
using namespace std ;

int N, M; 
__uint128_t C[MAX][MAX] ; 

__uint128_t Combination(int n, int m) { 
    if ( C[n][m] > 0 ) return C[n][m] ;
    if ( m == 1 ) return n ; 
    if ( n == m || m == 0 ) return 1 ; 

    if ( m > n/2 ) { 
        m = n - m ; 
    }
    
    return C[n][m] = Combination(n -1, m - 1) + Combination(n - 1, m) ; 
}

void Input() { 
    cin >> N >> M ; 
}

int main(void) {
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; 

    Input() ;
    C[1][1] = C[1][2] = 1 ; C[2][1] = 2 ; 
    __uint128_t result =  Combination(N,M) ; 

    string r = ""; 
    string f = to_string((long long) (result /  (__uint128_t) pow(10, 15))) ; 
    string s = to_string((long long) (result % (__uint128_t) pow(10, 15))) ; 
    if ( f == "0") { 
        r = s ; 
    } else {
        r = f + s; 
    }
    cout <<  r  << '\n';
    return 0 ;
}