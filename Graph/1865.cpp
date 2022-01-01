#include <iostream> 
#include <vector> 
#include <limits.h>
#define MAX 501 
#define INF INT_MAX
using namespace std; 

int TC, N, M, W ; 
int S, E, T ; 
vector<pair<int, int> > v[MAX]; // 웜홀 존재 여부, 연결된 노드 
long long DIST[MAX] ; 

void bellmanFord() { 
    for (int i = 1 ; i <= N ; i++) DIST[i] = INF ; 

    bool cycle = false; 

    DIST[1] = 0 ; 
    for (int i = 1; i <= N ; i++) { 
        for (int j = 1 ; j <= N; j++) { 
            for (int k = 0 ; k < v[j].size(); k++) { 
                int to = v[j][k].first ; 
                int weight = v[j][k].second ; 

                if ( DIST[to] > DIST[j] + weight ) { 
                    DIST[to] = DIST[j] + weight ; 
                    if ( i == N ) { 
                        cycle = true ; 
                    }
                }
            }
        }
    }

    if ( cycle ) {
        cout << "YES" << '\n' ; 
    }
    else {
        cout << "NO" << '\n'; 
    }
} 

void Input() {
    cin >> N >> M >> W ;  
    // 도로 
    for (int j = 0 ; j < M ; j++) {
        cin >> S >> E >> T ; 
        v[S].push_back(make_pair(E, T)); 
        v[E].push_back(make_pair(S, T)); 
    }
    // 웜홀 
    for (int j = 0 ; j < W ; j++) { 
        cin >> S >> E >> T ; 
        v[S].push_back(make_pair(E, -T)); 
    }
}
int main(void) { 
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ;

    cin >> TC ; 

    for (int i = 0 ; i < TC ; i++) { 
        Input() ; 
        bellmanFord() ;
        for (int j = 1 ; j <= N; j++ ) v[j].clear() ;  
    }
    return 0 ; 
}