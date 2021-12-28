#include <iostream> 
#include <vector> 
#include <string.h> 
#include <queue> 
#define MAX 100001
using namespace std; 
int V ; 
int N, NV, D ; 
vector<pair<int, int> > G[MAX] ; 
bool visited[MAX] ; 
int result ; 
int leaf ; 

void DFS(int curr, int dist) { 
    int r = 0 ; 
    if ( visited[curr] ) return ; 
    visited[curr] = true;  
    if ( dist > result) { 
        result = dist ; 
        leaf = curr ; 
    }

    for (int i = 0 ; i < G[curr].size(); i++) {
        int next = G[curr][i].first ; 
        int next_w = G[curr][i].second ; 
        DFS(next, dist + next_w) ; 
    }   
}

void Input() {  
    cin >> V ; 

    for (int i = 0 ; i < V; i++) {
        cin >> N ; 

        while (1) { 
            cin >> NV ; 
            if ( NV == -1 ) break ;  
            cin >> D ;
            G[N].push_back(make_pair(NV, D)) ; 
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false) ;
    cin.tie(0) ; 

    Input() ; 

    memset(visited, false, sizeof(visited)); 
    DFS(1, 0); 

    memset(visited, false, sizeof(visited)) ;
    DFS(leaf, 0); 
    cout << result << '\n' ; 

    return 0 ;
}