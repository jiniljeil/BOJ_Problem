#include <bits/stdc++.h> 
#define SIZE 101
using namespace std ;

typedef struct robot {
    int y, x; 
    int d ; 
} robot; 

int A[SIZE][SIZE] ;
int visited[SIZE][SIZE][4] ; 
int R, C ;
robot start, finish ; 

void bfs() { 
    queue<robot> Q ; 
    Q.push({start.y, start.x, start.d}) ; 
    visited[start.y][start.x][start.d] = 0 ;

    while (!Q.empty()) { 
        robot crobot = Q.front() ; Q.pop() ;

        if ( crobot.y == finish.y && crobot.x == finish.x && crobot.d == finish.d) { 
            cout << visited[crobot.y][crobot.x][crobot.d] << '\n' ; 
            break ; 
        }

        // current direction 
        for (int k = 1 ; k <= 3 ; k++) { 
            int nx = crobot.x + dx[crobot.d] * k; 
            int ny = crobot.y + dy[crobot.d] * k;  
            
            if ( visited[ny][nx][crobot.d] ) continue ;

            if ( nx < 0 || ny < 0 || nx >= C || ny >= R ) break ;
            if ( A[ny][nx] == 1 ) break ; 

            visited[ny][nx][crobot.d] = visited[crobot.y][crobot.x][crobot.d] + 1; 
            Q.push({ny, nx, crobot.d}) ; 
        }

        if ( crobot.d == 0 || crobot.d == 1 ) { 
            for ( int nd = 2 ; nd <= 3 ; nd++) { 
                if ( !visited[crobot.y][crobot.x][nd] ) {
                    visited[crobot.y][crobot.x][nd] = visited[crobot.y][crobot.x][crobot.d] + 1; 
                    Q.push({crobot.y, crobot.x, nd});
                }
            }
        }
        else if ( crobot.d == 2 || crobot.d == 3 ) { 
            for ( int nd = 0 ; nd <= 1 ; nd++) { 
                if ( !visited[crobot.y][crobot.x][nd] ) {
                    visited[crobot.y][crobot.x][nd] = visited[crobot.y][crobot.x][crobot.d] + 1; 
                    Q.push({crobot.y, crobot.x, nd});
                }
            }
        }
    }
}
int main() { 
    ios::sync_with_stdio(0) ; cin.tie(0) ; 

    cin >> R >> C ;

    for (int i = 0 ; i < R ;i++ ) {
        for (int j = 0 ; j < C ; j++) {
            cin >> A[i][j] ;
        }
    }

    int a,b,c ; 
    cin >> a >> b >> c ;
    start = {a - 1, b - 1, c - 1} ; 
    cin >> a >> b >> c ;
    finish = {a - 1, b - 1, c - 1} ; 
    
    bfs() ;

    return 0;
}


/*
5 6
0 0 0 0 0 0
0 1 1 0 1 0
1 1 0 0 0 0
0 0 1 1 1 0
1 0 0 0 0 0
4 2 3
2 4 1
Ans: 11 

10 10
0 1 1 1 0 0 0 0 0 1
0 0 0 0 0 1 1 1 1 1
0 0 0 0 0 1 1 1 1 1
0 1 0 0 1 1 1 1 1 1
0 0 0 1 0 0 0 1 1 1
0 1 1 1 0 0 0 0 0 1
0 0 0 1 1 0 0 0 1 1
0 1 0 1 1 1 1 0 1 1
0 0 0 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0 1 1
1 9 1
9 1 3
Ans: 12

9 12
0 0 0 0 0 0 0 0 0 0 0 1
0 1 1 1 1 0 0 1 1 1 1 0
0 0 0 0 0 0 0 1 1 1 1 0
0 1 1 1 1 0 0 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 0 0 1 1 1 1 0
0 1 1 1 1 0 0 0 0 0 0 0
0 1 1 1 1 0 0 1 1 1 1 0
1 0 0 0 0 0 0 0 0 0 0 0
1 1 3
9 12 3
Ans: 10
*/