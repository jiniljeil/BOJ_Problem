#include <iostream>
#include <queue> 
#include <vector> 
#include <cstring> 
#define MAX 1e7 
using namespace std;

int map[103][103];
bool visited[103][103];  
int N; 
int dx[4] = {-1, 0 , 1, 0}; 
int dy[4] = { 0, 1 , 0, -1}; 
int label = 1, short_path = MAX ;

void island_label() {
     for(int i = 0 ; i < N ; i++){
         for(int j = 0 ; j < N ; j++) {
             if(!visited[i][j] && map[i][j] == -1){ 
                queue< pair<int, int> > Q ; 
                Q.push(make_pair(j,i)); 
                visited[i][j] = true; 
                map[i][j] = label ;

                while(!Q.empty()){ 
                    int curr_x = Q.front().first; 
                    int curr_y = Q.front().second ; 
                    Q.pop(); 

                    for(int k = 0 ; k < 4; k++){
                        int dir_x = curr_x + dx[k]; 
                        int dir_y = curr_y + dy[k]; 
                        if( dir_x >= 0 && dir_x < N && dir_y >= 0 && dir_y < N){ 
                            if( !visited[dir_y][dir_x] && map[dir_y][dir_x] == -1) { 
                                visited[dir_y][dir_x] = true; 
                                map[dir_y][dir_x] = label ;
                                Q.push(make_pair(dir_x, dir_y)); 
                            }
                        }
                    }
                }
                label++; 
             }
         }
     }
}
int BFS(int start) {
    int c = 0 ; 
    queue< pair<int,int> > q ; 
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){ 
            if( map[i][j] == start){
                q.push(make_pair(j, i)) ;
                visited[i][j] = true ; 
            } 
        }
    }
    
    while(!q.empty()){
        int size = q.size(); 
        for(int i = 0 ; i < size; i++) {
            int curr_x = q.front().first ; 
            int curr_y = q.front().second ; 
            q.pop(); 

            for(int k = 0 ; k < 4; k++) {
                int dir_x = curr_x + dx[k]; 
                int dir_y = curr_y + dy[k];
                if( dir_x >= 0 && dir_x < N && dir_y >= 0 && dir_y < N ) { 
                    if(map[dir_y][dir_x] != 0 && map[dir_y][dir_x] != start) return c; 
                    else if(map[dir_y][dir_x] == 0 && !visited[dir_y][dir_x]) {
                        visited[dir_y][dir_x] = true ;
                        q.push(make_pair(dir_x,dir_y));
                    }
                }
            }
        }
        c++; 
    }
}
int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> N ; 
    for(int i= 0 ; i < N; i++) {
        for(int j = 0 ;j < N; j++) {
            cin >> map[i][j]; 
            if(map[i][j] == 1) {
                map[i][j] = -1; 
            }
        }
    }
    island_label(); 

    for(int i = 1 ; i < label; i++) {
        short_path = min(short_path, BFS(i)); 
        memset(visited, false, sizeof(visited)); 
    }
    
    cout << short_path << "\n";
    return 0 ;
}