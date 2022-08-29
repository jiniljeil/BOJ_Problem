#include <iostream> 
#include <cstring> 
#include <vector> 
#define MAX 301
using namespace std ;

int MAP[MAX][MAX] ; 
int ROWS[MAX][MAX] ; 
int COLS[MAX][MAX] ; 
int R, C, N; 
vector<int> V[MAX * MAX] ; 
bool visited[MAX * MAX] ; 
int matched[MAX * MAX] ; 

bool dfs(int k) { 
    for (int i = 0 ; i < V[k].size(); i++) { 
        int t = V[k][i] ; 
        if ( visited[t] ) continue ; 
        visited[t] = true ; 
        if ( matched[t] == 0 || dfs(matched[t])) { 
            matched[t] = k ; 
            return true ; 
        }
    }
    return false; 
}
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> R >> C >> N ; 

    int a, b; 
    for (int i = 0 ; i < N ; i++) { 
        cin >> a >> b ; 
        MAP[a - 1][b - 1] = 1; // hole
    }

    int r_cnt = 1 ; 
    for (int i = 0 ; i < R ; i++) { 
        for (int j = 0 ; j < C ;j++) {
            if ( MAP[i][j] == 0 ) ROWS[i][j] = r_cnt ;  
        }
        r_cnt++; 
    }

    int c_cnt = 1 ; 
    for (int i = 0 ; i < C; i++) { 
        for (int j = 0 ; j < R ; j++) { 
            if ( MAP[j][i] == 0 ) COLS[j][i] = c_cnt; 
        }
        c_cnt++; 
    }

    for (int i = 0; i < R ;i++) { 
        for (int j = 0 ; j < C ; j++) { 
            if ( MAP[i][j] == 0 ) { 
                V[ROWS[i][j]].push_back(COLS[i][j]); 
            }
        }
    }

    int answer = 0 ; 
    for (int i = 1; i <= r_cnt; i++) { 
        memset(visited, false, sizeof(visited)) ; 
        if (dfs(i)) answer++; 
    }
    cout << answer << '\n'; 
    return 0 ;
}