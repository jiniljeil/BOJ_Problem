#include <iostream>
#include <queue> 

using namespace std; 
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0, -1 }; 
int N, M, K; // row, column, block 
int map[1001][1001];
int value[1001][1001][11];   
int main(void){
    scanf("%d %d %d",&N,&M,&K); 

    for(int i = 1 ; i <= N; i++) {
        for(int j = 1 ; j <= M; j++) {
            scanf("%1d", &map[i][j]); 
        }
    }
    bool check = false; 
    queue< pair<pair<int,int>, int>  > q; 
    q.push(make_pair(make_pair(1,1), K));  
    value[1][1][K] = 1 ; 
    while(!q.empty() && !check){
        int curr_x = q.front().first.first; 
        int curr_y = q.front().first.second; 
        int block = q.front().second;
        q.pop(); 

        if( curr_x == M && curr_y == N) { 
            printf("%d\n", value[curr_y][curr_x][block]); 
            check = true; 
            break; 
        }
        for(int i = 0 ; i < 4 ;i++) {
            int dir_x = curr_x + dx[i]; 
            int dir_y = curr_y + dy[i]; 

            if( dir_x < 1 || dir_x > M || dir_y < 1 || dir_y > N) continue;
            
            if( map[dir_y][dir_x] == 1 && block && value[dir_y][dir_x][block-1] == 0){ 
                value[dir_y][dir_x][block-1] = value[curr_y][curr_x][block] + 1 ; 
                q.push(make_pair(make_pair(dir_x,dir_y), block-1)); 
            }
            if( map[dir_y][dir_x] == 0 && value[dir_y][dir_x][block] == 0 ) {
                value[dir_y][dir_x][block] = value[curr_y][curr_x][block] + 1;  
                q.push(make_pair(make_pair(dir_x,dir_y), block)); 
            }
        }
    }
    if( !check ){ 
        printf("-1\n");
    }
    return 0; 
}