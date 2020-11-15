#include <vector>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int **map;
bool **visit;
int row, column;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
int BFS(){
    int result = 0 ;
    queue<pair<int,int>> q ;
    
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ;j <column; j++){
            if( map[i][j] == 1){
                bool check = true;
                int curr_x = j;
                int curr_y = i ;
                
                q.push(make_pair(curr_x, curr_y));
                while(!q.empty()){
                    curr_x = q.front().first;
                    curr_y = q.front().second;
                    q.pop();
                    bool t = false;
                    for(int k = 0 ;k < 4; k++){
                        int dir_x = curr_x + dx[k];
                        int dir_y = curr_y + dy[k];
                        if ( dir_x >= 0 && dir_x < column && dir_y >= 0 && dir_y < row && map[dir_y][dir_x] == 0 && !visit[dir_y][dir_x]){
                            visit[dir_y][dir_x] = true;
                            map[dir_y][dir_x] += map[curr_y][curr_x];
                            q.push(make_pair(dir_x, dir_y));
                            
                            t = true;
                        }
                    }
                    if(t) result++;
                    
                    
                    for(int it = 0 ; it < row; it++){
                        for(int jt = 0 ;jt < column; jt++){
                            cout << map[it][jt] << " ";
                        }
                        cout << endl;
                    }
                    cout << endl << result << endl;
                    for(int it = 0 ; it < row; it++){
                        for(int jt = 0 ;jt < column; jt++){
                            if( map[it][jt] == 0) {
                                check = false;
                                break;
                            }
                        }
                        if( !check ) break;
                    }
                    if( check ) {
                        return result ;
                    }
                }
                
            }
        }
    }
    
    
    return result;
}
int main() {
    
    scanf("%d %d",&column, &row);
    getchar();
    map = (int**)malloc(sizeof(int*) * row) ;
    visit =(bool**)malloc(sizeof(bool*) * row);
    for(int i = 0 ; i < row; i++){
        map[i] = (int*)malloc(sizeof(int) * column);
        visit[i] = (bool*)malloc(sizeof(bool) * column);
    }
    
    for(int i = 0 ; i < row; i++){
            for(int j= 0 ; j < column; j++){
                if( j != column -1){
                    scanf("%d ",&map[i][j]);
                }else{
                    scanf("%d",&map[i][j]);
                }
            }
            getchar();
    }
    
    cout << BFS();
    return 0;
}
