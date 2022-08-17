#include <iostream> 
#include <vector> 
#include <cstring> 
#define MAX 202
using namespace std ;

int N, M ; 
vector<int> cows[MAX] ; 
int match[MAX] ; 
bool visited[MAX] ; 

bool dfs(int k) { 
    for (int i = 0 ; i < cows[k].size(); i++) { 
        int t = cows[k][i] ; 

        if (visited[t]) continue ; 
        visited[t] = true ; 

        if ( match[t] == 0 || dfs(match[t])) { 
            match[t] = k ; 
            return true ; 
        }
    }
    return false; 
}

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N >> M ; 
    
    for (int i = 0, n = 0; i < N ; i++) { 
        cin >> n ; 
        for (int j = 0, k = 0; j < n ; j++ ) { 
            cin >> k ; 
            cows[i + 1].push_back(k) ; 
        }
    }

    int cnt = 0 ; 
    for (int i = 1; i <= N ; i++) { 
        memset(visited, false, sizeof(visited)); 
        if ( dfs(i) ) cnt++; 
    }

    cout << cnt << '\n'; 

    return 0 ;
}