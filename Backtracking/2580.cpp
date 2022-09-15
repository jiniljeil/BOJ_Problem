#include <iostream> 
using namespace std; 

int MAP[9][9] ;

void Input_Output(int type) { 
    for (int i = 0 ; i < 9 ; i++) { 
        for (int j = 0 ; j < 9 ; j++) { 
            if ( type == 0 ) cin >> MAP[i][j] ; 
            else cout << MAP[i][j] << ' '; 
        }
        if ( type != 0 ) cout << '\n'; 
    }
}

bool check(int y, int x, int num) {
    for (int i = 0 ; i < 9 ; i++) { 
        if ( MAP[i][x] == num || MAP[y][i] == num ) return false ; 
    }

    int tx = x / 3 * 3, ty = y / 3 * 3 ; 

    for (int i = ty ; i < ty + 3 ; i++) { 
        for (int j = tx ; j < tx + 3 ; j++) { 
            if ( MAP[i][j] == num ) { 
                return false; 
            }
        }
    }

    return true ; 
}

bool finish() {
    for (int i = 0 ; i < 9 ; i++) { 
        for (int j = 0 ; j < 9 ; j++) { 
            if ( MAP[i][j] == 0 ) return false; 
        }
    }
    return true ; 
}

void Backtrack(int p) { 
    for (int i = p ; i < 9; i++) { 
        for (int j = 0 ; j < 9; j++) {
            if ( MAP[i][j] != 0 ) continue; 

            for (int k = 1; k <= 9 ; k++) { 
                if ( check(i, j, k) ) { 
                    MAP[i][j] = k ; 
                    Backtrack(i) ; 
                    if ( finish() ) return ; 
                    MAP[i][j] = 0 ;
                }
            }
            return ;
        }
    }
}

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    Input_Output(0) ; 
    Backtrack(0);
    Input_Output(1) ; 
    return 0 ;
}