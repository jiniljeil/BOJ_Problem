#include <iostream> 
#include <vector> 
typedef long long ll ; 
using namespace std; 

ll n, k ; 
ll answer ; 
vector<int> v; 
int dp[10001] ; 

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0) ; 
    
    cin >> n >> k ; 
    for (int i = 0, t = 0 ; i < n; i++) { 
        cin >> t ; v.push_back(t) ; 
    }
    
    dp[0] = 1; 

    for (int i = 0 ; i < v.size(); i++) { 
        for (int j = v[i]; j <= k ; j++) { 
            dp[j] += dp[j - v[i]] ; 
        }
    }
    cout << dp[k] << '\n'; 

    return 0 ; 
}