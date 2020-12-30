#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int dp[100001];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n ;
    
    for(int i = 1 ; i <= n; i++){
        cin >> arr[i] ;
    }
    dp[1] = arr[1];
    int max_result = -1000 ;
    
    for(int i = 2 ; i <= n; i++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
    }
    for(int i = 1 ; i <= n ; i++){
        if( dp[i] > max_result ){
            max_result = dp[i] ;
        }
    }
    cout << max_result << endl;
    return 0;
}
