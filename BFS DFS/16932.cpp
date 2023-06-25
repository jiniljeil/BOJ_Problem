#include <iostream>
#include <queue>  
#include <cstring> 
#include <vector> 
#include <set> 
#define SIZE 1010
using namespace std ;
typedef pair<int,int> pi ; 
int N, M ; 
int map[SIZE][SIZE] ;
int visited[SIZE][SIZE] ; 
int groupNum[(SIZE/2) * (SIZE/2)] ;  
vector<pi> V ;
int result, group ; 
int dx[4] = {-1, 0, 1, 0} ; 
int dy[4] = { 0,-1, 0, 1} ; 

void bfs(int y, int x) {
    queue<pi> Q ; 
    Q.push({y, x}) ; 
    visited[y][x] = group ; 
    int cnt = 0 ;
    while (!Q.empty()) { 
        pi curr = Q.front(); Q.pop();

        for (int k = 0 ; k < 4 ; k++) { 
            int ny = curr.first + dy[k]; 
            int nx = curr.second + dx[k]; 
            
            if ( nx < 0 || nx >= M || ny < 0 || ny >= N ) continue ;
            if ( map[ny][nx] == 0 || visited[ny][nx] ) continue;  
            visited[ny][nx] = group ;
            Q.push({ny, nx}) ;
        }
    }
} 

int main(void) { 
    ios::sync_with_stdio(0) ; cin.tie(0) ;

    cin >> N >> M ; 

    for (int i = 0 ; i < N ; i++) { 
        for (int j = 0 ; j < M ; j++) { 
            cin >> map[i][j] ; if ( map[i][j] == 0 ) V.push_back({i, j}); 
        }
    }

    for (int i = 0 ; i < N ; i++) { 
        for (int j = 0 ; j < M ; j++) { 
            if ( map[i][j] == 1 && visited[i][j] == 0) {
                group++; 
                bfs(i,j) ; 
            }
        }
    }

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            groupNum[visited[i][j]]++ ; 
        }
    }

    for (int i = 0 ; i < V.size() ; i++) { 
        int y = V[i].first, x = V[i].second ; 
        int cnt = 1 ; set<int> S ; 
        for (int k = 0 ; k < 4 ;k++) { 
            int nx = x + dx[k] ; 
            int ny = y + dy[k] ; 
            if ( nx < 0 || nx >= M || ny < 0 || ny >= N ) continue ;
            if ( visited[ny][nx] == 0 || S.find(visited[ny][nx]) != S.end() ) continue;  
            
            S.insert(visited[ny][nx]) ;
            cnt += groupNum[visited[ny][nx]] ; 
        }
        result = max(result, cnt ) ; 
    }

    cout << result << '\n'; 
    return 0 ;
}