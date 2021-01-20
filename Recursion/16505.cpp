#include <iostream>
#include <math.h>
using namespace std;

int N;
char map[1029][1029];
void func(int x, int y, int size) {
    map[y][x] = '*';
    if( size == 0 ) return ;
    func(x + size/2, y, size/2);
    func(x, y + size/2, size/2);
    func(x, y, size/2);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N; 
    
    for(int i = 0 ; i < pow(2,N); i++) {
        for(int j = 0 ; j < pow(2,N); j++) {
            map[i][j] = ' ';
        }
    }

    func(0,0,pow(2,N));
    for(int i = 0; i < pow(2,N); i++) {
        for(int j = 0 ; j < pow(2,N) - i; j++) {
            cout << map[i][j];
        }
        if( pow(2,N) - 1 != i) cout << '\n';
    }
    return 0;
}