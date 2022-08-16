#include <iostream> 
#include <vector> 
#include <cstring> 
#define MAX 1001
using namespace std ;

int TC ; 
int N, M ; 
vector<int> V[MAX] ; 
int match[MAX] ; 
bool visited[MAX] ; 
bool dfs(int k)  {
    for (int i = 0 ; i < V[k].size(); i++) { 
        int t = V[k][i] ; 
        if ( visited[t] ) continue ; 
        visited[t] = true ; 
        if ( match[t] == 0 || dfs(match[t]) ) { 
            match[t] = k ; 
            return true ; 
        }
    }
    return false; 
}
int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 

    cin >> TC ; 
    

    while(TC--) { 
        cin >> N >> M ; 
        for (int i = 0, cnt = 1 ; i < M ; i++) { 
            int a, b; 
            cin >> a >> b; 
            V[cnt].clear(); 
            for (int j = a ; j <= b ; j++) { 
                V[cnt].push_back(j) ; 
            }
            cnt++; 
        }

        memset(match, 0, sizeof(match)) ; 

        int cnt = 0 ;
        for (int i = 1 ; i <= M ;i++) { 
            memset(visited, false, sizeof(visited));
            if ( dfs(i) ) cnt++ ; 
        }
        
        cout << cnt << '\n'; 
    }
    return 0 ;
}