#include <iostream> 
#include <queue> 
#define SIZE 1010 

using namespace std ;
typedef pair<int, int> pi ; 

int N, M, L, R ;
int map[SIZE][SIZE] ; 
bool visited[SIZE][SIZE] ;
int dx[2] = {-1, 1} ; 
int dy[2] = { 0, 0} ; 
pi start ; 

void bfs() { 
    queue< pair<pi, pi> > Q; 
    Q.push({start, {L, R}}) ; 
    visited[start.first][start.second] = true ;
    while (!Q.empty()) { 
        int y = Q.front().first.first, x = Q.front().first.second ; 
        int left = Q.front().second.first, right = Q.front().second.second ; 
        Q.pop() ;

        // 위 아래 다 넣기
        int top = 1, down = 1;
        while ( ( (y - top >= 0 && y - top < N) && map[y - top][x] != 1) && visited[y - top][x] == 0 ) { 
            Q.push({{y - top, x}, {left, right}}) ; 
            visited[y - top][x] = true; 
            top++; 
        }
        while( (( y + down >= 0 && y + down < N) && map[y + down][x] != 1) && visited[y + down][x] == 0) {
            Q.push({{y + down, x}, {left, right}}) ; 
            visited[y + down][x] = true; 
            down++; 
        }

        for (int k = 0 ; k < 2 ; k++) { 
            // 좌 우 넣기
            int nx = x + dx[k] ;  
            int ny = y + dy[k] ;
            if ( nx < 0 || ny < 0 || ny >= N || nx >= M ) continue ;
            if ( visited[ny][nx] || map[ny][nx] == 1 ) continue ;
            if ( k == 0 && left > 0 ) { 
                visited[ny][nx] = true; Q.push({{ny,nx},{left - 1, right}}) ;
            } else if ( k == 1 && right > 0 ) { 
                visited[ny][nx] = true; Q.push({{ny,nx},{left, right - 1}}) ;
            }
        }
    }

    int cnt = 0 ;
    for (int i = 0 ; i < N ; i++) { 
        for (int j = 0 ; j < M ; j++) { 
            if( visited[i][j] == 1 ) cnt++; 
        }
    }
    cout << cnt << '\n';
}

int main(void) { 
    scanf("%d %d", &N, &M) ; 
    scanf("%d %d", &L, &R) ; 

    for (int i = 0 ; i < N ; i++) { 
        for (int j = 0; j < M; j++ ) {
            scanf("%1d", &map[i][j]); 
            if ( map[i][j] == 2 ) start = {i, j} ;
        }
    }

    bfs() ; 
    return 0 ;
}