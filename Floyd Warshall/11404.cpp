#include <iostream> 
#include <climits>
#define INF INT_MAX 
#define MAX 101 
using namespace std ; 

int n, m ; 
long long a, b, c ; 
long long DIST[MAX][MAX] ; 

void Init() { 
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ;j++)  {
            DIST[i][j] = INF ; 
        }
        DIST[i][i] = 0 ; 
    }
}

void floyd_warshall() { 
    for (int k = 0 ; k < n ; k++) { 
        for (int i = 0 ; i < n ; i++) { 
            for (int j = 0 ; j < n; j++) {
                DIST[i][j] = min(DIST[i][j], DIST[i][k] + DIST[k][j]) ; 
            }
        }
    }
}
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ;
    
    cin >> n >> m ; 

    Init() ; 

    for (int i = 0 ; i < m ; i++) { 
        cin >> a >> b >> c ; 
        DIST[a - 1][b - 1] = min(DIST[a - 1][b - 1], c) ;
    }
    
    floyd_warshall() ; 

    for (int i = 0 ; i < n ; i++) { 
        for (int j = 0 ; j < n ;j++) { 
            if ( DIST[i][j] != INF) cout << DIST[i][j] << ' ' ; 
            else cout << "0" << ' ' ;
        }
        cout << '\n'; 
    }
    return 0 ;
}