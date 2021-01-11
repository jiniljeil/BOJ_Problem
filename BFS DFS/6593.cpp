#include <iostream>
#include <queue> 
#include <cstring>
using namespace std; 

int L, R, C; 
char map[30][30][30];
int value[30][30][30];
int dx[6] = {1, 0, -1, 0, 0, 0} ;
int dy[6] = {0, 1, 0 ,-1, 0, 0} ; 
int dz[6] = {0, 0, 0 , 0, 1, -1} ;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(1){
        queue<pair<pair<int,int>, int> > q; 
        int result = 0;
        int start_x, start_y, start_z;
        cin >> L >> R >> C ; 
        if( L == 0 && R == 0 && C == 0) break; 

        for(int k = 0 ; k < L; k++) {
            for(int i = 0 ; i < R ;i++ ) {
                for(int j = 0; j < C; j++) {
                    cin >> map[i][j][k] ;
                    if( map[i][j][k] == 'S') {
                        start_x = j ; 
                        start_y = i; 
                        start_z = k; 
                    }
                }
            }
        }
        q.push(make_pair(make_pair(start_x,start_y),start_z)); 
        value[start_y][start_x][start_z] = 0 ;
        bool check = false; 
        while(!q.empty()) {
            int curr_x = q.front().first.first; 
            int curr_y = q.front().first.second; 
            int curr_z = q.front().second; 
            q.pop(); 
            
            if( map[curr_y][curr_x][curr_z] == 'E') {
                cout << "Escaped in " << value[curr_y][curr_x][curr_z] << " minute(s)." << "\n";
                check = true; 
                break; 
            }
            for(int i = 0; i < 6; i++){ 
                int dir_x = curr_x + dx[i] ;
                int dir_y = curr_y + dy[i] ; 
                int dir_z = curr_z + dz[i] ; 
                if( dir_x < 0 || dir_x >= C || dir_y < 0 || dir_y >= R || dir_z < 0 || dir_z >= L) continue;
                if( (map[dir_y][dir_x][dir_z] == '.' || map[dir_y][dir_x][dir_z] == 'E') && value[dir_y][dir_x][dir_z] == 0 ) {
                    value[dir_y][dir_x][dir_z] = value[curr_y][curr_x][curr_z] + 1;
                    q.push(make_pair(make_pair(dir_x, dir_y), dir_z)) ;
                }
            }
        }
        if(!check ) {
            cout << "Trapped!" << "\n";
        }
        memset(value, 0, sizeof(value));
        
    } 
    return 0;
}