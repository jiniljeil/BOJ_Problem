#include <iostream>

using namespace std ;

int N ; 
int arr[1001]; 
int dp[1001];
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> N; 

    for(int i = 0 ; i < N ;i++) {
        cin >> arr[i]; 
    }

    int result = 1; 
    for(int i = 0 ; i < N ; i++) {
        dp[i] = 1;
        for(int j = i - 1; j >= 0 ; j--) { 
            if( arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1); 
            }
            result = max(dp[i], result);
        }
    }

    cout << result << '\n';
    return 0; 
}