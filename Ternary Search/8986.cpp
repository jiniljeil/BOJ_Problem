#include <iostream> 
#include <stdint.h>
#include <vector>
#include <math.h> 
using namespace std ;
vector<int64_t> V ;
int N ;  

int64_t func(int64_t p) { 
    int64_t r = 0 ; 
    for (int i = 1 ; i < N ; i++) { 
        r += abs(p * i - V[i]) ; 
    }
    return r ;
}

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N ; 
    for (int i = 0; i < N ; i++) { 
        int64_t x; cin >> x ; 
        V.push_back(x) ; 
    }
    
    int64_t left = 0, right = V[N - 1]; 

    while ( right - left >= 3 ) { 
        int64_t p = (left * 2 + right) / 3 ; 
        int64_t q = (left + right * 2) / 3 ; 
        if ( func(p) <= func(q) ) right = q ;
        else left = p ; 
    }

    int64_t result = 1e18 ; 
    for (int64_t i = left ; i <= right ; i++) { 
        result = min(func(i), result) ; 
    }
    cout << result << '\n' ;
     
    return 0 ;
}