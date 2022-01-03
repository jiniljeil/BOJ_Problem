/*

8 9
0 0 0 0 0 0 0 0 0
0 0 0 1 1 0 0 0 0
0 0 0 1 1 0 1 1 0
0 0 1 1 1 1 1 1 0
0 0 1 1 1 1 1 0 0
0 0 1 1 0 1 1 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

8 9 
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 1 1 0
0 1 0 1 1 1 0 1 0
0 1 0 0 1 0 0 1 0
0 1 0 1 1 1 0 1 0
0 1 1 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0

*/

#include <iostream> 
#include <queue> 
#include <cstring> 
#define MAX 101
using namespace std; 

int MAP[MAX][MAX]; 
int value[MAX][MAX]; 
int dx[4] = {-1, 0, 1, 0} ; 
int dy[4] = { 0, 1, 0,-1} ; 
int R, C ; 
int result ; 
vector<int> outside_v ; 

void Outside() { 
    int p = 0 ; 
    memset(value, 0, sizeof(value)) ; 

    for (int i = 0 ; i < R; i++) {
        for (int j = 0 ; j < C; j++) {
            if ( MAP[i][j] == 0 && value[i][j] == 0) { 

                bool out = false; 
                p--; 
                queue<pair<int,int> > Q; 

                Q.push(make_pair(j, i)) ; 
                value[i][j] = p ; 

                while(!Q.empty())  {
                    int curr_x = Q.front().first ; 
                    int curr_y = Q.front().second ; 
                    Q.pop() ;

                    for (int k = 0 ; k < 4 ; k++) {
                        int dir_x = curr_x + dx[k] ; 
                        int dir_y = curr_y + dy[k] ; 

                        if (dir_x < 0 || dir_x >= C || dir_y < 0 || dir_y >= R) {
                            out = true; 
                            continue ; 
                        }

                        if (MAP[dir_y][dir_x] != 0 || value[dir_y][dir_x] != 0) continue ; 
                        
                        value[dir_y][dir_x] = p ; 
                        Q.push(make_pair(dir_x, dir_y)) ; 
                    }
                }
                
                // 바깥 영역의 경우 저장
                if ( out ) {
                    outside_v.push_back(p) ; 
                }
            } else if ( MAP[i][j] == 1 ) { 
                value[i][j] = 1; 
            }
        }
    }
}


void Remove() { 
    for (int i = 0 ; i < R ; i++ ) { 
        for (int j = 0 ; j < C ; j++) { 
            if ( MAP[i][j] == 1 ) { 
                int c = 0 ; 
                int dirV[4] = {0, } ; 
                for (int k = 0 ; k < 4; k++) { 
                    int dir_x = j + dx[k] ; 
                    int dir_y = i + dy[k] ;

                    if ( dir_x < 0 || dir_x >= C || dir_y < 0 || dir_y >= R) continue ; 
                    if ( value[dir_y][dir_x] < 0 ) { 
                        dirV[k] = value[dir_y][dir_x] ; 

                        // 인접한 칸들 중 2개가 외부 영역인 경우
                        for (int ch = 0 ; ch < k ; ch++) {
                            if ( dirV[ch] != 0 && dirV[ch] == value[dir_y][dir_x] ) { 
                                bool check = false ; 
                                for (int p = 0 ; p < outside_v.size(); p++) {
                                    if ( outside_v[p] == dirV[ch] ) { 
                                        check = true; 
                                        break ;
                                    }
                                }

                                if ( check ) {
                                    MAP[i][j] = 0 ; 
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

bool Finish() { 
    int v = value[0][0]; 
    for (int i = 0 ; i < R; i++ ) {
        for (int j = 0; j < C; j++) { 
            if ( v != value[i][j]) {
                return false; 
            }
        }
    }

    return true; 
}

void Input() {
    cin >> R >> C; 

    for (int i = 0 ; i < R; i++) {
        for (int j = 0 ; j < C; j++) { 
            cin >> MAP[i][j] ; 
        }
    }
}

int main(void) { 
    ios::sync_with_stdio(false) ; 
    cin.tie(0); 

    Input() ;

    while (1) { 
        Outside(); 
        if ( Finish() ) break; 
        Remove() ; 
        result++; 
        outside_v.clear();
    }
    
    cout << result << '\n'; 
    return 0 ;
}