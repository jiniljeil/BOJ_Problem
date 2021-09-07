#include <iostream>
#include <queue> 
using namespace std ;

int row, col; 
char map[51][51]; 
int water_map[51][51]; 
int biber_map[51][51]; 
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = { 0, 1, 0, -1}; 
queue<pair<int,int> > water ;
queue<pair<int,int> > biber ; 

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;
    cin >> row >> col; 
    string s ; 
    for (int i = 0 ; i < row ;i++) {
        cin >> s ; 
        for (int j = 0 ; j < col; j++) {
            map[i][j] = s[j]; 
            water_map[i][j] = -1 ; 
            biber_map[i][j] = -1 ;

            if (map[i][j] == '*') {
                water.push(make_pair(j, i)); 
                water_map[i][j] = 0; 
            }
            if (map[i][j] == 'S') {
                biber.push(make_pair(j, i)); 
                biber_map[i][j] = 0; 
            }
        }
    }

    while(!water.empty()) {
        int curr_x = water.front().first; 
        int curr_y = water.front().second; 
        water.pop(); 
        for(int i = 0 ; i < 4; i++) {
            int dir_x = curr_x + dx[i] ;
            int dir_y = curr_y + dy[i] ;

            if( dir_x < 0 || dir_x >= col || dir_y < 0 || dir_y >= row) continue; 
            if( water_map[dir_y][dir_x] != -1 || map[dir_y][dir_x] == 'X' || map[dir_y][dir_x] == 'D') continue; 

            water_map[dir_y][dir_x] = water_map[curr_y][curr_x] + 1; 
            water.push(make_pair(dir_x, dir_y)); 
        }
    }

    while(!biber.empty()) {
        int curr_x = biber.front().first ;
        int curr_y = biber.front().second; 

        biber.pop(); 

        for(int i = 0 ; i < 4; i++) {
            int dir_x = curr_x + dx[i] ;
            int dir_y = curr_y + dy[i] ;

            if( dir_x < 0 || dir_x >= col || dir_y < 0 || dir_y >= row) continue; 

            if( map[dir_y][dir_x] == 'D') {
                cout << biber_map[curr_y][curr_x] + 1 << '\n'; 
                return 0; 
            }

            if( biber_map[dir_y][dir_x] != -1 || (water_map[dir_y][dir_x] != -1 && water_map[dir_y][dir_x] <= biber_map[curr_y][curr_x] + 1)
                || map[dir_y][dir_x] == '*' || map[dir_y][dir_x] == 'X') continue; 
            
            biber_map[dir_y][dir_x] = biber_map[curr_y][curr_x] + 1; 
            biber.push(make_pair(dir_x, dir_y)); 
        }
    }

    cout << "KAKTUS" << '\n'; 
    return 0; 
}