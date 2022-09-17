#include <iostream> 
#include <cstring> 
#include <vector> 
#define MAX 20010 
using namespace std ;

int TC, V, E; 
int visited[MAX] ; 
vector<int> MAP[MAX] ; 

bool check = true ; 

void dfs(int start, int type) { 
    visited[start] = type ; 

    for (int i = 0 ; i < MAP[start].size(); i++) { 
        int next = MAP[start][i] ; 

        if ( visited[next] == type ) { 
            check = false; 
            return ; 
        }
        
        if ( visited[next] == 0 ) { 
            dfs(next, type * -1) ; 
        }
    }
}

int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 

    cin >> TC ; 

    while(TC--) { 
        int a, b; 
        
        cin >> V >> E ; 
        
        for (int i = 0; i < E ; i++) { 
            cin >> a >> b ; 
            MAP[a].push_back(b) ; 
            MAP[b].push_back(a) ; 
        }

        for (int i = 1 ; i <= V; i++) { 
            if ( !check ) break ;

            if ( visited[i] == 0 ) { 
                dfs(i, 1) ;
            }
        }

        if ( check ) cout << "YES" << '\n' ; 
        else cout << "NO" << '\n'; 

        for (int i = 1 ; i <= V; i++) { 
            MAP[i].clear(); 
        }
        memset(visited, 0, sizeof(visited)) ;
        check = true ;  
    }
    return 0 ; 
}