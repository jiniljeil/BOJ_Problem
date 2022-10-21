#include <iostream> 

using namespace std ;
int N, num ; 
pair<int, int> arr[99] ; 
int dp[99] ; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N ; 

    for (int i = 1 ; i <= N ; i++) {
        cin >> arr[i].first >> arr[i].second ; 

        for (int j = 0 ; j < i ; j++) { 
            if ( j + arr[j].first <= i && i + arr[i].first <= N + 1 ) { 
                dp[i] = max(dp[i], dp[j] + arr[i].second) ; 
            }
        }
    }

    int s = 0 ; 
    for (int i = 0 ; i <= N ; i++) { 
        s = max(s, dp[i]) ; 
    }

    cout << s << '\n' ;

    return 0 ;
}