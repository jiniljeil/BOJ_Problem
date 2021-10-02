#include <iostream> 
#include <vector> 
#define LOG 17 // 2 ^ 17 = 131072 > 1e5
#define MAX 100001
using namespace std; 

int N, M, n1, n2; 
vector<int> graph[MAX]; 
bool visited[MAX]; 
int Depth[MAX], parent[MAX][LOG]; 
void DFS(int curr, int depth) { 
    visited[curr] = true ;
    Depth[curr] = depth ;  

    for (int i = 0 ; i < graph[curr].size(); i++) {
        int next_node = graph[curr][i]; 
        if ( visited[next_node] ) continue; 
        parent[next_node][0] = curr ;
        DFS(next_node, depth + 1); 
    }
}

void set_parent() { 
    DFS(1, 0) ;
    for (int i = 1 ; i < LOG; i++) {
        for (int j = 1;  j <= N ; j++) {
            parent[j][i] = parent[parent[j][i-1]][i-1]; 
        }
    }
}

int Fast_LCA(int x, int y) {
    if (Depth[x] > Depth[y]) swap(x,y); 

    for(int i = LOG - 1; i >= 0 ; i--) {
        if (Depth[y] - Depth[x] >= (1 << i)) {
            y = parent[y][i] ;
        }
    }

    if ( x == y ) return x; 

    for(int i = LOG - 1; i >= 0 ; i--) {
        if ( parent[x][i] != parent[y][i] ) {
            x = parent[x][i]; 
            y = parent[y][i]; 
        }
    }

    return parent[x][0] ;
}


int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;

    cin >> N ; 

    for(int i = 0 ; i < N - 1; i++) {
        cin >> n1 >> n2; 
        graph[n1].push_back(n2); 
        graph[n2].push_back(n1); 
    }

    set_parent() ; 

    cin >> M ;  

    for(int i = 0 ; i < M ; i++) {
        cin >> n1 >> n2; 
        cout << Fast_LCA(n1, n2) << '\n'; 
    }

    return 0;
}