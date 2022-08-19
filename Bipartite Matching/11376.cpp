#include <iostream>
#include <cstring>  
#include <vector> 
#include <algorithm>
#define MAX 1001 
using namespace std ; 

int N, M;  
vector<int> works[MAX] ; 
int c[MAX] ;
bool visited[MAX];

bool dfs(int k ) {
    for (int i = 0 ; i < works[k].size(); i++) { 
        int t = works[k][i]; 
        if (visited[t]) continue; 
        visited[t] = true ;
        if ( c[t] == 0 || dfs(c[t])) { 
            c[t] = k ; return true ;  
        }
    }
    return false; 
}

int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 
    cin >> N >> M ; 

    for (int i = 1, n = 0; i <= N ; i++) { 
        cin >> n ; 
        for (int j = 0, w = 0 ; j < n ;j++) { 
            cin >> w ;
            works[i].push_back(w) ; 
        }
    }

    int cnt = 0 ; 
    for (int i = 1 ; i <= N ; i++) { 
        for (int j = 0 ; j < 2 ;j++) {
            memset(visited, false, sizeof(visited)) ; 
            if ( dfs(i) ) cnt++;  
        }
    }

    cout << cnt << '\n'; 
    return 0;
}
