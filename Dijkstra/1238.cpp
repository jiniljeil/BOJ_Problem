#include <iostream> 
#include <vector> 
#include <queue> 
#define INF 1e9 
using namespace std; 

int N, M, X ; 
vector<pair<int, int> > v[1001] ;
int DIST[1001] ; 
int dijsktra(int start) { 
    for(int i = 1 ; i <= N; i++) DIST[i] = INF ; 

    priority_queue<pair<int, int> > pq ; 

    pq.push(make_pair(-0, start)) ; 
    DIST[start] = 0 ; 

    while(!pq.empty()) {
        int curr_weight = -pq.top().first; 
        int curr_node = pq.top().second ; 

        pq.pop(); 

        for(int i = 0 ; i < v[curr_node].size(); i++) {
            int next_node = v[curr_node][i].first ;  
            int next_weight = v[curr_node][i].second ;  
            
            if ( DIST[next_node] > curr_weight + next_weight)  {
                DIST[next_node] = curr_weight + next_weight ; 
                pq.push(make_pair(-DIST[next_node], next_node)); 
            }
        }
    }

    return DIST[X] ; 
}

void Input()  {
    cin >> N >> M >> X ; 

    int a, b, c; 
    for(int i = 0 ; i < M; i++)  {
        cin >> a >> b >> c ; 
        v[a].push_back(make_pair(b, c)) ; 
    }
}

int main(void) {
    ios::sync_with_stdio(false) ; 
    cin.tie(0); 
    int result = 0 ; 

    Input() ; 
    // X 에서 각자 집으로 돌아가기 
    dijsktra(X); 

    int DIST_COPY[1001] ; 
    for (int i = 1; i <= N; i++) {
        DIST_COPY[i] = DIST[i] ; 
    } 

    // X에 도달하는데 걸리는 시간 + X에서 집으로 돌아가는데 걸리는 시간 MAX
    for (int i = 1 ; i <= N; i++) {
        result = max(result, DIST_COPY[i] + dijsktra(i)) ;  
    }
    cout << result << '\n';

    return 0;
}