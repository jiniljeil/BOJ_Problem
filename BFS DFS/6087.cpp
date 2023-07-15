#include <iostream> 
#include <string> 
#include <queue> 
#define INF 1e9
#define MAX 101
using namespace std ;

int H, W; 
char MAP[MAX][MAX] ; 
int visited[MAX][MAX] ; 
int dx[4] = {-1, 0, 1, 0} ; 
int dy[4] = { 0, 1, 0,-1} ; 
int start_x = -1, start_y = -1 ; 
int end_x = -1, end_y = -1 ; 

typedef struct point { 
    int x, y ; 
} point ; 

queue<point> Q ;
void BFS() { 
    while (!Q.empty()) { 
        point curr = Q.front(); Q.pop() ; 
        for (int k = 0 ; k < 4; k++) { 
            int nx = curr.x + dx[k] ; 
            int ny = curr.y + dy[k] ; 

            while ( (nx >= 0 && nx < W && ny >= 0 && ny < H) && MAP[ny][nx] != '*') { 
                if ( !visited[ny][nx] ) { 
                    visited[ny][nx] = visited[curr.y][curr.x] + 1 ;
                    Q.push({nx, ny});
                }
                nx += dx[k];  ny += dy[k] ; 
            }
        }
    }

    cout << visited[end_y][end_x] - 1<< '\n';
}

void Input() { 
    cin >> W >> H ; 

    for (int i = 0 ; i < H ; i++) { 
        string s ; 
        cin >> s ; 
        for (int j = 0; j < W; j++) { 
            MAP[i][j] = s[j] ;
            if ( MAP[i][j] == 'C') { 
                if ( start_x == -1 && start_y == -1 ) {
                    start_y = i ; start_x = j ; 
                    Q.push({j , i});
                } else { 
                    end_y = i ; end_x = j ; 
                } 
                MAP[i][j] = '.';
            }
        }
    }
}

int main(void) { 
    ios::sync_with_stdio(false); 
    cin.tie(0) ; 

    Input() ;
    BFS(); 

    return 0 ;
}