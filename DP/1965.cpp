#include <iostream> 

using namespace std ;
int N ; 
int arr[1010] ; 
int dp[1010]; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0); 
    cin >> N ; 
    for (int i = 1 ; i <= N ; i++) { 
        cin >> arr[i] ; 
        dp[i] = 1; 
    }

    for (int i = 1 ; i <= N ; i++) {
        for (int j = i + 1 ; j <= N ; j++) { 
            if ( arr[i] < arr[j] ) { 
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }

    int m = 0 ; 
    for (int i = 1 ; i <= N ; i++) { 
        if ( m < dp[i] ) m = dp[i] ; 
    }
    cout << m << '\n'; 
    return 0 ;
}