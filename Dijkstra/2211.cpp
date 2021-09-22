#include <iostream> 
#include <queue>
#include <vector> 
#define INF 1e9
#define MAX 1001
using namespace std; 

int n, t; 
int a, b, c; 

vector<pair<int, int> > v[MAX]; 
vector<int> path[MAX] ; 
int dist[MAX]; 
int total = 0 ; 
void dijkstra(int start) { 
    priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > pq ; 
    // weight, vertex 

    for(int i = 1 ; i <= n; i++) dist[i] = INF ;

    pq.push(make_pair(0, start)); 
    dist[start] = 0; 

    while(!pq.empty()) {
        pair<int, int> curr = pq.top();  pq.pop(); 
        int weight = curr.first ; 
        int curr_v = curr.second ;

        for (int i = 0 ; i < v[curr_v].size() ; i++) {
            int next_v = v[curr_v][i].first; 
            int next_w = v[curr_v][i].second ; 

            if ( dist[next_v] > weight + next_w) { 
                dist[next_v] = weight + next_w ;
                pq.push(make_pair(dist[next_v], next_v)) ; 
                if (path[next_v].size() > 0) { 
                    path[next_v].pop_back() ; 
                    total--; 
                }
                path[next_v].push_back(curr_v); 
                total++; 
            }
        }
    }

    cout << total << '\n'; 
    
    for(int i = 1 ; i <= n; i++) {
        if (path[i].size() > 0) { 
            for (int j = 0 ; j < path[i].size(); j++) {
                cout << i << ' ' << path[i][j] << '\n'; 
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> n >> t; 

    for (int i = 0 ; i < t; i++) {
        cin >> a >> b >> c ; 

        v[a].push_back(make_pair(b, c));  
        v[b].push_back(make_pair(a, c)); 
    }

    dijkstra(1) ; 

    return 0 ;
}