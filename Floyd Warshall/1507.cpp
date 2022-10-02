#include <iostream> 

using namespace std ;

int N ; 
int MAP[21][21] ; 
bool visited[21][21] ; 
int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 

    cin >> N ; 
    for (int i = 0 ; i < N ; i++) { 
        for (int j = 0 ; j < N ; j++) { 
            cin >> MAP[i][j] ;  
        }
    }

    for (int k = 0 ; k < N ; k++) { 
        for (int i = 0 ; i < N ; i++) { 
            if ( i == k ) continue ; 
            for (int j = 0 ; j < N ; j++) { 
                if ( i == k || k == j ) continue ; 
                if ( MAP[i][j] > MAP[i][k] + MAP[j][k] ) { 
                    cout << "-1" << '\n'; 
                    return 0 ; 
                } else if ( MAP[i][j] == MAP[i][k] + MAP[k][j] ) { 
                    visited[i][j] = true ; 
                }
            }   
        }
    }

    long long answer = 0 ; 
    for (int i = 0 ; i < N ; i++) { 
        for (int j = 0 ; j < N ; j++) { 
            if ( visited[i][j] ) continue ; 
            answer += MAP[i][j] ; 
        }
    }

    cout << answer / 2 << '\n' ; 
    return 0 ;
}