#include <iostream>
#include <vector> 
#include <cstring> 
using namespace std; 

int R, C, M; 
typedef struct shark { 
    short number ; 
    int r, c; 
    short speed ;
    short direction ;  /* 1: 위, 2: 아래, 3: 오른쪽, 4: 왼쪽 */
    int size ; 
} Shark ; 
int result = 0 ; 
short MAP[101][101] ;
vector<Shark> sharks ; 
int dx[5] = {0, -1, 1, 0, 0} ;  
int dy[5] = {0, 0, 0, 1, -1} ; 
void Input() { 

    cin >> R >> C >> M ; 

    for (int i = 0 ; i < M ;i++) {
        Shark new_shark ; 
        cin >> new_shark.r >> new_shark.c ; 
        cin >> new_shark.speed >> new_shark.direction >> new_shark.size ; 
        new_shark.number = i + 1 ; 

        MAP[new_shark.r][new_shark.c] = i + 1 ;
        sharks.push_back(new_shark) ; 
    }
}

void catch_shark(int column) {
    for (int i = 1 ; i <= R ; i++) {
        int shark_num = MAP[i][column] ;
        if ( shark_num != 0 ) { 
            for (int k = 0 ; k < sharks.size(); k++) {
                if ( shark_num == sharks[k].number ) { 
                    result += sharks[k].size ; 
                    sharks.erase(sharks.begin() + k) ; 
                    break; 
                }
            }
            break; 
        }
    }
}

void shark_move() { 

    for (int i = 0 ; i < sharks.size(); i++) {
        // 이동을 위해 상어 위치 초기화 
        int x = sharks[i].r, y = sharks[i].c ; 
        int speed = sharks[i].speed ; 

        if (sharks[i].direction <= 2) { 
            speed = speed % ((R - 1) * 2) ; 
        } else { 
            speed = speed % ((C - 1) * 2) ; 
        }

        for (int k = 0 ; k < speed ; k++) {
            if ( x == 1 && sharks[i].direction == 1 ) { 
                sharks[i].direction = 2 ; 
            } else if ( x == R && sharks[i].direction == 2 ) { 
                sharks[i].direction = 1 ; 
            } else if ( y == 1 && sharks[i].direction == 4 ) { 
                sharks[i].direction = 3 ; 
            } else if ( y == C && sharks[i].direction == 3 ) { 
                sharks[i].direction = 4 ; 
            }
            x += dx[sharks[i].direction] ; 
            y += dy[sharks[i].direction] ; 
        }
        sharks[i].r = x; 
        sharks[i].c = y; 
    }

    memset(MAP, 0, sizeof(MAP)) ; 

    for (int i = 0 ; i < sharks.size(); i++) {
        int r = sharks[i].r, c = sharks[i].c ;  
        if (  MAP[r][c] > 0 ) { 
            int pre_shark = -1; 
            for (int k = 0 ; k < sharks.size(); k++) { 
                if (sharks[k].number == MAP[r][c]) {
                    pre_shark = k ; 
                    break; 
                }
            }
            
            if ( sharks[pre_shark].size < sharks[i].size ) {
                MAP[r][c] = sharks[i].number ; 
                sharks.erase(sharks.begin() + pre_shark) ; 
                i--; 
            } else { 
                sharks.erase(sharks.begin() + i) ;
                i--; 
            }
        } else { 
            MAP[r][c] = sharks[i].number ; 
        }
    }
}

void Solve() { 
    // 한 칸 이동 
    for (int i = 1 ; i <= C ; i++) {
        // 상어 잡기 
        catch_shark(i) ; 
        // 상어 이동 
        shark_move() ; 
    }
    cout << result << '\n'; 
}

int main(void) { 
    ios::sync_with_stdio(false);  
    cin.tie(0) ; 

    Input() ; 
    Solve() ; 
    return 0 ; 
}