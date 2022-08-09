#include <iostream> 

using namespace std; 

int TC ; 
int R, C ; 
int arr[101][101] ; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> TC ; 

    while(TC--) { 
        cin >> R >> C ; 
        int n = 0 ; 
        int c = 0 ; 
        for (int i = 0 ; i < R ;i++) { 
            for (int j = 0 ; j < C ;j++) {
                cin >> n ; arr[i][j] = n ;
            }
        }
        
        for (int i = R - 1; i >= 0 ; i--) { 
            for (int j = 0 ; j < C ; j++) { 
                if ( arr[i][j] == 0 ) { 
                    for (int k = i - 1 ; k >= 0 ; k--) { 
                        if ( arr[k][j] == 1 ) { 
                            c += (i - k);
                            arr[k][j] = 0 ; 
                            arr[i][j] = 1 ; 
                            break ;
                        }
                    }
                }
            }
        }
        cout << c << '\n'; 
    }
    return 0 ;
}