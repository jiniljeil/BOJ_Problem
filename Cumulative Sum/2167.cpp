#include <iostream> 

using namespace std ;

int A[301][301] ; 
int S[301][301] ;
int N, M, K ; 

/*
1 2 3 
4 5 6
7 8 9

 1  3  6
 5 12 21
12 27 45
S[i][j] = A[i][j] - S[i - 1][j - 1] + S[i][j - 1] + S[i - 1][j] ;  
*/
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N >> M ; 
    for (int i = 1 ; i <= N ; i++) { 
        for (int j = 1 ; j <= M ; j++) { 
            cin >> A[i][j] ; 
        }
    }

    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1; j <= M ; j++) { 
            S[i][j] = A[i][j] - S[i-1][j-1] + S[i][j-1] + S[i-1][j] ;  
        }
    }
    cin >> K ; 
    for (int i = 0 ; i < K ; i++) { 
        int a1,b1,a2,b2 ; 
        cin >> a1 >> b1 >> a2 >> b2; 
        cout << S[a2][b2] - S[a1-1][b2] - S[a2][b1-1] + S[a1-1][b1-1] << '\n';
    } 
    return 0 ; 
}