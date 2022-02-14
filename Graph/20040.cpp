#include <iostream> 
#include <set> 
#define MAX 500001
using namespace std; 

int n, m; 
int parent[MAX] ; 
set<int> s; 

int find(int x) { 
    if (parent[x] == x) return x; 
    return parent[x] = find(parent[x]); 
}

void uni(int x, int y){
    if (find(x) == find(y)) return ;
    parent[find(x)] = find(y); 
    find(x) ; 
}

int main(void) { 
    ios::sync_with_stdio(false) ;
    cin.tie(0) ; 

    int a, b ; 

    cin >> n >> m ; 
    for (int i = 0 ; i < n ; i++) parent[i] = i ; 

    for (int i = 1 ; i <= m; i++) { 
        cin >> a >> b ; 

        if ( find(a) == find(b)) { 
            cout << i << '\n'; 
            return 0; 
        }
        
        uni(a, b); 
    }
    cout << '0' << '\n'; 
    return 0; 
}