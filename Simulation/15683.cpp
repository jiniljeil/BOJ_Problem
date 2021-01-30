#include <iostream>
#include <vector> 
#include <string.h> 

using namespace std; 
int row, col, N_CCTV;
int result = 1e9;
int map[10][10];
int copy_map[10][10];
vector< pair<pair<int,int> , pair<int,int> > > v ;

void up(int x, int y){
    for(int i = y - 1; i >= 0 ; i--) {
        if(copy_map[i][x] == 6) break;
        if(copy_map[i][x] >= 1 && copy_map[i][x] <= 5) continue; 
        copy_map[i][x] = -1; 
    }
}

void down(int x, int y) {
    for(int i = y + 1; i < row; i++) {
        if(copy_map[i][x] == 6) break;
        if(copy_map[i][x] >= 1 && copy_map[i][x] <= 5) continue; 
        copy_map[i][x] = -1; 
    }
}

void left(int x, int y) {
    for(int i = x - 1; i >= 0 ; i--) {
        if(copy_map[y][i] == 6) break;
        if(copy_map[y][i] >= 1 && copy_map[y][i] <= 5) continue; 
        copy_map[y][i] = -1; 
    }
}

void right(int x, int y) {
    for(int i = x + 1; i < col ; i++) {
        if(copy_map[y][i] == 6) break;
        if(copy_map[y][i] >= 1 && copy_map[y][i] <= 5) continue; 
        copy_map[y][i] = -1; 
    }
}

void Setting_CCTV(){

    // Copy 
    for(int i = 0; i < row ; i++) {
        for(int j = 0 ;j < col; j++) {
            copy_map[i][j] = map[i][j]; 
        }
    }
    // 0: 오른쪽, 1: 왼쪽, 2: 위, 3: 아래
    for(int i = 0; i < v.size(); i++) {
        if(v[i].second.first == 1) {
            if(v[i].second.second == 0) right(v[i].first.first, v[i].first.second) ;
            else if(v[i].second.second == 1) left(v[i].first.first, v[i].first.second);
            else if(v[i].second.second == 2) up(v[i].first.first, v[i].first.second);
            else if(v[i].second.second == 3) down(v[i].first.first, v[i].first.second);
        }else if( v[i].second.first == 2) {
            if( v[i].second.second == 0 || v[i].second.second == 1) {
                right(v[i].first.first, v[i].first.second);
                left(v[i].first.first, v[i].first.second);
            }else if( v[i].second.second == 2 || v[i].second.second == 3) {
                up(v[i].first.first, v[i].first.second);
                down(v[i].first.first, v[i].first.second);
            }
        }else if( v[i].second.first == 3) {
            if( v[i].second.second == 0) { 
                right(v[i].first.first, v[i].first.second);
                up(v[i].first.first, v[i].first.second);
            }else if(v[i].second.second == 1) {
                left(v[i].first.first, v[i].first.second);
                up(v[i].first.first, v[i].first.second);
            }else if(v[i].second.second == 2) {
                left(v[i].first.first, v[i].first.second);
                down(v[i].first.first, v[i].first.second);
            }else if(v[i].second.second == 3) {
                down(v[i].first.first, v[i].first.second);
                right(v[i].first.first, v[i].first.second);
            }
        }else if( v[i].second.first == 4) {
            if( v[i].second.second == 0) {
                right(v[i].first.first, v[i].first.second);
                up(v[i].first.first, v[i].first.second);
                left(v[i].first.first, v[i].first.second);
            }else if(v[i].second.second == 1){
                up(v[i].first.first, v[i].first.second);
                left(v[i].first.first, v[i].first.second);
                down(v[i].first.first, v[i].first.second);
            }else if(v[i].second.second == 2){
                left(v[i].first.first, v[i].first.second);
                down(v[i].first.first, v[i].first.second);
                right(v[i].first.first, v[i].first.second);
            }else if(v[i].second.second == 3){
                down(v[i].first.first, v[i].first.second);
                right(v[i].first.first, v[i].first.second);
                up(v[i].first.first, v[i].first.second);
            }
        }else if( v[i].second.first == 5) {
            right(v[i].first.first, v[i].first.second);
            left(v[i].first.first, v[i].first.second);
            up(v[i].first.first, v[i].first.second);
            down(v[i].first.first, v[i].first.second);
        }
    }
}

int Num_of_Area() { 
    int c = 0 ; 
    for(int i = 0 ; i < row; i++) {
        for(int j = 0 ; j <col; j++) {
            if( copy_map[i][j] == 0 ) c++; 
        }
    }

    return c; 
}
void Direction_of_the_CCTV(int cnt) {
    if( cnt == N_CCTV) {
        Setting_CCTV();
        int num = Num_of_Area(); 
        result = (result > num )? num : result ;
        return ;
    }
    v[cnt].second.second = 0 ; 
    Direction_of_the_CCTV(cnt + 1);
    v[cnt].second.second = 1 ; 
    Direction_of_the_CCTV(cnt + 1);
    v[cnt].second.second = 2 ; 
    Direction_of_the_CCTV(cnt + 1);
    v[cnt].second.second = 3 ;
    Direction_of_the_CCTV(cnt + 1);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> row >> col; 

    for(int i = 0 ; i < row; i++ ){
        for(int j = 0 ;j < col; j++) {
            cin >> map[i][j] ; 
            if(map[i][j] >= 1 && map[i][j] <= 5) { 
                // x, y, cctv_num, direction
                v.push_back(make_pair(make_pair(j,i),make_pair(map[i][j], -1)));
            }
        }
    }

    N_CCTV = v.size();

    Direction_of_the_CCTV(0);

    cout << result << '\n';
    return 0;
}