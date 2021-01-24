#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

long long N, R, C;
long long result = 0 ;
int dx[4] = {0,1,0,1};
int dy[4] = {0,0,1,1};
void func(long long x, long long y, long long size) {
    if( size == 2 ) {
        for(int i = 0 ; i < 4; i++){ 
            int dir_x = x + dx[i];
            int dir_y = y + dy[i];
            if( dir_x == C && dir_y == R) {
                cout << result << '\n';
                return;
            }else{
                result++;
            }
        }
        return ;
    }else{
        if(R >= y + size/2 && C >= x + size/2){ 
            result += (3 * (size/2 * size/2));
            func(x + size/2, y + size/2, size/2);
        }else if(R >= y + size/2){
            result += (2 * (size/2 * size/2));
            func(x, y + size/2, size/2);
        }else if(C >= x + size/2){
            result += (size/2 * size/2);
            func(x + size/2, y, size/2);
        }else{
            func(x, y, size/2);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> R >> C;
    func(0,0, pow(2,N));
    return 0;
}