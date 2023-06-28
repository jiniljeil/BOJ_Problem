#include <bits/stdc++.h> 
#define SIZE 11 
#define INF 1e9
using namespace std ;

typedef struct p { 
    int y, x ;
} point ; 

typedef struct b { 
    point red, blue ; 
    int n ; 
    string dir ; 
} ball ;

point red, blue;
int R, C ;
int dx[4] = {-1, 0, 1, 0} ; 
int dy[4] = { 0,-1, 0, 1} ; 
char d[4] = {'L','U','R','D'};
int mat[SIZE][SIZE] ; 
bool visited[SIZE][SIZE][SIZE][SIZE] ;
int result = INF ;
string s = ""; 
void move(int& y, int& x, int k, int& cnt) { 
    while (mat[y + dy[k]][x + dx[k]] != '#' && mat[y][x] != 'O') {
        y += dy[k] ; x += dx[k] ; cnt++ ;
    }
}
void bfs() { 
    queue<ball> Q; 
    Q.push({red, blue, 0, ""}) ; 
    visited[red.y][red.x][blue.y][blue.x] = true ; 

    while (!Q.empty()) { 
        int rx = Q.front().red.x, ry = Q.front().red.y ;
        int bx = Q.front().blue.x, by = Q.front().blue.y ; 
        int n = Q.front().n ; string dir = Q.front().dir; 

        Q.pop() ; 
        
        if ( result == INF && n >= 10 ) { result = -1; break ;}  
        
        for (int k = 0 ; k < 4; k++) { 
            string tmp_dir = dir ;
            int n_ry = ry, n_rx = rx ;
            int n_by = by, n_bx = bx ;

            int rcnt = 0, bcnt = 0 ;
            move(n_ry, n_rx, k, rcnt) ; 
            move(n_by, n_bx, k, bcnt) ; 

            if ( mat[n_by][n_bx] == 'O') continue ;
            if ( mat[n_ry][n_rx] == 'O') { 
                if ( result > n + 1 ) { 
                    result = n + 1; 
                    s = tmp_dir + d[k] ; 
                } 
                continue ;
            }

            // 두 공이 겹칠 경우
            if ( n_ry == n_by && n_bx == n_rx ) {
                if ( rcnt > bcnt ) { 
                    n_ry -= dy[k]; n_rx -= dx[k]; 
                } else {
                    n_by -= dy[k]; n_bx -= dx[k];
                }
            }

            if ( visited[n_ry][n_rx][n_by][n_bx] ) continue ; 
            tmp_dir += d[k]; 

            // cout << tmp_dir << '\n';
            visited[n_ry][n_rx][n_by][n_bx] = true ;
            Q.push({n_ry, n_rx, n_by, n_bx, n + 1, tmp_dir}) ;
        }
    }

    // n < 10이며 두 공이 동시에 들어가게 되면 result == 1e9
    if ( result == INF || result == -1 ) cout << -1 << '\n';
    else {
        cout << result << '\n'; 
        cout << s << '\n';
    }
}

int main(void) {  
    cin >> R >> C ; 
    for (int i = 0 ; i < R; i++) { 
        string s; cin >> s ;
        for (int j = 0 ; j < C; j++){ 
            mat[i][j] = s[j] ;
            
            if (mat[i][j] == 'R') { mat[i][j] = '.'; red = {i, j}; } 
            else if (mat[i][j] == 'B') { mat[i][j] = '.'; blue = {i, j}; } 
        }
    }
    
    bfs();
    return 0;
}


/*
10 10
##########
#RB....#.#
#..#.....#
#........#
#.O......#
#...#....#
#........#
#........#
#.......##
##########
*/