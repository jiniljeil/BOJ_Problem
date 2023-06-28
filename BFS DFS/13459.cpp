#include <bits/stdc++.h> 
#define SIZE 11
using namespace std ;

typedef struct p { 
    int y, x;    
} point ; 

typedef struct b { 
    point red, blue; 
    int n ;
} ball ;

char mat[SIZE][SIZE] ;
bool visited[SIZE][SIZE][SIZE][SIZE] ;
point red, blue, hole ; 
int R, C ;
int dx[4] = {-1, 0, 1, 0} ; 
int dy[4] = { 0,-1, 0, 1} ;

bool bfs() { 
    queue<ball> Q ; 
    Q.push({red, blue, 0}) ;
    
    visited[red.y][red.x][blue.y][blue.x] = true ;

    while (!Q.empty()) { 
        int ry = Q.front().red.y, rx = Q.front().red.x ;
        int by = Q.front().blue.y, bx = Q.front().blue.x ; 
        int n = Q.front().n ; 
        Q.pop(); 

        if ( n >= 10 ) break ;
        
        for (int k = 0 ; k < 4; k++) { 
            int nry = ry, nrx = rx ;
            int nby = by, nbx = bx; 
            int rcnt = 0, bcnt = 0 ;
            
            while ( mat[nry + dy[k]][nrx + dx[k]] != '#' && mat[nry][nrx] != 'O') { 
                nry += dy[k]; nrx += dx[k] ; rcnt++;
            }
            while ( mat[nby + dy[k]][nbx + dx[k]] != '#' && mat[nby][nbx] != 'O') { 
                nby += dy[k]; nbx += dx[k] ; bcnt++;
            }
            
            if ( mat[nby][nbx] == 'O') continue ; 
            if ( mat[nry][nrx] == 'O') return 1; 
            
            if (nrx == nbx && nry == nby) {
                if ( rcnt > bcnt ) { 
                    nry = nry - dy[k]; 
                    nrx = nrx - dx[k];
                } else {
                    nby = nby - dy[k]; 
                    nbx = nbx - dx[k]; 
                }
            }
            
            if ( visited[nry][nrx][nby][nbx] ) continue; 
            visited[nry][nrx][nby][nbx] = true ;
            point r = {nry, nrx}, b = {nby, nbx};
            Q.push({r, b, n + 1});
        }
    }
    
    return 0; 
}

int main(void) { 
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C ; 
    for (int i = 0 ; i < R; i++) { 
        string s; cin >> s ;
        for (int j = 0 ; j < C; j++){ 
            mat[i][j] = s[j] ;
            
            if (mat[i][j] == 'R') { mat[i][j] = '.'; red = {i, j}; } 
            else if (mat[i][j] == 'B') { mat[i][j] = '.'; blue = {i, j}; } 
            else if (mat[i][j] == 'O') hole = {i, j}; 
        }
    }
    
    cout << bfs() << '\n'; 
    return 0; 
}