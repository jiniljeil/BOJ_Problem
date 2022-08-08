#include <iostream> 
#include <vector> 
#include <queue> 
#include <stack> 
#define MAX 1001
#define INF 1e8
using namespace std; 

int n, m ; 
int start_v, end_v; 
vector<pair<int, int> > V[MAX] ; 
int DIST[MAX] ; 
int PATH[MAX] ; 
stack<int> S; 
void dijkstra() { 
    for (int i = 1 ; i <= n; i++ ) DIST[i] = INF;
    priority_queue<pair<int, int> > pq ; 
    pq.push(make_pair(-0, start_v)) ; 
    DIST[start_v] = 0 ; 
    while( !pq.empty())  {
        int weight = -pq.top().first; 
        int curr_v = pq.top().second ; 
        pq.pop() ;
        
        if ( DIST[curr_v] < weight ) continue ; 
        
        for (int i = 0; i < V[curr_v].size(); i++) { 
            int next_v = V[curr_v][i].first ; 
            int next_w = V[curr_v][i].second ; 

            if ( DIST[next_v] > next_w + weight) { 
                DIST[next_v] = next_w + weight ; 
                PATH[next_v] = curr_v ; 
                pq.push(make_pair(-DIST[next_v], next_v)) ;
            }
        }
    }

    cout << DIST[end_v] << '\n'; 

    int endpoint = end_v ; 
    while(endpoint) { 
        S.push(endpoint) ;
        endpoint = PATH[endpoint];
    }
    cout << S.size() << '\n'; 
    while(!S.empty()) { 
        cout << S.top() << ' ' ; 
        S.pop(); 
    }
    cout << '\n'; 
}

int main(void) {
    ios::sync_with_stdio(false) ; cin.tie(0) ;

    cin >> n >> m ; 
    for (int i = 1 ; i <= m ; i++) { 
        int a, b, c ; cin >> a >> b >> c ; 
        V[a].push_back(make_pair(b, c)) ; 
    }
    cin >> start_v >> end_v ; 

    dijkstra() ;
    return 0;
}