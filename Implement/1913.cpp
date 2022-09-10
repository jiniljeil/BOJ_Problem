#include <iostream> 

using namespace std; 

int MAP[1000][1000] ; 
int N, K ; 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0} ; 

bool range(int y, int x) { 
    if ( y < 1 || y >= (N + 1) || x < 1 || x >= (N + 1)) return false; 
    else if ( MAP[y][x] !=  0) return false; 
    return true ;
}
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N ; 
    cin >> K ; 

    int i = 1, j = 1 ; 
    int k = 0 ; 
    int cnt = N * N ; 
    int ans_i = -1, ans_j = -1 ; 

    while (1) { 
        if ( cnt == K ) { ans_i = i ; ans_j = j ; }

        MAP[i][j] = cnt--; 

        if ( i == (N/2 + 1) && j == (N/2 + 1)) break ;

        int dir_y = i + dy[k] ; 
        int dir_x = j + dx[k] ; 

        if (!range(dir_y, dir_x)) { 
            k = (k + 1) % 4 ;
            cnt++; 
        } else { 
            i = dir_y ; j = dir_x ; 
        }
    }

    for (int i = 1 ; i <= N ; i++) { 
        for (int j = 1 ; j <= N ; j++) { 
            cout << MAP[i][j] << ' ' ;
        }
        cout << '\n'; 
    }

    cout << ans_i << ' ' << ans_j << '\n'; 
    return 0;
}