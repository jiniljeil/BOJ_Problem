#include <iostream> 
#include <queue> 
#include <string> 
#define RMAX 10000
#define CMAX 500 
using namespace std ; 

int R, C ; 
bool visited[RMAX + 1][CMAX + 1] ; 
char MAP[RMAX + 1][CMAX + 1] ; 
int dy[3] = {-1, 0, 1} ; 
int answer = 0 ;
bool dfs(int y, int x) { 
    visited[y][x] = true; 
    if ( x == C - 1 ) { 
        answer++; 
        return true ; 
    }

    for (int i = 0 ; i < 3 ;i++) { 
        int ny = y + dy[i] ; 
        int nx = x + 1 ; 

        if ( nx < 0 || nx >= C || ny < 0 || ny >= R ) continue ; 
        if ( visited[ny][nx] || MAP[ny][nx] == 'x' ) continue ; 
        if ( dfs(ny, nx) ) {
            return true ;
        } 
    }
    return false; 
} 

int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 
    cin >> R >> C ;
    for (int i = 0 ; i < R ; i++) { 
        string s ; cin >> s ; 
        for (int j = 0 ; j < C ; j++) { 
            MAP[i][j] = s[j] ; 
        }   
    }

    for (int i = 0 ; i < R; i++) { 
        dfs(i, 0) ;
    }

    cout << answer << '\n'; 
    return 0 ;
}