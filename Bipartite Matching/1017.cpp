#include <iostream> 
#include <vector> 
#include <cstring> 
#include <algorithm>
#define MAX 50010
#define SIZE 1001
using namespace std ;

int N ; 
vector<int> num_v ; 
vector<int> V[SIZE] ; 
bool visited[SIZE] ; 
int matched[5IZE] ; 
bool prime[MAX] ; 
void eratosthenes_sieve() {
    for (int i = 2 ; i <= MAX ; i++) prime[i] = true ; 
    for (int i = 2 ; i <= sqrt(MAX) ; i++) {
        if ( prime[i] ) {
            for (int j = i * i ; j <= MAX ; j += i) { 
                prime[j] = false ; 
            }
        }
    }
}

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    eratosthenes_sieve() ; 

    cin >> N  ;

    int t = 0 ; 
    for (int i = 0 ; i < N ;i++) { 
        cin >> t ; 
        num_v.push_back(t);  
    }

    sort(num_v.begin(), num_v.end()) ; 

    for (int i = 0 ; i < N ; i++) {
        for (int j = i + 1 ; j < N ; j++) {
            if ( prime[ num_v[i] + num_v[j] ]) { 
                V[num_v[i]].push_back(num_v[j]) ; 
            }
        }
    }

    for (int i = 1 ; i < SIZE ; i++) { 
        if ( !V[i].empty() ) {  
            if (dfs(i)) { 
                
            }
        }
    }
    return 0 ; 
} 