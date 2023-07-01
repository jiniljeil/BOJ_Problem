#include <bits/stdc++.h>
#define SIZE 1000010
using namespace std;

typedef unsigned long long ull ;
typedef long long ll; 
ull A[SIZE] ;
ull S ; 
int N, M ;
ll cnt ; 
int main() {
    ios::sync_with_stdio(0); cin.tie(0) ; 

    cin >> N >> M ;
    for (int i = 0, k; i < N ; i++) { 
        cin >> k; 
        S = (S + k % M) % M ; 
        A[S]++;
    }

    A[0]++;

    for (int i = 0; i < M ; i++) {
        if ( A[i] < 2 ) continue ;
        cnt += A[i] * (A[i] - 1) / 2;
    }
    cout << cnt << '\n';
    return 0;
}