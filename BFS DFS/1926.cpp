#include <iostream>
#include <queue> 
#define MAX 501 
using namespace std;
int map[MAX][MAX]; 
int visited[MAX][MAX];
int row, col ; 

int dx[4] = {-1, 0 ,1 ,0 };
int dy[4] = {0, 1 , 0, -1 };

int BFS(int x, int y ) {
    queue< pair<int, int> > q; 
    int width = 1 ;
    q.push(make_pair(x,y)); 

    while(!q.empty()){
        int curr_x = q.front().first ; 
        int curr_y = q.front().second ;
        q.pop();

        for(int i = 0 ; i < 4; i++){
            int dir_x = curr_x + dx[i];
            int dir_y = curr_y + dy[i] ;
            if( dir_x >= 0 && dir_x < row && dir_y >=0 && dir_y < col ){
                if( map[dir_y][dir_x] == 1 && !visited[dir_y][dir_x] ){
                    visited[dir_y][dir_x] = true; 
                    width++;
                    q.push(make_pair(dir_x,dir_y));
                }
            }
        }
    }
    return width ;
}
int main(void){
    scanf("%d %d",&col,&row); 

    for(int i = 0 ; i < col; i++){
        for(int j = 0 ; j <row; j++){
            if( j == row -1 ){
                scanf("%d", &map[i][j]);
            }else{
                scanf("%d ", &map[i][j]);
            }
        }
    }

    for(int i = 0 ;i < MAX; i++)
        for(int j = 0 ; j < MAX ; j++ )
            visited[i][j] = false;

    int max = 0 ;
    int count = 0 ;
    for(int i = 0 ; i  < col; i++){
        for(int j = 0 ;j <row; j++){
            if( map[i][j] == 1 && !visited[i][j]){
                visited[i][j] = true; 
                count++;
                int tmp = BFS(j,i);  // first: count, second: max 
                if( tmp > max ){
                    max = tmp;
                }
            }
            
        }
    }
    printf("%d\n%d\n",count, max);
    return 0;
}