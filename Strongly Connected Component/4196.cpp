#include <iostream> 
#include <vector> 
#include <cstring> 
#include <algorithm>
#define SIZE 100010

using namespace std ;

int TC, N, M ;
vector<int> V[SIZE] ;
bool visited[SIZE] ;
bool t ; 

void clear() {
    memset(visited, 0, sizeof(visited)) ; 
    for (int i = 1; i <= N ; i++) {
        V[i].clear() ;
    }
    t = false; 
}

void dfs(vector<int> &path, int curr) { 
    if (visited[curr]) return ; 
    visited[curr] = true ;
    
    for (int i = 0 ; i < V[curr].size() ; i++) {
        int next = V[curr][i]; 
        dfs(path, next) ; 
    }

    if (!t) path.push_back(curr) ;
}

int main(void) { 
    ios::sync_with_stdio(0); cin.tie(0) ;

    cin >> TC ; 
    while (TC--) { 
        cin >> N >> M ; 
        for (int i = 0, a,b ; i < M ; i++) { 
            cin >> a >> b ; 
            V[a].push_back(b) ; 
        }

        vector<int> path ; 
        for (int i = 1; i <= N ; i++) { 
            dfs(path, i) ;
        }

        reverse(path.begin(), path.end());
        memset(visited, 0, sizeof(visited)) ;

        t = true; 
        int ans = 0 ;
        for (int i = 0 ; i < path.size(); i++) { 
            if (!visited[path[i]]) { ans++; dfs(path, path[i]); }
        }
        cout << ans << '\n' ;
        clear();
    }
}