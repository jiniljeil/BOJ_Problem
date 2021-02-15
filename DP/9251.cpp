#include <iostream>
#include <string> 

using namespace std; 
string a ,b; 
int dp[1001][1001];
int main(void){ 
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;

    cin >> a >> b; 
    int lenA = a.length(), lenB = b.length(); 
    int result = 0 ; 

    for(int i = 1 ; i <= lenA; i++) {
        for(int j = 1 ; j <= lenB; j++) {
            if( a[i-1] == b[j-1]) { 
                dp[i][j] = dp[i-1][j-1] + 1; 
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // LCS 중에 긴 것 선택 
            }
        }
    }

    cout << dp[lenA][lenB] << '\n';
    return 0;
}