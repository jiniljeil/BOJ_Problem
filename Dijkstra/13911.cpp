#include <iostream> 
#include <vector> 
#include <queue> 
#include <climits> 
#define MAX 10010 
using namespace std ;

int V, E, M, S; 
int u, v, w, x, y; 
vector<pair<int, int> > G[MAX] ;
unsigned long long answer = __LONG_LONG_MAX__ ; 
priority_queue<pair<int, int> > pq ;

void Dijkstra(int DIST[MAX]) { 

    while (!pq.empty()) { 
        int curr_w = -pq.top().first ; 
        int curr_v = pq.top().second ; 

        pq.pop() ; 

        for (int i = 0 ; i < G[curr_v].size() ; i++) { 
            int next_v = G[curr_v][i].first ; 
            int next_w = G[curr_v][i].second ; 

            if ( DIST[next_v] > curr_w + next_w ) { 
                DIST[next_v] = curr_w + next_w ;  
                pq.push(make_pair(-DIST[next_v], next_v)) ; 
            }
        }
    }
}

int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 
    int M_DIST[MAX] ; 
    int S_DIST[MAX] ; 

    cin >> V >> E ; 
    for (int i = 0 ; i < E ; i++) { 
        cin >> u >> v >> w ; 
        G[u].push_back(make_pair(v, w)) ; 
        G[v].push_back(make_pair(u, w)) ; 
    }

    for (int i = 1 ; i < MAX ; i++) M_DIST[i] = INT_MAX ;
    cin >> M >> x ; 
    for (int i = 0, k ; i < M ; i++) { 
        cin >> k ; 
        M_DIST[k] = 0 ; pq.push(make_pair(-0, k));
    }
    Dijkstra(M_DIST) ; 

    for (int i = 1 ; i < MAX ; i++) S_DIST[i] = INT_MAX ;
    cin >> S >> y ; 
    for (int i = 0, k; i < S; i++) { 
        cin >> k ; 
        S_DIST[k] = 0 ; pq.push(make_pair(-0, k)) ; 
    }

    Dijkstra(S_DIST) ; 

    for (int i = 1 ; i <= V; i++) { 
        if ( M_DIST[i] == INT_MAX || S_DIST[i] == INT_MAX || M_DIST[i] > x || S_DIST[i] > y) continue; 
        if ( M_DIST[i] == 0 || S_DIST[i] == 0 ) continue ; 
        
        answer = min(answer, 1ULL * (M_DIST[i] + S_DIST[i])) ; 
    }

    if ( answer == __LONG_LONG_MAX__ ) cout << "-1" << '\n';
    else cout << answer << '\n'; 
    return 0;
}

