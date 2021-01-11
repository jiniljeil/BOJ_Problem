#include <iostream>
#include <queue> 

using namespace std; 
int K, R, C; 
int map[201][201]; 
bool visited[201][201][31];
int dx[8] = {-2,-1, 1, 2, 2, 1, -1, -2 } ;
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1} ;
int next_dx[4] = {-1, 0, 1, 0} ;
int next_dy[4] = {0 ,1, 0, -1} ;
queue<pair<pair<int,int>, pair<int, int> > >q; 
int main(void){
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0) ; 
    cin >> K >> C >> R ;

    for(int i = 1 ; i <= R ; i++ ) {
        for(int j = 1 ; j <= C; j++) {
            cin >> map[i][j] ; 
        }
    }

    q.push(make_pair(make_pair(1,1), make_pair(0, 0))) ;
    visited[1][1][0] = true; 
    bool check = false; 
    while(!q.empty()) {
        int curr_x = q.front().first.first ;
        int curr_y = q.front().first.second;
        int jump = q.front().second.first; 
        int result = q.front().second.second; 

        q.pop(); 
        if( curr_x == C && curr_y == R) { 
            check = true; 
            cout << result << "\n";
            break; 
        }
        if( jump < K) {
            for(int i = 0 ; i < 8; i++ ){
                int dir_x = curr_x + dx[i] ;
                int dir_y = curr_y + dy[i] ; 
                if( dir_x <= 0 || dir_x > C || dir_y <= 0 || dir_y > R ) continue; 
                if( map[dir_y][dir_x] == 0 && !visited[dir_y][dir_x][jump + 1]) { 
                    visited[dir_y][dir_x][jump +1] = true; 
                    q.push(make_pair(make_pair(dir_x,dir_y), make_pair(jump + 1, result + 1) ));
                }
            }
        }
        for(int i = 0 ; i < 4; i++){ 
            int dir_x = curr_x + next_dx[i] ;
            int dir_y = curr_y + next_dy[i] ; 
            if( dir_x <= 0 || dir_x > C || dir_y <= 0 || dir_y > R ) continue; 
            if( map[dir_y][dir_x] == 0 && !visited[dir_y][dir_x][jump]) { 
                visited[dir_y][dir_x][jump] = true;
                q.push(make_pair(make_pair(dir_x,dir_y), make_pair(jump, result + 1) ));
            }
        }
    }
    if(!check) cout << "-1" << "\n";
    return 0;
}