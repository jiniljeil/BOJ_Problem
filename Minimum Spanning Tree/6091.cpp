#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>
#define SIZE 1025
using namespace std ;

int map[SIZE][SIZE];
int N ;
int parent[SIZE];
typedef struct path {
    int weight ;  
    int start, end ;
} PATH ;

struct cmp {
    bool operator() (const PATH &a, const PATH &b) { 
        return a.weight > b.weight ;   
    }
};
priority_queue<PATH, vector<PATH>, cmp> pq ; 
vector<int> V[SIZE] ; 
int find_root(int x) {
    if ( parent[x] == x ) return parent[x] ;
    else return parent[x] = find_root(parent[x]) ;
}

void union_set(int x, int y) {
    x = find_root(x) ; 
    y = find_root(y) ; 
    
    parent[y] = x ; 
}

int main(void) {
    int k; 
    cin >> N ;
    for (int i = 1 ; i <= N ; i++) {
        for (int j = i + 1; j <= N ; j++) { 
            cin >> k ; map[i][j] = map[j][i] = k ;
            pq.push({k, i, j}) ; 
        }
    }

    for (int i = 1; i <= N ; i++) parent[i] = i;
    
    int cnt = 0 ;
    while (!pq.empty() ) {
        if ( cnt == N - 1 ) break ;
        PATH p = pq.top(); pq.pop() ;   
        int start = find_root(p.start), end = find_root(p.end) ; 
        if ( start != end ) {
            union_set(start, end) ;
            V[p.start].push_back(p.end) ; V[p.end].push_back(p.start);
            cnt++; 
        }   
    }
    
    for (int i = 1; i <= N ; i++) {
        cout << V[i].size() << ' '; 
        sort(V[i].begin(), V[i].end());
        for (int j = 0 ; j < V[i].size() ; j++) { 
            cout << V[i][j] << ' ';   
        }
        cout << '\n';
    }
    
    return 0 ;
}