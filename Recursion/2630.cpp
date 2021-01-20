#include <iostream>

using namespace std;
int N; 
int map[129][129];
int blue, white; 
void func(int x, int y, int size) { 
    bool check = false; 
    int color = map[y][x];
    for(int i = y ; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            if(map[i][j] != color) {
                check = true ;
                break;
            }
        }
        if(check) break;
    }
    if( check ) { // 다른게 존재 
        func(x, y, size/2); // 왼 위 0 0 4 4
        func(x + size/2, y, size/2); // 오 위 4 0 8 4
        func(x, y + size/2, size/2); // 왼 아래 0 4 4 8
        func(x + size/2, y + size/2, size/2); // 오 아래 
    }else{ // 다른게 존재 X
        if(color == 0) {
            white++;
        }
        if(color == 1) {
            blue++;
        }
    }
     
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N; 
    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < N; j++) {
            cin >> map[i][j]; 
        }
    }

    func(0, 0, N);

    cout << white << '\n' << blue << '\n';

    return 0 ;
}