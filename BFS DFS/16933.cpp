#include <iostream>
#include <queue> 

using namespace std; 
int N, M, K; 
int map[1001][1001]; 
int value[1000][1000][11]; 
int dx[4] = {-1, 0 , 1, 0}; 
int dy[4] = {0, 1, 0, -1};
int main(void){
    scanf("%d %d %d",&N, &M, &K); 

    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            scanf("%1d", &map[i][j]); 
        }
    }

    queue< pair< pair<pair<int,int>,int> , pair<int,int> > >  q;
    int currTime = 0; // 0 : 낮 , 1 : 밤 
    q.push(make_pair(make_pair(make_pair(0,0),1),make_pair(currTime, 0)));
    value[0][0][0] = 1 ; 
    bool check = false; 
    while(!q.empty() && !check){ 
        int curr_x = q.front().first.first.first;
        int curr_y = q.front().first.first.second;
        int result = q.front().first.second; 
        int time = q.front().second.first; 
        int block = q.front().second.second; 
        q.pop(); 
        if( curr_y == N - 1 && curr_x == M - 1) { 
            printf("%d\n", result); 
            check = true; 
            break; 
        }
        for(int i = 0 ; i < 4; i++) { 
            int dir_x = curr_x + dx[i]; 
            int dir_y = curr_y + dy[i]; 
            
            if( dir_x < 0 || dir_x >= M || dir_y < 0 || dir_y >= N ) continue; 

            if( map[dir_y][dir_x] == 0 && value[dir_y][dir_x][block] == 0 ) {
                value[dir_y][dir_x][block] = value[curr_y][curr_x][block] + 1 ;
                q.push(make_pair(make_pair(make_pair(dir_x,dir_y), result + 1), make_pair(!time, block)));
            }
            else if( map[dir_y][dir_x] == 1 && (block < K) && value[dir_y][dir_x][block+1] == 0 ){
                if( time == 0){
                    // cout << "X: " <<  curr_x << "Y: " << curr_y << "\n";
                    value[dir_y][dir_x][block +1] = value[curr_y][curr_x][block] + 1; 
                    q.push(make_pair(make_pair(make_pair(dir_x,dir_y), result + 1), make_pair(!time, block+1)));
                }else{
                    value[curr_y][curr_x][block] = value[curr_y][curr_x][block] + 1; 
                    q.push(make_pair(make_pair(make_pair(curr_x,curr_y), result + 1), make_pair(!time,block)));
                }
            }
        }
    }
    if( !check ){
        printf("-1\n");
    }
    return 0;
}

