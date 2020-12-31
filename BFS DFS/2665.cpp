#include <iostream> 
#include <queue> 

using namespace std;

int map[51][51] ;
int visited[51][51] ;

int dx[4] = { -1 , 0 , 1, 0}; 
int dy[4] = { 0 ,1 , 0, -1 }; 
void BFS(int size){
    for(int i = 0 ; i < size; i++ )
        for(int j = 0 ; j < size; j++)
            visited[i][j] = 1e7 ;

    queue< pair<int, int> > q; 
    q.push(make_pair(0,0));
    visited[0][0] = 0; 

    while(!q.empty()){
        int curr_x = q.front().first;
        int curr_y = q.front().second;

        q.pop() ;
        
        for(int i = 0 ; i < 4 ;i++){
            int dir_x = curr_x + dx[i]; 
            int dir_y = curr_y + dy[i]; 

            if( dir_x >= 0 && dir_x < size && dir_y >= 0 && dir_y < size ){
                if( map[dir_y][dir_x] == 1 ){
                    if( visited[dir_y][dir_x] > visited[curr_y][curr_x] ){
                        visited[dir_y][dir_x] = visited[curr_y][curr_x] ;
                        q.push(make_pair(dir_x, dir_y));
                    }
                }else{
                    if ( visited[dir_y][dir_x] > visited[curr_y][curr_x] + 1){
                        visited[dir_y][dir_x] = visited[curr_y][curr_x] + 1; 
                        q.push(make_pair(dir_x,dir_y));
                    }
                }
            }
        }
    }

    printf("%d\n", visited[size-1][size-1]); 
}

int main(void){
    int n; 
    scanf("%d",&n);

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++) {
            scanf("%1d",&map[i][j]);
        }   
    }

    BFS(n); 
    return 0 ;
}