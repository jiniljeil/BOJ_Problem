#include <iostream> 
#include <climits>
#define MAX 401
#define INF 1e8 

using namespace std ; 

int V, E ; 
int a, b, c ;
long long DIST[MAX][MAX] ; 

void Input() { 
    cin >> V >> E ; 

    for (int i = 0 ; i < V ; i++) { 
        for (int j = 0 ; j < V ; j++) { 
            if ( i == j ) DIST[i][j] = 0 ; 
            else DIST[i][j] = INF ; 
        }
    }

    for (int i = 0 ; i < E ; i++) { 
        cin >> a >> b >> c ; 
        DIST[a - 1][b - 1] = c ; 
    }
}

void Floyd_warshall() { 
    long long answer = INF ; 
    for (int k = 0 ; k < V; k++) {
        for (int i = 0 ; i < V ; i++) {
            for (int j = 0 ; j < V ; j++) { 
                DIST[i][j] = min(DIST[i][j], DIST[i][k] + DIST[k][j]) ; 
            }
        }
    }
    
    for (int i = 0 ; i < V ; i++) { 
        for (int j = i + 1 ; j < V ; j++)  {
            if ( DIST[i][j] != INF && DIST[j][i] != INF ) { 
                answer = min(answer, DIST[i][j] + DIST[j][i]) ; 
            }
        }
    } 
    if ( answer == INF ) { 
        cout << "-1" << '\n' ; 
    } else {
        cout << answer << '\n' ;
    }
}
int main(void) {
    ios::sync_with_stdio(false) ; cin.tie(0) ; 
    
    Input() ;
    Floyd_warshall(); 
    return 0 ;
}