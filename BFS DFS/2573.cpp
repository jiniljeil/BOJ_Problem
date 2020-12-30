#include <iostream>
#include <queue> 
#include <string.h> 
using namespace std;
int dx[4] = {-1, 0, 1, 0 }; 
int dy[4] = {0, 1, 0, -1} ;

int map[301][301] ; 
int copy_map[301][301] ; 
int visited[301][301] ;
int row, col; 
int year ; 
queue< pair<int,int> > queue_pair; 

bool check(int x, int y){
    if( x >= 0 && y >= 0 && x < row && y < col){
        return true; 
    }else{
        return false; 
    }
}

void BFS(int x, int y){
    queue< pair<int, int> > q ; 
    q.push(make_pair(x,y));
    visited[x][y] = 1; 
    while(!q.empty()){
        int curr_x = q.front().first; 
        int curr_y = q.front().second; 
        q.pop(); 
        for(int k = 0 ; k < 4 ; k++){
            int dir_x = curr_x + dx[k]; 
            int dir_y = curr_y + dy[k]; 
            
            if( check(dir_x,dir_y) && visited[dir_x][dir_y] == 0 && map[dir_x][dir_y] != 0 ){
                visited[dir_x][dir_y] = 1; 
                q.push(make_pair(dir_x,dir_y)); 
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    cin >> row >> col ; 
    for(int i = 0 ; i < row; i++){
        for(int j = 0 ; j < col; j++){
            cin >> map[i][j] ; 
            copy_map[i][j] = map[i][j]; 
        }
    }

    while(true){
        year++; 

        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col; j++){
                int count = 0 ; 
                for(int k = 0 ; k < 4; k++){ 
                    int dir_x = i + dx[k]; 
                    int dir_y = j + dy[k];

                    if(check(dir_x,dir_y) && map[dir_x][dir_y] == 0){
                        count++; 
                    }
                }
                if( count != 0 ) queue_pair.push(make_pair(i,j));
            }
        }

        int size = queue_pair.size(); 
        while(size--){
            int curr_x = queue_pair.front().first; 
            int curr_y = queue_pair.front().second; 
            queue_pair.pop(); 
            
            int count = 0 ; 
            for(int k = 0 ; k < 4; k++){
                int dir_x = curr_x + dx[k];
                int dir_y = curr_y + dy[k];

                if( check(dir_x,dir_y) && map[dir_x][dir_y] == 0 ){
                    count++; 
                }
            }
            copy_map[curr_x][curr_y] -= count; 
            if(copy_map[curr_x][curr_y] < 0 ) copy_map[curr_x][curr_y] = 0;
        }

        //copy 
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col; j++){
                map[i][j] = copy_map[i][j]; 
            }
        }   
        
        int map_count = 0 ; 
        memset(visited, 0 , sizeof(visited)); 
        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col; j++){
                if( map[i][j] != 0 && visited[i][j] == 0){
                    BFS(i, j);
                    map_count++;
                }
            }
        }

        if( map_count >= 2) {
            cout << year << endl ; 
            break ;
        }else if(map_count == 0 ){
            cout << "0\n" << endl ; 
            break; 
        } 
    }
    return 0;
}