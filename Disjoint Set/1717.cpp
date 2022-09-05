#include <iostream> 

#define MAX 1000001 
using namespace std ;

int n, m ; 
int parent[MAX]; 

int find_root(int x) { 
    if ( x == parent[x] ) return x ;
    return parent[x] = find_root(parent[x]) ;
}

void union_find(int x, int y) { 
    x = find_root(x) ; 
    y = find_root(y) ; 
    
    if ( x < y ) parent[y] = x ;  
    else parent[x] = y ;    
}

bool same_parent(int x, int y) { 
    x = find_root(x) ; 
    y = find_root(y) ; 

    if ( x == y ) return true ; 
    else return false; 
}

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> n >> m ; 
    for (int i = 1 ; i <= n ; i++) { 
        parent[i] = i ; 
    }

    for (int i = 0, chk, a, b; i < m; i++) { 
        cin >> chk >> a >> b ;

        if ( chk == 0 ) { 
            union_find(a, b) ; 
        } else if ( chk == 1 ) { 
            
            if ( same_parent(a, b) ) { 
                cout << "YES" << '\n'; 
            } else { 
                cout << "NO" << '\n'; 
            }
        }
    }
    return 0 ; 
}