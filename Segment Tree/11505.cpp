#include <bits/stdc++.h>
#define INF INT_MAX
#define MOD 1000000007
using namespace std; 

typedef long long ll; 
int n, m, k ; 

ll init(vector<ll> &A, vector<ll> &tree, int node, int start ,int end)  {
    if ( start == end ) {
        return tree[node] = A[start] ; 
    } else { 
        int mid = (start + end) / 2;
        return tree[node] = (init(A, tree, node * 2, start, mid ) % MOD) * (init(A, tree, node * 2 + 1, mid + 1, end ) % MOD);
    }
}

ll update(vector<ll> &tree, int node, int start, int end, int idx, ll val) { 
    if ( idx < start || idx > end ) return tree[node];
    if ( start == end ) return tree[node] = val ; 
    int mid = (start + end) / 2 ;
    return tree[node] = ( update(tree, node * 2, start, mid, idx, val) % MOD) * (update(tree, node *2 +1 , mid + 1, end, idx, val ) % MOD ); 
}

ll query(vector<ll> &tree, int node, int start, int end, int left, int right) {
    if ( left > end || right < start ) return 1 ;
    if ( left <= start && end <= right ) return tree[node] ; 

    int mid = (start + end) / 2 ;

    return (query(tree, node * 2, start, mid, left, right) % MOD) * (query(tree, node * 2 + 1, mid + 1, end, left, right) % MOD); 
}

int main() { 
    ios::sync_with_stdio(0) ; cin.tie(0) ;
    cin >> n >> m >> k ;

    vector<ll> A(n) ;   
    int h = (int)ceil(log2(n)) ; 
    int tree_size = ( 1 << (h + 1)) ; 
    vector<ll> tree(tree_size) ;

    for (int i = 0 ; i < n ;i++) cin >> A[i] ; 

    init(A, tree, 1, 0, n - 1 ); 

    int T = m + k ;
    while (T--) {
        int t ; cin >> t; 
        if ( t == 1 ) { 
            int idx, val ; cin >> idx >> val ; 
            update(tree, 1, 0, n - 1, idx - 1, val) ; 
        }
        else if ( t == 2 ) { 
            int l, r ; cin >> l >> r; 
            cout << query(tree, 1, 0, n - 1, l - 1, r -1) % MOD<<'\n' ;
        }
    }
    
    
    return 0;
}