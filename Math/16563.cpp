#include <iostream> 
#include <cmath> 
#include <cstring>
#include <vector> 
#include <algorithm>
#define MAX_N 5000000
using namespace std ; 

int N, k ;  
int isPrime[MAX_N + 1] ; 
vector<int> prime ; 
void eratosthenes() {
    for (int i = 2 ; i <= MAX_N ; i++) isPrime[i] = i ; 
    isPrime[0] = isPrime[1] = -1 ; 
    int sqrtn = int(sqrt(MAX_N)) ;
    for (int i = 2; i <= sqrtn ; i++) {
        if (isPrime[i] == i) { 
            for (int j = i * i ; j <= MAX_N ; j += i) { 
                isPrime[j] = i ; 
            }
        }
    }
}

void factor(int n) { 
    vector<int> ret ;     

    while(n > 1) { 
        ret.push_back(isPrime[n]) ; 
        n /= isPrime[n] ; 
    }

    // sort(ret.begin(), ret.end()) ; 

    for (int i = 0 ; i < ret.size(); i++) { 
        cout << ret[i] << ' ' ;  
    }
    cout << '\n' ; 
}   
int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 

    eratosthenes() ; 

    cin >> N  ;
    for (int i = 0 ; i < N; i++) { 
        cin >> k ; 
        factor(k) ; 
    }

    return 0 ; 
}