#include <iostream> 
#define MAX 201
#define DIV 1000000000
using namespace std ;

typedef long long int ll ; 
int N, K ; 
ll DP[MAX][MAX] ; 
int main(void) {
    ios::sync_with_stdio(false) ; cin.tie(0) ; 
    cin >> N >> K ; 

    for (int i = 0 ; i <= N ; i++) { 
        DP[1][i] = 1 ; 
    }

    for (int k = 2 ; k <= K ; k++) { 
        for (int i = 0; i <= N; i++) { 
            for (int j = 0 ; j <= i ; j++) {
                DP[k][i] = DP[k][i] + DP[k - 1][j] ;
            }
            DP[k][i] %= DIV ;
        }
    }
    cout << DP[K][N] << '\n';
    return 0;
}