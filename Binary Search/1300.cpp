#include <iostream>
#include <algorithm>
using namespace std; 

int N, K ; 
int Start, Mid, End ; 
int cnt ; // 특정 원소보다 작은 원소의 갯수 세기 위함. 
int Result ; 
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> N >> K ;

    Start = 1; 
    End = K ; 

    while (Start <= End) {
        cnt = 0 ;
        Mid = (Start + End) / 2 ; 

        for (int i = 1 ; i <= N ; i++) cnt += min(Mid / i, N); 

        if ( cnt < K ) {
            Start = Mid + 1;  
        }else {
            Result = Mid ; 
            End = Mid - 1 ; 
        }
    }
    cout << Result << '\n';
    return 0 ;
}