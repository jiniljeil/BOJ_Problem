#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001];
int value[1001][1001][2];

int dx[4] = {-1, 0 , 1 , 0} ;
int dy[4] = {0, 1, 0 , -1} ;

void BFS(int row, int col){
    queue<pair<pair<int,int>, int> >queue; // second: 벽을 부술 수 있는 횟수
    value[1][1][1] = 1;
    queue.push(make_pair(make_pair(1, 1),1));
    
    while(!queue.empty()){
        int currX = queue.front().first.first;
        int currY = queue.front().first.second;
        int block = queue.front().second;
        queue.pop();
        
        if( currX == col && currY == row ){
            printf("%d\n", value[currY][currX][block]);
            return ;
        }
        
        for(int i = 0 ; i < 4 ; i++){
            int dirX = currX + dx[i];
            int dirY = currY + dy[i];
            
            // 범위 내에
            if( dirX >= 1 && dirY >= 1 && dirX <= col && dirY <= row){
                // 벽을 부술 수 있고 벽이 있으면
                if( map[dirY][dirX] == 1 && block ){
                    value[dirY][dirX][block -1] = value[currY][currX][block] + 1;
                    queue.push(make_pair(make_pair(dirX, dirY), block-1));
                }
                
                if( map[dirY][dirX] == 0 && value[dirY][dirX][block] == 0 ){
                    value[dirY][dirX][block] = value[currY][currX][block] + 1;
                    queue.push(make_pair(make_pair(dirX, dirY), block));
                }
            }
        }
    }
    
    printf("-1\n");
    return ;
}

int main() {
    int row, col ;
    
    scanf("%d %d", &row, &col);
    
    for(int i = 1 ; i <= row; i++){
        for(int j = 1; j <= col ; j++){
            scanf("%1d",&map[i][j]);
        }
    }
    
    BFS(row, col);
    
    return 0;
}

/*
 6 4
 0000
 1110
 1000
 0000
 0111
 0000
 */
