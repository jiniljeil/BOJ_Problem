#include <iostream> 
#include <vector>
#include <queue>
#include <climits>
using namespace std ; 
int N, T, M, L ; 
int a, b, c, d; 
vector<pair<pair<int, int>, int> > V[101];  
int COST[101][10001] ; 
void dijkstra(int start, int end) { 
    for (int i = 1; i <= N; i++) {
        for (int j = 0 ; j <= M ; j++) COST[i][j] = INT_MAX; 
    }
    priority_queue<pair<pair<int, int>, int> > pq; 
    pq.push(make_pair(make_pair(-0, -0), start)) ; 
    COST[start][0] = 0 ; 

    while(!pq.empty()) { 
        
        int time = -pq.top().first.first ;
        int cost = -pq.top().first.second ; 
        int curr = pq.top().second ; 
        pq.pop() ;

        if ( cost > M || time > COST[curr][cost] ) continue ; 

        for (int i = 0 ; i < V[curr].size(); i++) {
            int next = V[curr][i].first.first ; 
            int next_time = V[curr][i].first.second ; 
            int next_cost = cost + V[curr][i].second ; 

            if ( M >= next_cost && COST[next][next_cost] > time + next_time ) { 
                COST[next][next_cost] = time + next_time ; 
                pq.push(make_pair(make_pair(-COST[next][next_cost], -next_cost), next)); 
            }
        }
    } 

    for (int i = 0; i <= M; i++) {
		if (COST[end][i] <= T) {
			cout << i << '\n';
            return ; 
		}
	}
	cout << -1 << '\n';
}
int main(void) { 
    ios::sync_with_stdio(false); 
    cin.tie(0) ; 

    cin >> N ; 
    cin >> T >> M ; 
    cin >> L ; 

    for (int i = 0 ; i < L ; i++) { 
        cin >> a >> b >> c >> d ; 
        V[a].push_back(make_pair(make_pair(b, c), d)); 
        V[b].push_back(make_pair(make_pair(a, c), d));
    }

    dijkstra(1, N) ; 
    return 0 ;
}