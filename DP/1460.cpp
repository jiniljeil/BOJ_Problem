#include <bits/stdc++.h> 
#define SIZE 1001
using namespace std ; 

int N, M, X, Y, L, F ;
int A[SIZE][SIZE], B[SIZE][SIZE] ; 
int result ;

int main() { 
    ios::sync_with_stdio(0) ; cin.tie(0) ;
    cin >> N >> M ; N++;
    for (int i = 0 ; i < M ; i++) { 
        cin >> X >> Y >> L >> F ; 

        for (int x = X ; x < X + L ; x++) { 
            for (int y = Y; y < Y + L ; y++) { 
                A[x][y] = F; 
            }
        }
    }

    for (int f1 = 1 ; f1 <= 7 ; f1++) { 
        for (int f2 = f1 ; f2 <= 7; f2++) { 
            memset(B, 0, sizeof(B)); 

            for (int i = 0 ; i < N ; i++) { 
                for (int j = 0 ; j < N ; j++) { 
                    if ( f1 == A[i][j] || f2 == A[i][j] ) B[i][j] = 1; 
                }
            }

            for (int i = 1 ; i < N ; i++) { 
                for (int j = 1; j < N ; j++) { 
                    if ( !B[i][j] ) continue ; 
                    B[i][j] = min(B[i - 1][j], min(B[i - 1][j - 1], B[i][j - 1])) + 1; 
                    result = max(result, B[i][j]) ;
                }
            }
        }
    }

    cout << result  * result << '\n';
    return 0; 
}