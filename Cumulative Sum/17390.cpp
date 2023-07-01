#include <bits/stdc++.h>

using namespace std ;

int N, M ; 
int A[300010];
int S[300010]; 
int main(void) {
    ios::sync_with_stdio(0) ; cin.tie(0) ;

    cin >> N >> M ; 
    for (int i = 0 ; i < N ; i++) cin >> A[i] ; 
    sort(A, A + N) ;

    for (int i = 0 ; i < N ; i++) {
        S[i + 1] = S[i] + A[i] ; 
    }

    for (int i = 0 ; i < M ; i++) { 
        int a, b; cin >> a >> b; 
        cout << S[b] - S[a - 1] << '\n'; 
    }
    return 0 ;
}