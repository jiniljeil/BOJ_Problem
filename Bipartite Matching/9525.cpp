#include <iostream> 
#include <vector> 
#include <cstring> 

#define MAX 101 
using namespace std ;
int N ; 
char MAP[MAX][MAX] ; 
int ROWS[MAX][MAX] ; 
int COLS[MAX][MAX] ; 
vector<int> V[MAX * MAX] ; 
bool visited[MAX * MAX] ; 
int matched[MAX * MAX] ; 

bool dfs(int k) { 
    for (int i = 0 ; i < V[k].size(); i++) { 
        int t = V[k][i] ; 
        if (visited[t]) continue ; 
        visited[t] = true ;
        if ( matched[t] == 0 || dfs(matched[t]))  {
            matched[t] = k ; 
            return true; 
        }
    }
    return false; 
} 

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); 

    cin >> N ; 

    for (int i = 0 ; i < N; i++) { 
        string s ; 
        cin >> s ; 
        for (int j = 0 ;j < s.size(); j++) { 
            MAP[i][j] = s[j] ;
        }
    }

    int r_cnt = 1, c_cnt = 1 ; 

    for (int i = 0 ; i < N; i++) { 
        bool r_x = false, c_x = false; 
        for (int j = 0; j < N ;j++) { 
            if ( r_x && MAP[i][j] == 'X') { r_cnt++; }
            if ( c_x && MAP[j][i] == 'X') { c_cnt++; } 

            if ( MAP[i][j] == '.') { r_x = true ; ROWS[i][j] = r_cnt;  }
            if ( MAP[j][i] == '.') { c_x = true ; COLS[j][i] = c_cnt;  }
        }
        r_cnt++;
        c_cnt++;
    }

    for (int i = 0 ; i < N; i++) { 
        for (int j = 0 ; j < N ;j++) { 
            if ( MAP[i][j] == 'X') continue ; 
            V[ROWS[i][j]].push_back(COLS[i][j]); 
        }
    }

    int cnt = 0 ; 
    for (int i = 1; i <= r_cnt ;i++) { 
        memset(visited, false, sizeof(visited)) ; 
        if (dfs(i)) cnt++; 
    }
    cout << cnt << '\n'; 
    return 0 ;
}