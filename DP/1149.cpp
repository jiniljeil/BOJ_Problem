#include <iostream>
#include <vector> 
#include <string.h> 
using namespace std ;

int result = 1e8, n = 0 ; 
int rgb[1000][3]; 
int rgb_dp[1000][3]; 

int min(int a, int b) {
    if( a > b) {
        return b;
    }else{
        return a;
    }
}
int DP(int k, int pre) { 
    if( k == n) return 0; 
    if( rgb_dp[k][pre] != -1) return rgb_dp[k][pre]; 

    int r = 1e8; 
    for(int i = 0; i < 3; i++) {
        if( pre != i) {
            r = min( r, rgb[k][i] + DP(k+1, i));
        }
    }
    rgb_dp[k][pre] = r; 

    return r; 
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    memset(rgb_dp, -1, sizeof(rgb_dp));

    cin >> n; 

    int a,b,c; 
    for(int i = 0 ; i < n; i++) {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2]; 
    }

    result = min(result, rgb[0][0] + DP(1, 0)); 
    result = min(result, rgb[0][1] + DP(1, 1)); 
    result = min(result, rgb[0][2] + DP(1, 2));

    cout << result << '\n';
    return 0 ;
}