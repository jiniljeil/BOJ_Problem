#include <iostream> 
#include <queue> 
#include <algorithm>
#include <string.h>
#define MAX 10001
using namespace std; 

int n ; 
vector<pair<int,int> > v[MAX]; 
bool visited[MAX] ; 
int leaf = 0 ; 
int length = 0 ;  

void DFS(int start, int dist) { 
    
    if ( visited[start] ) return ; 

    visited[start] = true ; 

    if ( dist > length ) { 
        length = dist ;
        leaf = start ; 
    }

    for (int i = 0 ; i < v[start].size(); i++) { 
        int next_n = v[start][i].first ; 
        int next_w = v[start][i].second ;  

        DFS(next_n, next_w + dist) ; 
    }
}

void Input() { 
    cin >> n ; 

    int a, b, c; 
    for (int i = 1 ; i <= n - 1 ; i++) {
        cin >> a >> b >> c ; 
        v[a].push_back(make_pair(b, c)) ; 
        v[b].push_back(make_pair(a, c)) ; 
    }
    
    for (int i = 1 ; i <= n ; i++ ) { 
        sort(v[i].begin(), v[i].end()); 
    }
}

int main(void) { 
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; 

    Input() ; 
    memset(visited, false, sizeof(visited)) ; 
    DFS(1, 0) ;
    memset(visited, false, sizeof(visited)) ; 
    DFS(leaf, 0) ;

    cout << length << '\n' ;
    return 0 ;
}