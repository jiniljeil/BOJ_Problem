#include <iostream>

using namespace std;
bool ldiagonal[10 * 2]; 
bool rdiagonal[10 * 2]; 
int N ; 
int map[10][10];
int n_bishop_black, n_bishop_white; 
void bishop(int c, int curr_x, int curr_y, int color) {
    if ( curr_x >= N){ 
        curr_y++;
        if(curr_x % 2 == 0 ) curr_x = 1 ; 
        else curr_x = 0;
    }
    if( curr_y >= N) { 
        if( color == 1 ) {
            if( c > n_bishop_white){
                n_bishop_white = c; 
            }
        }else{
            if( c > n_bishop_black) {
                n_bishop_black = c; 
            }
        }
        return ;
    }

    if( map[curr_y][curr_x] && !rdiagonal[curr_x + curr_y + 1] && !ldiagonal[curr_x - curr_y + N]) {
        rdiagonal[curr_x + curr_y + 1] = true; 
        ldiagonal[curr_x - curr_y + N] = true; 
        bishop(c+1, curr_x + 2, curr_y, color) ; // 검은색과 흰색 따로 따로 
        rdiagonal[curr_x + curr_y + 1] = false; 
        ldiagonal[curr_x - curr_y + N] = false; 
    }
    bishop(c, curr_x + 2, curr_y, color);
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> N ; 
    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < N; j++) {
            cin >> map[i][j];
        }
    }
    bishop(0, 0, 0, 0);
    bishop(0, 1, 0, 1); 
    cout << n_bishop_black + n_bishop_white << '\n';
    return 0 ;
}