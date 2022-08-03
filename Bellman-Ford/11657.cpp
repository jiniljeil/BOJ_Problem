#include <iostream> 
#include <limits.h>
#include <vector> 
#define MAX 501
#define INF INT_MAX

typedef long long ll ; 

using namespace std; 

int N, M ; 
int A, B, C; 
vector<pair<int, int> > V[MAX];
ll DIST[MAX] ; 
bool cycle = false; 

int bellmanFord() { 
    for (int i = 1; i <= N; i++) DIST[i] = INF ; 

    DIST[1] = 0 ; 
    for (int i = 1; i <= N ; i++) { 
        for (int j = 1; j <= N; j++) { 
            for (int k = 0 ; k < V[j].size(); k++) {
                ll to = V[j][k].first ; 
                ll weight = V[j][k].second ; 

                if ( DIST[j] != INF && DIST[to] > DIST[j] + weight ) { 
                    DIST[to] = DIST[j] + weight ;

                    if ( i == N ) { // 음수 사이클 발생 
                        return -1 ; 
                    }
                }  
            }
        }
    }

    return 1 ; 
}

void Input() { 
    cin >> N >> M ; 

    for (int i = 0 ; i < M ; i++) { 
        cin >> A >> B >> C ; 
        V[A].push_back(make_pair(B, C)); 
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0) ; 

    Input(); 
    int result = bellmanFord() ; 

    if ( result == -1 ) { 
        cout << "-1" << '\n' ; 
    } else { 
        for (int i = 2; i <= N ; i++) { 
            if ( DIST[i] == INF ) { 
                cout << "-1" << '\n'; 
            } else { 
                cout << DIST[i] << '\n'; 
            } 
        }
    }

    return 0 ;
}