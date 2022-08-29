#include <iostream> 
#include <vector> 
#include <cstring> 
#define MAX 101
using namespace std ;

int N, M ; 
vector<int> V[MAX] ; 
int matched[MAX]; 
bool visited[MAX] ; 

bool dfs(int k) { 
    for (int i = 0 ; i < V[k].size(); i++) { 
        int t = V[k][i] ; 
        if ( visited[t] ) continue ; 
        visited[t] = true  ; 

        if ( matched[t] == 0 || dfs(matched[t]) )  {
            matched[t] = k ; 
            return true ; 
        }
    }
    return false; 
}

int main(void) { 
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; 
    
    cin >> N >> M ; 

    for (int i = 1, a = 0, b = 0 ; i <= M ; i++) { 
        cin >> a >> b ; 
        V[a].push_back(b) ; 
    }

    int cnt = 0 ; 
    for (int i = 1 ; i <= N ; i++) { 
        memset(visited, false , sizeof(visited)) ; 
        if ( dfs(i) ) cnt++ ; 
    }
    cout << cnt << '\n';
    return 0 ;
}