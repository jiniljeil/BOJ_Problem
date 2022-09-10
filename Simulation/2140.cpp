#include <iostream> 
#include <string> 
using namespace std ;

int N ; 
char MAP[101][101]; 
string s ; 
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1} ; 
int dy[8] = {-1,-1,-1, 0, 0, 1, 1, 1} ; 
int answer = 0 ;
void Input() { 
    cin >> N ;

    for (int i = 0 ; i < N ;i++) { 
        cin >> s ; 
        for (int j = 0 ; j < N ; j++) { 
            MAP[i][j] = s[j] ; 
        }
    }
}

void BFS(int i, int j) {
    bool zero_check = false ; 
    for (int k = 0 ; k < 8 ; k++) { 
        int nx = j + dx[k] ; 
        int ny = i + dy[k] ; 

        if ( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue ; 
        if ( MAP[ny][nx] == '0') { zero_check = true ; break ;} 
    }

    if ( !zero_check ) { 
        for (int k = 0 ; k < 8; k++) { 
            int nx = j + dx[k] ; 
            int ny = i + dy[k] ; 

            if ( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue ; 
            if ( MAP[ny][nx] >= '0' && MAP[ny][nx] <= '9') MAP[ny][nx]--; 
        }
    } else { 
        answer--; 
    }
}

int main(void) { 
    ios::sync_with_stdio(false);
    cin.tie(0) ; 

    Input() ;

    if ( N <= 2 ) { cout << '0' << '\n'; return 0 ; } 

    answer = (N - 2) * (N - 2) ; 

    for (int i = 1 ; i < N - 1 ; i++) { 
        for (int j = 1 ; j < N - 1 ; j++) { 
            if ( i == 1 || j == 1 || i == N - 2 || j == N - 2 ) { 
                BFS(i, j); 
            }
        }
    }

    cout << answer << '\n'; 
    return 0 ;
}