#include <iostream> 
#include <vector> 
#include <algorithm> 
#define SIZE 200010
using namespace std ;
typedef pair<int, int> pi ;
vector<pair<int, pi> > V ;
int N, M ; 

int parent[SIZE] ; 
int cnt; 
int time = 0 ;

int find_parent(int x) { 
    if ( parent[x] == x ) return x; 
    else return parent[x] = find_parent(parent[x]);
}

void union_nodes(int x, int y) { 
    x = find_parent(x) ; 
    y = find_parent(y) ; 
    if ( x != y ) { 
        parent[y] = x ; 
    }
}

int main() { 
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> N >> M ; 

    for (int i = 0,a,b,c; i < M ; i++) { 
        cin >> a >> b >> c; 
        V.push_back({c, {a, b}}) ; 
    }

    for (int i = 1, t = 0 ; i <= N ; i++) { 
        cin >> t; 
        V.push_back({t, {i, N + 1}}); 
        parent[i] = i ;
    }
    parent[N + 1] = N + 1 ; 

    sort(V.begin(), V.end()) ;

    for (int i = 0 ; i < M + N ; i++) { 
        if ( cnt == N ) break ; 
        pi nodes = V[i].second ;
        if ( find_parent(nodes.first) != find_parent(nodes.second)) { 
            union_nodes(nodes.first, nodes.second) ; 
            cnt++; 
            time += V[i].first ;
        }
    }

    cout << time << '\n' ; 
    return 0;
}