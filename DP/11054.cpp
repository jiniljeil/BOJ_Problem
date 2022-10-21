#include <iostream> 

using namespace std ;
int dp[1010]; 
int arr[1010] ; 
int N ; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N ; 

    for (int i = 1 ; i <= N ; i++) { 
        cin >> arr[i] ; 
        dp[i] = 1 ;  
    }

    for (int i = 1; i <= N ; i++) { 
        for (int j = i + 1 ; j <= N ; j++) { 
            if ( arr[i] < arr[j] ) { 
                dp[j] = max(dp[j], dp[i] + 1) ; 
            } 
        }
    }

    for (int i = 1; i <= N ; i++) { 
        for (int j = i + 1 ; j <= N ; j++) { 
            if ( arr[i] > arr[j] ) { 
                dp[j] = max(dp[j], dp[i] + 1) ; 
            } 
        }
    }

    int t = 0 ;
    for (int i = 1;  i <= N; i++) { 
        if ( t < dp[i] ) t = dp[i] ; 
    }

    cout << t << '\n'; 
    return 0 ; 
}