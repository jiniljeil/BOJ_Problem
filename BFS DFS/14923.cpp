#include <iostream>
#include <queue> 
#define MAX 1001
using namespace std ;

int map[MAX][MAX] ; 
int value[MAX][MAX][2]; 
int N, M; 
int user_x,user_y, end_x, end_y; 
int dx[4] = {-1, 0, 1, 0} ; 
int dy[4] = {0, 1, 0, -1}; 
void BFS() { 
    queue< pair<pair<int,int>, int> >q; 
    q.push(make_pair(make_pair(user_x, user_y), 1));
    
    while(!q.empty()) {
        int curr_x = q.front().first.first ;
        int curr_y = q.front().first.second ;    
        int block = q.front().second ; 
        q.pop(); 

        if( curr_x == end_x && curr_y == end_y ) {
            cout << value[curr_y][curr_x][block] << "\n";
            return ;  
        }

        for(int i = 0 ; i < 4; i++) {
            int dir_x = curr_x + dx[i] ;
            int dir_y = curr_y + dy[i] ; 
            if( dir_x > 0 && dir_x <= M && dir_y > 0 && dir_y <= N) {
                if( map[dir_y][dir_x] == 0 && value[dir_y][dir_x][block] == 0) {
                    value[dir_y][dir_x][block] = value[curr_y][curr_x][block] + 1 ; 
                    q.push(make_pair(make_pair(dir_x,dir_y), block)); 
                } 
                if( map[dir_y][dir_x] == 1 && block) { 
                    value[dir_y][dir_x][block - 1] = value[curr_y][curr_x][block] + 1; 
                    q.push(make_pair(make_pair(dir_x,dir_y), block-1)); 
                }
            }
        }
    }
    cout << "-1\n"; 
    return ;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M ;
    cin >> user_y >> user_x ;
    cin >> end_y >> end_x ; 

    for(int i = 1 ;i <= N; i++) {
        for(int j = 1 ; j <= M; j++){
            cin >> map[i][j] ;
        }
    }

    BFS() ;
    return 0;
}