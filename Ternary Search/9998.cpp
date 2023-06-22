#include <iostream> 
#include <algorithm> 
#include <cmath> 
#define SIZE 300010

using namespace std ;
typedef long long ll ; 

int N ; 
ll A[SIZE], B[SIZE]; 

ll f(ll x) { 
    ll ret = 0 ; 
    for (int i = 0 ; i < N ; i++) { 
        ll height = x + abs( N / 2 - i ) ; 
        ret += abs(height - A[i]) ;
        ret += abs(height - B[i]) ; 
    }
    return ret ;
}

int main(void) { 
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> N ; 

    for (int i = 0 ; i < N ; i++) cin >> A[i] ; 
    for (int i = 0 ; i < N ; i++) cin >> B[i] ; 

    ll low = 0, high = 0 ; 
    for (int i = 0 ; i < N ; i++) 
        high = max(high, max(A[i], B[i])) ; 

    while ( low < high ) { 
        ll mid = (low + high) / 2 ; 
        if ( f(mid) < f(mid + 1) ) high = mid ;
        else low = mid + 1 ;
    }

    cout << f(low) << '\n' ; 
    return 0;
}