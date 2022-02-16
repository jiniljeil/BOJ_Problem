#include <iostream>
#include <vector>
#include <cstring> 
#define MAX 1001
using namespace std ;

int N ; 
vector<int> v ;
int dp[MAX] ; 

int DP(int x, int len, bool reverse) { 
    if ( x == N ) return 0 ; 
    if ( dp[x] != -1 ) return dp[x] ; 

    if ( reverse && v[x - 1] < v[x]) { 
        return v[x - 1] ; 
    }

    for (int i = 0 ; i < x; i++) { 
        if ( !reverse ) { 
            if ( v[i] > v[i + 1] ) { 
                dp[x] = len + DP( i - 1, len + 1, true) ; 
            } else { 
                dp[x] = len + DP( i - 1, len + 1, reverse) ; 
            }
        } else {    
            dp[x] = len + DP( i - 1, len + 1, reverse) ; 
        }
    }

    return dp[x] ; 
}

void Input() { 
    cin >> N ; 
    int k = 0 ; 
    for(int i = 0 ; i < N; i++) {
        cin >> k ; 
        v.push_back(k) ; 
    }
}

int main(void) {
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; 

    Input() ;

    memset( dp, -1 , sizeof(dp)) ; 
    dp[0] = 1; 
    DP(N - 1, 1, false) ; 

    for (int i = 0 ; i < N; i++) { 
        cout << dp[i] << ' ' ; 
    }
    return 0 ;
}