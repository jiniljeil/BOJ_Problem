#include <iostream> 
#include <vector> 
#define MAX 50002
#define LOG 16
using namespace std; 

int N, M, n1, n2; 
vector<int> v[MAX];
int parent[MAX], Depth[MAX]; 
bool visited[MAX] ; 

void DFS(int curr, int depth) { 
    visited[curr] = true; 
    Depth[curr] = depth ; 

    for (int i = 0 ; i < v[curr].size(); i++) {
        int next_node = v[curr][i]; 
        if ( visited[next_node] ) continue; 
        parent[next_node] = curr ;
        DFS(next_node ,depth + 1) ; 
    }
}

int LCA(int x, int y) { 
    // Depth(높이)가 다를 경우, 맞춰준다. 
    while ( Depth[x] != Depth[y] ) { 
        if (Depth[x] > Depth[y]) { 
            x = parent[x]; 
        }else {
            y = parent[y] ;
        }
    }

    // 공통 조상을 가질 때 까지 반복
    while ( x != y ) {
        x = parent[x] ; 
        y = parent[y] ; 
    }

    return x ; 
}
int main(void) {
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;cout.tie(0) ;

    cin >> N ; 

    for(int i = 0; i < N - 1; i++) {
        cin >> n1 >> n2 ; 

        v[n1].push_back(n2); 
        v[n2].push_back(n1); 
    }
    DFS(1, 0); 
    
    cin >> M ; 

    for(int i = 0 ; i < M; i++) {
        cin >> n1 >> n2; 
        cout << LCA(n1, n2) << '\n'; 
    }
    return 0; 
}