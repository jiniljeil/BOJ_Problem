#include <bits/stdc++.h> 
#define SIZE 100010
using namespace std ;

int N, M ; 

void init(vector<int> &A, vector<int> &tree, int node, int start, int end) { 
    if ( start == end ) {
        tree[node] = A[start] ; 
    } else {
        init(A, tree, node * 2, start, (start + end) / 2 ) ;  
        init(A, tree, node * 2 + 1, (start + end) / 2 + 1, end) ; 
        tree[node] = min(tree[node * 2], tree[node * 2 + 1] );
    }
}

void update(vector<int> &A, vector<int> &tree, int node, int start, int end, int idx, int val) { 
    if ( idx < start || idx > end ) return ; 
    if ( start == end ) { 
        A[idx] = val ; 
        tree[node] = val ; 
        return  ;
    }
    update(A, tree, node * 2, start, (start + end) / 2, idx , val) ; 
    update(A, tree, node * 2 + 1, (start + end) / 2 + 1, end, idx , val ) ; 
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]) ;
}

int query(vector<int> &A, vector<int> &tree, int node, int start, int end, int left, int right) { 
    if ( left > end || right < start ) return -1; 
    if ( left <= start && end <= right ) return tree[node] ; 

    int lmin = query(A, tree, node * 2, start, (start + end) / 2, left, right ) ; 
    int rmin = query(A, tree, node * 2 + 1, (start + end) / 2 + 1, end, left ,right) ; 

    if ( lmin == -1 ) return rmin ; 
    else if ( rmin == -1 ) return lmin ; 
    else return min(lmin, rmin) ; 
}

int main() {
    ios::sync_with_stdio(0) ; cin.tie(0) ;

    cin >> N ; 
    vector<int> A(N) ; 
    int h = (int)ceil(log2(N)) ; 
    int tree_size = ( 1 << (h + 1)) ; 
    
    vector<int> tree(tree_size) ; 
    for (int i = 0 ; i < N ; i++ ) { 
        cin >> A[i] ; 
    }

    init(A, tree, 1, 0, N - 1) ; 
    cin >> M ; 

    while(M--) { 
        int t ; 
        cin >> t ; 
        if ( t == 1 ) { 
            int idx, val ; cin >> idx >> val ; 
            update(A,tree,1, 0, N - 1, idx - 1, val) ; 
        } else if ( t == 2 ) { 
            int left, right ; cin >> left >> right ;
            cout << query(A, tree, 1, 0, N - 1, left - 1, right -1) << '\n'; 
        }
    }
    return 0; 
}