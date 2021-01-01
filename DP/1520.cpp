#include <iostream>
#include <string.h> 
using namespace std;
int map[501][501]; 
int dp[501][501];
int dx[4] = {-1, 0 ,1 ,0} ;
int dy[4] = {0, 1 ,0 ,-1} ;
int row ,col, dir_x, dir_y; 

int DFS(int y, int x){ 
    if(y == row && x == col) return 1;
    if(dp[y][x] != -1) return dp[y][x]; // 방문 여부 
    dp[y][x] = 0 ; 
    for(int i = 0 ; i < 4 ; i++){
        dir_x = x + dx[i]; 
        dir_y = y + dy[i]; 
        if( dir_x >= 1 && dir_x <= col && dir_y >= 1 && dir_y <= row) {
            if( map[dir_y][dir_x] < map[y][x] ){
                    dp[y][x] += DFS(dir_y, dir_x); 
            } 
        }
    }
    return dp[y][x];
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL) ;
    cout.tie(NULL) ; 
    cin >> row >> col ;

    memset(dp, -1 , sizeof(dp)); 
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++) {
            cin >> map[i][j] ; 
        }
    }

    cout << DFS(1,1) << "\n";

    return 0; 
}