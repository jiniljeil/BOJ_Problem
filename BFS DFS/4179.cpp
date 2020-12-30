#include <iostream>
#include <queue>

using namespace std;

int fire[1001][1001];
int dist[1001][1001];
string map[1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
    int row, col;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> row >> col ;
    
    for(int i = 0 ; i < row ;i++){
        cin >> map[i];
    }
    
    queue<pair<int,int>> queue1 ;
    queue<pair<int,int>> queue2 ;
    
    for(int i = 0 ; i < row; i++){
        for(int j = 0; j < col; j++){
            fire[i][j] = -1; dist[i][j] = -1;
            
            if( map[i][j] == 'F'){
                fire[i][j] = 0;
                queue1.push({j,i});
            }
            if( map[i][j] == 'J'){
                dist[i][j] = 0 ;
                queue2.push({j,i});
            }
        }
    }
    while(!queue1.empty()){
        int curr_x = queue1.front().first;
        int curr_y = queue1.front().second;
        
        queue1.pop();
        for(int k = 0 ; k < 4 ; k++){
            int dir_x = curr_x + dx[k];
            int dir_y = curr_y + dy[k];
            
            if(!(dir_x >= 0 && dir_x < col && dir_y >= 0 && dir_y < row)) continue;
            if(fire[dir_y][dir_x] >= 0 || map[dir_y][dir_x] == '#') continue;
            fire[dir_y][dir_x] = fire[curr_y][curr_x] + 1;
            queue1.push({dir_x,dir_y});
        }
    }
    
    while(!queue2.empty()){
        int curr_x = queue2.front().first;
        int curr_y = queue2.front().second;
        queue2.pop();
        
//        cout << curr_y << " " << curr_x << endl;
        
        for(int k = 0 ; k < 4 ; k++){
            int dir_x = curr_x + dx[k];
            int dir_y = curr_y + dy[k];
            
            if(!(dir_x >= 0 && dir_x < col && dir_y >= 0 && dir_y < row)){
                cout << dist[curr_y][curr_x]+1 << "\n";
                return 0;
            }
            
            if(dist[dir_y][dir_x] >= 0 || map[dir_y][dir_x] == '#') continue;
            if(fire[dir_y][dir_x] != -1 && fire[dir_y][dir_x] <= dist[curr_y][curr_x] + 1 ) continue;
            dist[dir_y][dir_x] = dist[curr_y][curr_x] + 1;
            queue2.push({dir_x,dir_y});
        }
    }
  
    cout << "IMPOSSIBLE" << "\n";
    return 0;
}
