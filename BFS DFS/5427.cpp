#include <iostream>
#include <queue>

using namespace std;

int dist[1001][1001];
int fire[1001][1001];
string map[1001];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int main(void) {
    int n ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n ;
    
    for(int r = 0; r < n ;r++){
        int row, col;
        bool check = false;
        cin >> col >> row ;
        
        //initialization
        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col; j++){
                fire[i][j] = -1;
                dist[i][j] = -1;
            }
            map[i].clear();
        }
        queue<pair<int, int>> fire_q;
        queue<pair<int, int>> dist_q;
        //input
        for(int i = 0 ; i < row; i++){
            cin >> map[i];
            for(int j = 0 ; j < map[i].length(); j++){
                if(map[i][j] == '*'){
                    fire[i][j] = 0 ;
                    fire_q.push({j,i});
                }
                if(map[i][j] == '@'){
                    dist[i][j] = 0;
                    dist_q.push({j,i});
                }
            }
        }
        
        while(!fire_q.empty()){
            int curr_x = fire_q.front().first;
            int curr_y = fire_q.front().second;
            
            fire_q.pop();
            
            for(int k = 0 ; k < 4; k++){
                int dir_x = curr_x + dx[k];
                int dir_y = curr_y + dy[k];
                
                if( dir_x < 0 || dir_x >= col || dir_y < 0 || dir_y >= row ) continue;
                if( fire[dir_y][dir_x] >= 0 || map[dir_y][dir_x] == '#') continue;
                fire[dir_y][dir_x] = fire[curr_y][curr_x] + 1;
                fire_q.push({dir_x,dir_y});
            }
        }
        
        while(!dist_q.empty()){
            int curr_x = dist_q.front().first;
            int curr_y = dist_q.front().second;
            
            dist_q.pop();
            
            for(int k = 0 ; k < 4; k++){
                int dir_x = curr_x + dx[k];
                int dir_y = curr_y + dy[k];
                
                if( (dir_x < 0 || dir_x >= col || dir_y < 0 || dir_y >= row) && dist[dir_y][dir_x] != '#'){
                    cout << dist[curr_y][curr_x] + 1 << "\n";
                    check = true ;
                    break;
                }
                if( dist[dir_y][dir_x] >= 0 || map[dir_y][dir_x] == '#') continue;
                if( fire[dir_y][dir_x] != -1 && fire[dir_y][dir_x] <= dist[curr_y][curr_x] +1) continue;
                dist[dir_y][dir_x] = dist[curr_y][curr_x] + 1;
                dist_q.push({dir_x,dir_y});
            }
            if( check ) break;
        }
        if(!check) cout << "IMPOSSIBLE" << "\n";
    }
    return 0;
}
