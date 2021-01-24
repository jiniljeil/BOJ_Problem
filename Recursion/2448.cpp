#include <iostream>

using namespace std ;

int N ;
char arr[3072][6143];
// 1024 * 3 = 3072 
// 3072 * 2 - 1 = 6143

void func(int x, int y, int n){ 
    if( n == 3 ) {
        arr[y][x] = '*';
        arr[y+1][x-1] = '*';
        arr[y+1][x+1] = '*';

        for(int i = -2; i <= 2; i++) {
            arr[y+2][x + i] = '*';
        }
        return ;
    }
    func(x, y, n/2);
    func(x - n/2, y + n/2, n/2); 
    func(x + n/2, y + n/2, n/2); 
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    cin >> N; 

    func(N - 1 , 0, N); 

    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < 2 * N - 1; j++) {
            if ( arr[i][j] == '*') cout << '*'; 
            else cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}