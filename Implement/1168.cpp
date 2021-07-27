#include <iostream>
#include <vector> 
#define MAX 100001
using namespace std ;

int seg[4 * MAX]; 

// 세그먼트 트리 초기화
int seginit(int node, int start, int end) {
    if(start == end) return seg[node] = 1; // elements[start]; 
    int mid = (start + end) / 2 ; 
    return seg[node] = seginit(node * 2, start, mid) + seginit(node * 2 + 1, mid + 1, end); 
}

// 원소 삭제 
int segupdate(int node, int start, int end, int remove) { // 삭제할 원소
    seg[node]--; 
    if (start == end) return 0 ;
    int mid = (start + end) / 2; 
    if( remove <= mid ) return segupdate( 2 * node, start, mid, remove); 
    else return segupdate( 2 * node + 1, mid + 1, end, remove); 
}

// 다음 순서 찾기 
int next_num(int node, int start, int end, int order) {
    if (start == end) return start; 
    int mid = (start + end) / 2; 
    if( order <= seg[2 * node] ) return next_num(2 * node, start, mid, order) ;
    else return next_num(2 * node + 1, mid + 1, end, order - seg[2 * node]); 
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    int N, K, rN, curr; 

    cin >> N >> K ; 
    rN = N; curr = 1; 

    seginit(1, 1, N); 

    cout << "<" ; 
    for(int i = 0 ; i < N; i++) {
        curr += (K - 1); 
        if(curr % rN == 0) curr = rN; 
        else if (curr > rN) curr %= rN; 

        int num = next_num(1, 1, N, curr); 
        segupdate(1, 1, N, num);

        if (i < N - 1 ) cout << num << ", "; 
        else cout << num << ">"; 
        rN--;
    }
    

    return 0; 
}