#include <iostream> 
#include <vector> 
#include <cstring> 
#define MAX 501 
using namespace std; 

int n, k ;
vector<int> V[MAX] ;  
int matched[MAX] ; 
bool visited[MAX] ; 

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

    cin >> n >> k ; 

    for (int i = 1, r = 0, c = 0 ; i <= k ; i++) { 
        cin >> r >> c ; 
        V[r].push_back(c) ; 
    }

    int cnt = 0 ; 
    for (int i = 1 ; i <= n ; i++) { 
        memset(visited, false, sizeof(visited)) ; 
        if (dfs(i)) cnt++; 
    }

    cout << cnt << '\n' ;
    return 0 ;
}