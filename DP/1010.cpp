#include <iostream> 
#include <cstring> 
using namespace std; 

int DP[31][31]; 
int N; 

int func(int n, int r){ // nCr
    if( n == r || r == 0) return 1 ;
    if( DP[n][r] != 0) return DP[n][r]; 
    return DP[n][r] = func(n-1,r) + func(n-1,r-1);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    cin >> N; 

    for(int i = 0 ; i < N; i++){
        int a, b; 
        cin >> a >> b ; 
        cout << func(b,a) << "\n"; // 오른쪽에서 왼쪽 선택 
        
        memset(DP, 0, sizeof(DP));
    }
    return 0;
}