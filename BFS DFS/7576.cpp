#include <iostream>
#include <queue>

using namespace std;

int arr[1001][1001];
int dist[1001][1001];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int main(void) {
    int row, column;
    queue<pair<int,int>> queue;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> column >> row;
    
    for(int i = 0 ; i < row ; i++){
        for(int j= 0 ; j< column; j++){
            cin >> arr[i][j] ;
            if(arr[i][j] == 1){
                queue.push({j,i});
            }
            if(arr[i][j] == 0){
                dist[i][j] = -1;
            }
        }
    }
  
    while(!queue.empty()){
        int curr_x = queue.front().first;
        int curr_y = queue.front().second;
        
        queue.pop();
        
        for(int k = 0 ; k < 4; k++){
            int dir_x = curr_x + dx[k];
            int dir_y = curr_y + dy[k];
            
            if( (dir_x >= 0 && dir_x < column) && (dir_y >= 0 && dir_y < row)){
                if( dist[dir_y][dir_x] == -1){
                    dist[dir_y][dir_x] = dist[curr_y][curr_x] + 1;
                    queue.push({dir_x,dir_y});
                }
            }
        }
    }
    
    int result = 0 ;
    for(int i = 0 ; i < row; i++){
        for(int j = 0 ; j < column; j++){
            if( dist[i][j] == -1 ){
                cout << "-1" << "\n";
                return 0;
            }else{
                result = max(result, dist[i][j]);
            }
        }
    }
    
    cout << result << "\n";
    return 0;
}
