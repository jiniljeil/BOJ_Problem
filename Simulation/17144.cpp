#include <iostream>
#include <string.h>

using namespace std;

int R, C, T ; 
int map[50][50];
int copy_map[50][50]; 
int copy_2_map[50][50];
pair<int,int> up,down; 
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0 ,-1};

void divide_dust() {
    for(int i = 0 ; i < R; i++) {
        for(int j = 0 ;j < C; j++) {
            if( map[i][j] > 0 ) {
                int value = map[i][j]/5; 
                int c = 0 ; 
                for(int k = 0 ; k < 4; k++) {
                    int dir_x = j + dx[k]; 
                    int dir_y = i + dy[k];
                    if( dir_x < 0 || dir_x >= C || dir_y < 0 || dir_y >= R) continue;
                    if( map[dir_y][dir_x] == -1) continue;
                    c++;
                    copy_map[dir_y][dir_x] += value; 
                }
                copy_map[i][j] -= value * c;
            }
        }
    }
}

void move() {   
    for(int i = 0 ; i < R; i++) {
        for(int j = 0 ;j < C; j++) {
            copy_2_map[i][j] = copy_map[i][j];
        }
    }
    // up / right
    for(int i = up.first; i < C - 1; i++) {
        if(i == up.first) copy_2_map[up.second][i+1] = 0;
        else copy_2_map[up.second][i+1] = copy_map[up.second][i];
    }
    // up / up 
    for(int i = up.second; i >= 1;  i--) {
        copy_2_map[i-1][C-1] = copy_map[i][C-1];
    }
    // up / left
    for(int i = C - 1; i >= 1; i--) {
        copy_2_map[0][i-1] = copy_map[0][i];
    }
    // up / down 
    for(int i = 0 ; i < up.second - 1; i++) {
        copy_2_map[i+1][0] = copy_map[i][0];
    }
    // down / right
    for(int i = down.first; i < C - 1; i++) {
        if(i == down.first) copy_2_map[down.second][i+1] = 0;
        else copy_2_map[down.second][i+1] = copy_map[down.second][i];
    }
    // down / down 
    for(int i = down.second ; i < R - 1; i++) {
        copy_2_map[i+1][C-1] = copy_map[i][C-1];
    }
    // down / left 
    for(int i = C - 1; i >= 1; i--) {
        copy_2_map[R-1][i-1] = copy_map[R-1][i];
    }
    // down // up 
    for(int i = R-1; i > down.second + 1;  i--) {
        copy_2_map[i-1][0] = copy_map[i][0];
    }
}
void copy_original() {
    for(int i = 0 ; i < R; i++) {
        for(int j = 0 ; j < C ; j++) {
            copy_map[i][j] = map[i][j];
        }
    }
}
void copy() { 
    for(int i = 0 ; i < R; i++) {
        for(int j = 0 ; j < C ; j++) {
            map[i][j] = copy_2_map[i][j];
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> R >> C >> T; 
    
    bool next = false; 
    for(int i = 0 ; i < R ; i++) {
        for(int j = 0 ;j < C; j++) {
            cin >> map[i][j] ; 
            if( map[i][j] == -1) {
                if(!next) { 
                    up.first = j;  // x 
                    up.second = i; // y 
                    next = true;   
                }else {
                    down.first = j;
                    down.second = i ;
                }
            }
        }
    }

    for(int i = 0 ; i < T ; i++) { 
        copy_original();
        divide_dust() ; 
        move();
        copy();
    }
    int result = 0 ;
    for(int i = 0 ; i < R; i++) {
        for(int j = 0 ; j < C; j++) {
            if( map[i][j] != -1) {
                result += map[i][j] ;
            }
        }
    }
    cout << result << '\n';
    return 0;
}