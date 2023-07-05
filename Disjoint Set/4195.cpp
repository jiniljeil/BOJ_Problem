#include <bits/stdc++.h> 
#define SIZE 200010
using namespace std ;

int TC ; 
vector<int> parent; 
map<string, int> m ; 
int result[SIZE] ;

int find_root(int x){ 
    if ( parent[x] == x ) return x; 
    return parent[x] = find_root(parent[x]); 
}

void union_find(int x, int y) { 
    x = find_root(x) ; 
    y = find_root(y) ; 

    parent[y] = x;
}

int main() { 
    ios::sync_with_stdio(0) ; cin.tie(0) ;

    cin >> TC ;

    while (TC--) { 
        parent.push_back(0) ;
        int n ; cin >> n ; 
        
        int cnt = 1; 
        for (int i = 0 ; i < n ; i++ ) { 
            string a, b ; cin >> a >> b; 
            if ( m.find(a) == m.end() ) { 
                parent.push_back(cnt) ;
                result[cnt] = 1; 
                m.insert({a, cnt++});
            }
            if ( m.find(b) == m.end() ) {
                parent.push_back(cnt) ;
                result[cnt] = 1; 
                m.insert({b, cnt++}); 
            }

            int pa = find_root(m[a]) ; 
            int pb = find_root(m[b]) ;
            
            if ( pa != pb ) { 
                union_find(pa, pb); 
                result[pa] += result[pb];
            }
            cout << result[pa] << '\n';
        }
        memset(result, 0, sizeof(result)) ;
        parent.clear() ;
        m.clear() ;
    }
    return 0;
}