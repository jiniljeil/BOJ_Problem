#include <iostream>
#include <deque> 

using namespace std; 

int N, appleNum, m, time_r, c, curr_dir;
int x = 1, y = 1; 
char dir; 

int map[101][101]; // 1: 뱀, 2: 사과 
deque< pair<int,char> > V_DIR; 
deque< pair<int,int> > baem; 
// 동 남 서 북
int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1}; 

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0) ;

    map[1][1] = 1; // 뱀의 몸통: 1

    // INPUT 
    cin >> N >> appleNum; 
    int a, b;
    for(int i = 0 ; i < appleNum; i++) {
        cin >> a >> b ;
        map[a][b] = 2;  // 사과 
    }
    
    cin >> m ; 
    
    for(int i = 0; i < m; i++) {
        cin >> c >> dir ; 
        V_DIR.push_back(make_pair(c, dir));
    }
    
    baem.push_back(make_pair(y,x));

    pair<int,char> move_dir = V_DIR.front();

    while(true) {
        // cout << "TIME: " << time_r << '\n';
        // for(int i = 1 ; i <= N; i++) {
        //     for(int j = 1 ; j <= N; j++) {
        //         cout << map[i][j] << ' ' ; 
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        time_r++; 

        int dir_x = x + dx[curr_dir]; 
        int dir_y = y + dy[curr_dir];

        if((dir_x < 1 || dir_x > N || dir_y < 1 || dir_y > N) || map[dir_y][dir_x] == 1) break; // 범위 벗어난 경우 || 자기 몸통인 경우 

        if(map[dir_y][dir_x] == 0) { // 이동할 때 
            baem.push_front(make_pair(dir_y,dir_x)) ;
            map[dir_y][dir_x] = 1; 
            map[baem.back().first][baem.back().second] = 0; 
            baem.pop_back();
        }else if(map[dir_y][dir_x] == 2) { // 사과 먹을 때 
            map[dir_y][dir_x] = 1; 
            baem.push_front(make_pair(dir_y,dir_x));
        }

        if(V_DIR.size() > 0 ) {
            if( time_r == move_dir.first ) {
                if( move_dir.second == 'L') {
                    if(curr_dir == 0) curr_dir = 3 ; // 동 -> 북
                    else if(curr_dir == 1) curr_dir = 0; // 남 -> 동
                    else if(curr_dir == 2) curr_dir = 1; // 서 -> 남
                    else if(curr_dir == 3) curr_dir = 2; // 북 -> 서
                }
                if( move_dir.second == 'D') {
                    if(curr_dir == 0) curr_dir = 1; // 동 -> 남 
                    else if(curr_dir == 1) curr_dir = 2; // 남 -> 서 
                    else if(curr_dir == 2) curr_dir = 3; // 서 -> 북 
                    else if(curr_dir == 3) curr_dir = 0; // 북 -> 동 
                }
                V_DIR.pop_front();
                move_dir = V_DIR.front();
            }
        }

        x = dir_x; 
        y = dir_y;
    }
    cout << time_r << '\n';
    return 0;
}