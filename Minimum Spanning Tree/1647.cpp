#include <iostream> 
#include <vector> 
#include <algorithm>
#include <queue> 
#define MAX 100001
using namespace std; 

int N, M, A, B, C; 
int parent[MAX]; 
int path_count = 0 ; 
int max_value = -1; 
long long total_w = 0; 
vector<pair<int, pair<int,int> > > v; // weight, node1, node2

int find_parent(int x) {
    if (parent[x] == x) return x ; 
    else return parent[x] = find_parent(parent[x]); 
}

void Union(int x, int y) {
    x = find_parent(x); 
    y = find_parent(y); 

    if( x != y ) { 
        parent[y] = x; 
    }
}

int main(void) {
    ios::sync_with_stdio(false) ;
    cin.tie(0); cout.tie(0) ; 

    cin >> N >> M ; 

    for (int i = 0 ; i < M ;i++) {
        cin >> A >> B >> C ; 
        v.push_back(make_pair(C, make_pair(A, B))) ; // weight, (node1, node2) 
    }

    sort(v.begin(), v.end()) ; 
    
    for (int i = 1 ; i <= N ; i++) {
        parent[i] = i ; 
    }
    
    for (int i = 0 ; i < v.size(); i++) { 
        if (path_count == N - 1) break ;

        if (find_parent(v[i].second.first) != find_parent(v[i].second.second)) {
            Union(v[i].second.first, v[i].second.second) ;
            path_count++; 
            max_value = max(max_value, v[i].first); 
            total_w += v[i].first ; 
        }
    } 
    
    cout << total_w - max_value << '\n';
    return 0 ;
}