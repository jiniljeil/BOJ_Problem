#include <iostream> 
#include <cmath> 
using namespace std ;

int prime[10001] ; 
int M, N ; 
void eratosthenes_sieve() {
    for (int i = 2 ; i <= N; i++) {
        prime[i] = i ;
    }
    for (int i = 2; i < sqrt(N); i++ ) {
        // prime[i]이 0이면 이미 소수가 아니므로 continue
        if ( prime[i] == 0 ) continue ; 
        for (int j = i * i ; j <= N ; j += i) { 
            prime[j] = 0 ;
        }
    }
}

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> M >> N ; 

    eratosthenes_sieve() ;

    long long answer = 0 ; 
    int mini = 0 ; 
    for (int i = M ; i <= N ; i++) { 
        if ( prime[i] ) {
            if ( mini == 0 ) mini = i ; 
            answer += i ; 
        }
    }

    if ( answer == 0 ) { 
        cout << -1 << '\n' ; 
    } else { 
        cout << answer << '\n' << mini << '\n'; 
    }
    return 0 ;
}