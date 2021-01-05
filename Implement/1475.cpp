#include <iostream>

using namespace std;

int N;
int cnt[9]; 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num;
    cin >> num;

    for(int i = 0 ; i < num.length(); i++){
        if( num[i] == '9'){
            cnt[6]++;
        }else{
            cnt[num[i] - '0']++;
        }
    }
    if( cnt[6] % 2 == 0 ){
        cnt[6] /= 2 ;
    }else{
        cnt[6] = cnt[6]/2 + 1;
    }
    int max_r = 0 ; 

    for(int i = 0 ; i < 9; i++){
        if( max_r < cnt[i]) {
            max_r = cnt[i] ;
        }
    }

    cout << max_r << "\n";

    return 0;
}