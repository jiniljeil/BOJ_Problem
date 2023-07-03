#include <bits/stdc++.h> 

using namespace std ;

int N, M ; 

void minInit(vector<int> &A, vector<int> &minTree, int node, int start, int end) { 
    if ( start == end ) minTree[node] = A[start] ; 
    else { 
        minInit(A, minTree, node * 2, start, (start + end) / 2) ; 
        minInit(A, minTree, node * 2 + 1, (start + end) / 2 + 1, end) ;
        minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1])  ;
    }
}

void maxInit(vector<int> &A, vector<int> &maxTree, int node, int start, int end) { 
    if ( start == end ) maxTree[node] = A[start] ;
    else { 
        maxInit(A, maxTree, node * 2, start, (start + end) / 2 ) ; 
        maxInit(A, maxTree, node * 2 + 1, (start + end) / 2 + 1 , end) ; 
        maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]) ; 
    }
}

int findMin(vector<int> &A, vector<int> &minTree, int node, int start, int end, int left, int right) { 
    if ( left > end || right < start ) return -1 ; 
    if ( left <= start && end <= right ) return minTree[node] ; 

    int lmin = findMin(A, minTree, node * 2, start, (start + end) / 2, left ,right)  ;
    int rmin = findMin(A, minTree, node * 2 + 1, (start + end) / 2 + 1, end, left, right ) ;

    if ( lmin == -1 ) return rmin ; 
    else if ( rmin == -1 ) return lmin ; 
    else return min(lmin, rmin) ; 
}

int findMax(vector<int> &A, vector<int> &maxTree, int node, int start ,int end, int left, int right) { 
    if ( left > end || right < start ) return -1 ; 
    if ( left <= start && end <= right ) return maxTree[node] ; 

    int lmax = findMax(A, maxTree, node * 2, start, (start + end) / 2, left ,right)  ;
    int rmax = findMax(A, maxTree, node * 2 + 1, (start + end) / 2 + 1, end, left, right ) ;

    if ( lmax == -1 ) return rmax ; 
    else if ( rmax == -1 ) return lmax ; 
    else return max(lmax, rmax) ; 
}

int main() { 
    ios::sync_with_stdio(0) ; cin.tie(0) ; 

    cin >> N >> M ; 

    vector<int> A(N) ; 

    int h = (int)ceil(log2(N)) ;
    int tree_size = ( 1 << (h + 1)) ; 

    vector<int> minTree(tree_size) ; 
    vector<int> maxTree(tree_size) ;

    for (int i = 0 ; i < N ; i++) cin >> A[i] ;

    minInit(A, minTree, 1, 0, N - 1) ; 
    maxInit(A, maxTree, 1, 0, N - 1) ;

    for (int i = 0 ; i < M ; i++) { 
        int l, r ; cin >> l >> r ;
        cout << findMin(A, minTree, 1, 0, N - 1, l - 1, r - 1) << ' ' << findMax(A, maxTree, 1, 0, N - 1, l - 1, r - 1) << '\n' ; 
    }
    return 0; 
}