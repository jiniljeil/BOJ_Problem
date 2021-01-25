#include <iostream>

using namespace std;

int N; 
pair<int,int> egg[10];
int result = 0 ;
void func(int k){
    if( k == N ) { 
        int c = 0 ; 
        for(int i = 0 ; i < N; i++) {
            if( egg[i].first <= 0) c++;
        }
        result = (c > result) ? c : result; 
        return ;
    }
    if( egg[k].first <= 0) func(k+1); 
    else{
        bool hit_check = false; 
        for(int i = 0 ; i < N; i++) {
            if(k != i && egg[i].first > 0){ 
                egg[i].first -= egg[k].second ;
                egg[k].first -= egg[i].second ; 
                func(k+1);
                hit_check = true; 
                egg[i].first += egg[k].second ;
                egg[k].first += egg[i].second ; 
            }
        }
        if(!hit_check) func(N); // 현재 계란을 제외한 나머지들이 이미 깨진 상태 
    }
}

int main(void){ 
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> N; 
    for(int i = 0 ; i < N; i++) {
        cin >> egg[i].first >> egg[i].second; 
    }
    func(0);
    cout << result << '\n';
    return 0;
}