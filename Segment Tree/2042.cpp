#include <iostream> 
#include <vector> 
#include <cmath> 
#define MAX 1000010
typedef long long ll ; 
using namespace std ;

int N, M, K ; 
ll a, b, c ; 
ll V[MAX] ;

class SegmentTree { 
private: 
    ll * tree ; 
    int size ; 
public: 
    SegmentTree(int arrSize) {
        int h = ceil(log2(arrSize)) ; 
        this->size = (int) pow(2, h + 1) ; 
        tree = new ll[this->size] ; 
    }
    ~SegmentTree() { 
        free(tree) ; 
    }

    ll init(ll arr[], int node, int start, int end) {
        if ( start == end ) {
            return tree[node] = arr[start] ; 
        }
        ll mid = (start + end) /2 ; 
        return tree[node] = init(arr, node * 2, start, mid) + init(arr, node * 2 + 1, mid + 1, end) ; 
    }

    void update(int node, int start, int end, int idx, ll diff) { 
        if (idx < start || idx > end ) return ; 

        tree[node] += diff ;

        if ( start != end ) { 
            ll mid = (start + end) / 2 ;
            update(node * 2, start, mid, idx, diff) ;
            update(node * 2 + 1, mid + 1 , end, idx, diff) ; 
        }
    }

    ll sum(int node, int start, int end, int left, int right) { 
        if ( left > end || right < start ) return 0 ;
        
        if ( left <= start && right >= end ) { 
            return tree[node] ; 
        }

        ll mid = (start + end)/2; 
        return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right) ; 
    }
};

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    ll num ; 
    cin >> N >> M >> K ; 

    for (int i = 1; i <= N; i++) {
        cin >> num ;
        V[i] = num ;
    }

    SegmentTree *st = new SegmentTree(N); 

    st->init(V, 1, 1, N); 

    for (int i = 0 ; i < M + K ; i++) { 
        cin >> a >> b >> c ; 
        
        if ( a == 1 ) { 
            st->update(1, 1, N, b, c - V[b]) ; 
            V[b] = c; 
        } else { 
            cout << st->sum(1, 1, N, b, c) << '\n'; 
        }
    }

    free(st) ;
    return 0 ;
}