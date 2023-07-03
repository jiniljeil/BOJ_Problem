#include <bits/stdc++.h> 

using namespace std ;

int N, M ; 

void init(vector<int> &A, vector<int> &tree, int node, int start, int end) { 
    if ( start == end ) tree[node] = A[start] ; 
    else { 
        init(A, tree, node * 2, start, (start + end) / 2) ; 
        init(A, tree, node * 2 + 1, (start + end) / 2 + 1, end) ;
        tree[node] = min(tree[node * 2], tree[node * 2 + 1])  ;
    }
}

int query(vector<int> &A, vector<int> &tree, int node, int start, int end, int left, int right) { 
    if ( left > end || right < start ) return -1 ; 
    if ( left <= start && end <= right ) return tree[node] ; 

    int lmin = query(A, tree, node * 2, start, (start + end) / 2, left ,right)  ;
    int rmin = query(A, tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right ) ;

    if ( lmin == -1 ) return rmin ; 
    else if ( rmin == -1 ) return lmin ; 
    else return min(lmin, rmin) ; 
}

int main() { 
    ios::sync_with_stdio(0) ; cin.tie(0) ; 

    cin >> N >> M ; 

    vector<int> A(N) ; 

    int h = (int)ceil(log2(N)) ;
    int tree_size = ( 1 << (h + 1)) ; 

    vector<int> tree(tree_size) ; 

    for (int i = 0 ; i < N ; i++) cin >> A[i] ;

    init(A, tree, 1, 0, N - 1) ; 

    for (int i = 0 ; i < M ; i++) { 
        int l, r ; cin >> l >> r ;
        cout << query(A, tree, 1, 0, N - 1, l - 1, r - 1) << '\n' ; 
    }
    return 0; 
}