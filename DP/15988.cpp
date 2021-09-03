#include <iostream> 

using namespace std; 

int T, N; 
long long dp[1000001]; 
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    dp[1] = 1; // 1
    dp[2] = 2; // 1+1 2
    dp[3] = 4; // 1+2 2+1 1+1+1 3

    for(int i = 4; i <= 1000000; i++) {
        dp[i] += (dp[i-1] % 1000000009);
        dp[i] += (dp[i-2] % 1000000009);  
        dp[i] += (dp[i-3] % 1000000009);
    }
    cin >> T ;

    for(int i = 0 ; i < T ;i++) {
        cin >> N ; 
        cout << (dp[N] % 1000000009) << '\n';
    }
    return 0; 
}