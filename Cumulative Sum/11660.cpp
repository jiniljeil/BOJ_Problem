#include <bits/stdc++.h>
#define SIZE 1025 
using namespace std;

int A[SIZE][SIZE] ;
int N, M ;  
int sum[SIZE][SIZE] ; 
int main() { 
    ios::sync_with_stdio(0) ; cin.tie(0) ;

    cin >> N >> M ; 

    for (int i = 0 ; i < N ; i++) { 
        for (int j = 0 ; j < N ;j++) {
            cin >> A[i][j]; 
        }
    }

    for (int i = 0 ; i < N ; i++) { 
        for (int j = 0 ; j < N ;j++) { 
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + A[i][j] ; 
        }
    }

    for (int i = 0 ; i < M ; i++) { 
        int x1,y1,x2,y2 ; 
        cin >> x1 >> y1 >> x2 >> y2 ; 
        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}