#include <iostream>
#include <string.h> 

using namespace std; 

int triangle[501][501]; 
int dp[501][501]; 
int n; 

int max_value(int y, int x) {
    if (y < 0 || x < 0 ) return 0; 
    if (y == n - 1) return triangle[y][x];  
    int &ret = dp[y][x];
    if (ret != -1) return ret; 
    ret = 0; 
    return ret = max(max_value(y+1, x), max_value(y+1, x+1)) + triangle[y][x]; 
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> n ;

    for(int i = 0; i < n; i++) {
        for(int j = i ; j >= 0 ; j--) {
            cin >> triangle[i][j]; 
        }
    }
    memset(dp, -1, sizeof(dp)); 
    int result = max_value(0, 0); 
    cout << result << '\n'; 
    return 0; 
}