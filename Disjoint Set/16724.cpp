#include <iostream> 
#include <string>

using namespace std ;

int R, C;
int result; 
int arr[1010][1010]; 
int visited[1010][1010] ; 
// D: (0, 1) L: (-1, 0) U: (0, -1) R: (1, 0) 
int dx[4] = {0, -1, 0, 1}; 
int dy[4] = {1,  0,-1, 0}; 

void dfs(int y, int x) { 
    visited[y][x] = 1 ;
    int nx = x + dx[arr[y][x]]; 
    int ny = y + dy[arr[y][x]]; 

    if ( visited[ny][nx] == 1 ) result++; 
    if ( visited[ny][nx] == 0 ) dfs(ny, nx) ;
    visited[y][x] = 2 ; 
}

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0); 
    cin >> R >> C ;

    for (int i = 0 ; i < R ;i++) { 
        string s; cin >> s ;
        for (int j = 0 ; j < C; j++) { 
            if ( s[j] == 'D' ) arr[i][j] = 0 ; 
            else if ( s[j] == 'L') arr[i][j] = 1; 
            else if ( s[j] == 'U') arr[i][j] = 2; 
            else if ( s[j] == 'R') arr[i][j] = 3; 
        }
    }

    for (int i = 0 ; i < R ; i++) { 
        for (int j = 0 ; j < C ; j++) { 
            dfs(i, j); 
        }
    }

    cout << result << '\n' ;
    return 0 ;
}