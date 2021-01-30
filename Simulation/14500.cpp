#include <iostream>
#include <stack> 
#include <string.h>
using namespace std ;

int row, col; 
int map[500][500];
bool visited[500][500];
int max_result = 0; 
int dx[4] = {1, -1, 0, 0} ;
int dy[4] = {0, 0, 1, -1} ;

void DFS(int x, int y, int sum, int cnt) { 
    visited[y][x] = true; 
    if (cnt == 3)  {
        max_result = ( max_result < sum)? sum : max_result; 
        return ;
    }

    for(int i = 0 ; i < 4; i++) {
        int dir_x = x + dx[i];
        int dir_y = y + dy[i] ;
        if( dir_x < 0 || dir_x >= col || dir_y < 0 || dir_y >= row) continue; 
        if( visited[dir_y][dir_x]) continue; 
        DFS(dir_x,dir_y, sum+map[dir_y][dir_x], cnt + 1); 
        visited[dir_y][dir_x] = false; 
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    cin >> row >> col; 
    for(int i = 0 ; i < row; i++) {
        for(int j = 0 ; j < col; j++) {
            cin >> map[i][j] ; 
        }
    }

    stack<pair< pair<int,int> , pair<int,int> > > s ;
    
    for(int i = 0 ; i < row; i++){ 
        for(int j = 0; j < col; j++) {
            memset(visited, 0, sizeof(visited));
            DFS(j,i,map[i][j],0);
            int sum[4]= { 0, }; 
            // ㅜ 
            if(j + 2 < col && i + 1 < row) {
                sum[0] = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1];
            }
            // ㅗ
            if(j + 2 < col && i - 1 >= 0) {
                sum[1] = map[i][j] + map[i][j+1] + map[i-1][j+1] + map[i][j+2];
            }
            // ㅓ
            if(j + 1 < col && i - 1 >= 0 && i + 1 < row) { 
                sum[2] = map[i][j] + map[i-1][j+1] + map[i][j+1] + map[i+1][j+1];
            }
            // ㅏ 
            if(i + 2 < row && j + 1 < col) { 
                sum[3] = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1];
            }

            for(int k = 0 ; k < 4; k++) {
                if( max_result < sum[k]) { 
                    max_result = sum[k] ; 
                }
            }
        }
    }
    cout << max_result << '\n';
    return 0;
}