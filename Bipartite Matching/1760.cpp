#include <iostream> 
#include <cstring> 
#include <vector> 
#define MAX 101  
using namespace std ; 

int R, C ; 
int MAP[MAX][MAX] ; 
int ROWS[MAX][MAX] ; 
int COLS[MAX][MAX] ; 
vector<int> V[MAX * MAX] ; 
int matched[MAX * MAX] ; 
bool visited[MAX * MAX] ; 

bool dfs(int k) { 
    for (int i = 0 ; i < V[k].size(); i++) { 
        int t = V[k][i] ; 
        if ( visited[t] ) continue; 
        visited[t] = true ; 
        if (matched[t] == 0 || dfs(matched[t])) { 
            matched[t] = k ; 
            return true; 
        }
    }
    return false; 
}

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ;

    cin >> R >> C ; 

    int num = 0 ; 
    for (int i = 0 ; i < R; i++) {
        for (int j = 0; j < C ; j++) { 
            cin >> num ; 
            MAP[i][j] = num ; 
        }
    }
    int r_cnt = 1 ; 
    int c_cnt = 1 ; 

    for (int i = 0 ; i < R; i++) { 
        for (int j = 0 ; j < C; j++) { 
            if ( MAP[i][j] == 0 ) ROWS[i][j] = r_cnt ;
            if ( MAP[i][j] != 2 && (j == C - 1 || MAP[i][j+1] == 2)) r_cnt++; 
        }
    }

    for (int i = 0 ; i < C ; i++ ) {
        for (int j = 0 ; j < R ; j++) { 
            if ( MAP[j][i] == 0 ) COLS[j][i] = c_cnt ; 
            if ( MAP[j][i] != 2 && (j == R - 1 || MAP[j+1][i] == 2)) c_cnt++;
        }
    }


    for (int i = 0 ; i < R ; i++) { 
        for (int j = 0 ; j < C; j++) { 
            if ( MAP[i][j] == 0 ) { 
                V[ROWS[i][j]].push_back(COLS[i][j]) ; 
            }
        }
    }
    int cnt = 0 ;
    for (int i = 1 ; i <= r_cnt ; i++) { 
        memset(visited, false, sizeof(visited)) ; 
        if (dfs(i)) cnt++; 
    }
    cout << cnt << '\n';  
    
    return 0 ;
}