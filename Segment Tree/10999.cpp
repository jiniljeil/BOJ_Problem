#include <bits/stdc++.h>
#define SIZE 1000010

using namespace std ;

typedef long long ll; 

ll N, M, K ; 
ll A[SIZE] ; 
ll a, b, c, d; 
void init(ll A[SIZE], vector<ll> &tree, ll node, ll start, ll end ){ 
    if ( start == end ) { 
        tree[node] = A[start] ; 
    } else { 
        init(A, tree, node * 2, start,  (start + end) / 2 );
        init(A,tree, node * 2 + 1,  (start + end) / 2 + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1] ; 
    }
}

void update_lazy(vector<ll> &tree, vector<ll> &lazy, ll node, ll start, ll end) {
    if ( lazy[node] != 0 ) {
        tree[node] += (end - start + 1) * lazy[node]; 

        if ( start != end ) { 
            lazy[node * 2] += lazy[node] ;
            lazy[node * 2 + 1] += lazy[node]; 
        }
        lazy[node] = 0; 
    }
}
void update_range(vector<ll> &tree, vector<ll> &lazy, ll node, ll start, ll end, ll l, ll r, ll val) {
    update_lazy(tree, lazy, node, start, end) ;
    if ( l > end || r < start ) return ; 
    if ( l <= start && end <= r ) { 
        tree[node] += (end - start + 1) * val ; 
        if ( start != end ) { 
            lazy[node * 2] += val ; 
            lazy[node * 2 + 1] += val ; 
        }
        return ;
    }
    update_range(tree,lazy, node * 2, start, (start + end) / 2, l, r, val) ; 
    update_range(tree,lazy, node * 2 + 1, (start + end)/2 + 1, end, l , r, val) ; 
    tree[node] = tree[node * 2] + tree[node* 2 + 1] ; 
}

ll query(vector<ll> &tree, vector<ll> &lazy, ll node, ll start, ll end, ll l, ll r) { 
    update_lazy(tree, lazy, node, start, end);
    if ( l > end || r < start ) return 0 ; 
    if ( l <= start && end <= r ) return tree[node] ; 

    ll lsum = query(tree, lazy, node * 2, start, (start + end) / 2, l, r) ; 
    ll rsum = query(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, l, r) ; 

    return lsum + rsum ; 
}

int main() {    
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> N >> M >> K ;   
    
    ll h = (ll)ceil(log2(N));
    ll tree_size = ( 1 << (h + 1)) ; 

    vector<ll> tree(tree_size) ; 
    vector<ll> lazy(tree_size) ; 

    for (ll i = 0 ; i < N ; i++) { 
        cin >> A[i] ;
    }

    init(A, tree, 1, 0, N - 1) ; 

    M += K ; 
    
    while(M--){ 
        cin >> a ;
        if ( a == 1 ) { 
            cin >> b >> c >> d;  
            update_range(tree, lazy, 1, 0, N - 1, b - 1, c - 1, d) ; 
        } else if ( a == 2 ) { 
            cin >> b >> c ; 
            cout << query(tree, lazy, 1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }
    return 0; 
}