#include <bits/stdc++.h>
#define SIZE 5010
using namespace std;
typedef pair<int,int> pi ; 

int N, M ; 
vector<pi> V[SIZE] ;
bool visited[SIZE] ; 

void bfs(int start, int K) {
    int result = 0 ;
    queue<int> Q ; 
    visited[start] = true ;
    Q.push(start) ; 
    
    while(!Q.empty()) { 
        int curr = Q.front(); Q.pop() ;
        
        result++ ; 
        
        for (int k = 0 ; k < V[curr].size(); k++) { 
            int next = V[curr][k].first ; 
            int weight = V[curr][k].second ; 
            
            if ( !visited[next] && weight >= K ) { 
                visited[next] = true ; 
                Q.push(next) ; 
            }
        }
    }
    
    cout << result - 1<< '\n';
}
int main() { 
    ios::sync_with_stdio(0) ;
    cin.tie(0) ; 

    cin >> N >> M ; 
    for (int i = 0 ; i < N - 1 ; i++ ) {
        int a,b,c; cin >> a >> b >> c ; 
        V[a].push_back({b,c}) ; 
        V[b].push_back({a,c}) ; 
    }

    while (M--) {
        int result = 0 ; 
        int start, K ; 
        
        cin >> K >> start ; 
        
        bfs(start, K); 
        
        memset(visited, 0, sizeof(visited)) ; 
    }
    return 0 ;
}