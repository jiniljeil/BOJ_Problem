#include <iostream> 
#include <queue> 
#include <cstring>
#define MAX 1501
using namespace std; 

int R, C ; 
char map[MAX][MAX]; 
bool visited[MAX][MAX];
bool water_visited[MAX][MAX];
queue<pair<int,int> > water_q; 
queue<pair<int,int> > Q; 
int dx[4] = {-1, 0 ,1, 0}; 
int dy[4] = {0, 1, 0, -1};
int day = 0 ;

bool BFS(pair<int,int> start_pair, pair<int,int> end_pair) {
    bool isFind = false; 
    while(!Q.empty()) {
        int curr_x = Q.front().first ;
        int curr_y = Q.front().second ;
        Q.pop() ;
        
        if(curr_x == end_pair.first && curr_y == end_pair.second) { 
            isFind = true; 
            break; 
        }
        for(int i = 0 ; i < 4; i++ ){
            int dir_x = curr_x + dx[i]; 
            int dir_y = curr_y + dy[i]; 
            if( dir_x < 0 || dir_x >= C || dir_y < 0 || dir_y >= R ) continue ;
            if( map[dir_y][dir_x] != 'X' && !visited[dir_y][dir_x]) {
                visited[dir_y][dir_x] = true ;
                Q.push(make_pair(dir_x, dir_y));
            }
            if( map[dir_y][dir_x] == 'X') {
                visited[dir_y][dir_x] = true; 
            }
        }
    }
    return isFind; 
}

int main(void){
    ios::sync_with_stdio(false) ;
    cin.tie(0); cout.tie(0);
    pair<int,int> start_pair, end_pair; 

    bool start_c = false; 
    cin >> R >> C; 
    for(int i = 0; i < R; i++) {
        for(int j = 0 ; j < C ; j++) {
            cin >> map[i][j] ; 
            if( !start_c && map[i][j] == 'L') {
                start_pair.first = j;  
                start_pair.second = i; 
                start_c = true; 
                Q.push(make_pair(j, i)) ; // 백조 시작점
                visited[i][j] = true; 
            }
            if( start_c && map[i][j] == 'L') {
                end_pair.first = j ; 
                end_pair.second = i ; 
            }
            if( map[i][j] != 'X') {
                water_q.push(make_pair(j, i));
                water_visited[i][j] = true; 
            }
        }
    }
    while(true) { 
        if( BFS(start_pair, end_pair) ) {
            cout << day <<"\n";
            break; 
        }
        int size = water_q.size(); 
        while(size--) {
            int curr_x = water_q.front().first ;
            int curr_y = water_q.front().second; 
            water_q.pop(); 

            for(int i = 0 ; i < 4; i++) {
                int dir_x = curr_x + dx[i]; 
                int dir_y = curr_y + dy[i];
                if( dir_x < 0 || dir_x >= C || dir_y < 0 || dir_y >= R ) continue ;
                if(map[dir_y][dir_x] == 'X' && !water_visited[dir_y][dir_x]) {
                    map[dir_y][dir_x] = '.'; 
                    water_visited[dir_y][dir_x] = true; 
                    water_q.push(make_pair(dir_x,dir_y));
                    if( visited[dir_y][dir_x] )Q.push(make_pair(dir_x,dir_y)); 
                }
            }
        }
        day++;
    }
    return 0;
}