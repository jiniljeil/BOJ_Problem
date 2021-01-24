#include <iostream>

using namespace std; 
int N ; 

void moo(int k) {
    int len = 3; 
    int add = 0; 

    if( k == 1) cout << 'm' << '\n';
    else if( k <= 3) {
        cout << 'o' << '\n';
    }else{
        while( len < k) { 
            len = len * 2 + add + 4; 
            add++;
        }

        int add_str_idx = (len - add -1)/2; // 추가된 문자열 시작 위치
        if( add_str_idx == k) { 
            cout << 'm' << '\n'; return ; 
        }else{
            if( len - add_str_idx <= k) {
                moo( k - (len - add_str_idx) - 1);  // 23 - 14 - 1; 8 
            }else{ 
                cout << 'o' << '\n';
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;

    cin >> N; 
    moo(N);
    return 0;
}