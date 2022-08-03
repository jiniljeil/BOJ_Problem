#include <iostream>
#include <cmath>
#define MAX 1001 
using namespace std; 

int N ; 
int num ; 
int prime[MAX] ; 
int answer = 0 ; 
void eratosthenes_sieve() {
    for (int i = 2 ; i < MAX; i++) {
        prime[i] = i ;
    }
    for (int i = 2; i < sqrt(MAX); i++ ) {
        // prime[i]이 0이면 이미 소수가 아니므로 continue
        if ( prime[i] == 0 ) continue ; 
        for (int j = i * i ; j < MAX ; j += i) { 
            prime[j] = 0 ;
        }
    }
}

int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 
    eratosthenes_sieve(); 
    cin >> N ; 
    for (int i = 0 ; i < N ; i++) {
        cin >> num ; 
        if (prime[num] != 0) answer++; 
    }

    cout << answer << '\n'; 
    return 0 ;
}