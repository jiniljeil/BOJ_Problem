#include <iostream>
#include <queue>

using namespace std;

int map[51][51];
int dist[51][51];
int dx[4] = {0,1,0,-1}; // 북 동 남 서
int dy[4] = {-1,0,1,0};

int turn_direction(int dir){
    if(dir == 0) return 3;
    else if(dir == 1) return 0;
    else if(dir == 2) return 1;
    else if(dir == 3) return 2;
    return -1;
}


int main(void) {
    int row, col ,r_robot,c_robot;
    int direction, count = 0 ; // 0 (북쪽), 1 (동쪽), 2 (남쪽), 3 (서쪽)
    
    queue<tuple<int,int,int>> queue;
    
    scanf("%d %d", &row, &col);
    scanf("%d %d %d",&r_robot, &c_robot, &direction);
    
    
    for(int i = 0 ; i < row ;i++){
        for(int j = 0 ; j < col; j++){
            if(j == col-1){
                scanf("%d",&map[i][j]);
            }else{
                scanf("%d ",&map[i][j]);
            }
        }
    }
    if( map[r_robot][c_robot] == 0 ){
        dist[r_robot][c_robot] = 1;
        queue.push({c_robot,r_robot, direction});
        
        while(!queue.empty()){
            int block_count = 0 ;
            int path_count = 0 ;
            int curr_x = get<0>(queue.front());
            int curr_y = get<1>(queue.front());
            direction = get<2>(queue.front());
            queue.pop();
             
            for(int i = 0 ; i < 4; i++){
                int direct = turn_direction(direction);
                int dir_x = curr_x + dx[direct];
                int dir_y = curr_y + dy[direct];
                
                if( map[dir_y][dir_x] == 1) {
                    block_count++;
                    continue;
                }
                if( dist[dir_y][dir_x] || map[dir_y][dir_x] == 1 ) {
                    path_count++;
                    direction = direct;
                    continue;
                }
                
                if(dir_x < 0 || dir_x > col || dir_y < 0 || dir_y > row) continue;
                if(map[dir_y][dir_x] == 1 || dist[dir_y][dir_x] > 0 ) continue;
                dist[dir_y][dir_x] = dist[curr_y][curr_x] + 1;
                queue.push({dir_x, dir_y, direct});
            }
            if(path_count == 4){
                int dir = (direction + 2) % 4;
                
            }
            if(block_count == 4) {
                for(int i = 0 ; i < row; i++){
                    for(int j = 0 ;j < col; j++){
                        count = max(count, dist[i][j]);
                    }
                }
                printf("%d\n",count);
                break;
            }
        }
    }else{
        printf("ERROR\n");
    }
    

    return 0;
}
