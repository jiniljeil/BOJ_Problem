#include <iostream> 
#include <string.h> 
#include <limits.h> 

using namespace std ; 

int N ; 
int arr[3] ; 
int max_dp[2][3], min_dp[2][3];  
int max_result = 0 ; 
int min_result = INT_MAX; 

int dx[3] = { -1, 0, 1} ; 

void DP() { 
    for (int i = 0 ; i < N - 1; i++) { 
        for (int j = 0 ; j < 3; j++) { 
            cin >> arr[j] ; 
        }       

        // left 
        max_dp[1][0] = arr[0] + max(max_dp[0][0], max_dp[0][1]) ; 
        min_dp[1][0] = arr[0] + min(min_dp[0][0], min_dp[0][1]) ; 

        int t_max = max(max_dp[0][0], max_dp[0][1]) ; 
        int t_min = min(min_dp[0][0], min_dp[0][1]) ; 

        max_dp[1][1] = arr[1] + max(t_max, max_dp[0][2]) ; 
        min_dp[1][1] = arr[1] + min(t_min, min_dp[0][2]) ; 

        max_dp[1][2] = arr[2] + max(max_dp[0][1], max_dp[0][2]) ; 
        min_dp[1][2] = arr[2] + min(min_dp[0][1], min_dp[0][2]) ; 

        for (int j = 0 ; j < 3; j++) {
            max_dp[0][j] = max_dp[1][j] ; 
            min_dp[0][j] = min_dp[1][j] ; 
        }
    }

    for (int i = 0 ; i < 3; i++) { 
        max_result = max(max_result, max_dp[1][i]) ; 
        min_result = min(min_result, min_dp[1][i]) ; 
    }
}

void Input() { 
    cin >> N ; 

    for (int i = 0 ; i < 3; i++) {
        cin >> arr[i] ; 
        max_dp[0][i] = min_dp[0][i] = arr[i] ;
    }
}

int main(void) { 
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; 

    Input(); 

    if ( N == 1 )  {
        max_result = max(max(max_dp[0][0], max_dp[0][1]), max_dp[0][2]) ; 
        min_result = min(min(min_dp[0][0], min_dp[0][1]), min_dp[0][2]) ; 
    } else { 
        DP() ; 
    }
    

    cout << max_result << ' ' << min_result << '\n'; 
    
    return 0 ;
}