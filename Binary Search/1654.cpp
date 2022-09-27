#include <iostream> 
#include <vector> 
#include <climits>
using namespace std; 
typedef long long ll ; 
int K, N ; 
vector<ll> V ; 

ll max_n = INT_MIN ; 
ll num ; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> K >> N ; 

    for (int i = 0; i < K ; i++) { 
        cin >> num ; 
        V.push_back(num) ; 
        max_n = max(max_n, num) ; 
    }

    ll left = 1, right = max_n ; 
    ll mid = max_n ; 
    ll answer = INT_MIN;  
    while ( left <= right ) { 
        mid = (left + right) / 2 ; 
        int cnt = 0 ; 

        for (int i = 0 ; i < V.size() ; i++) { 
            cnt += (V[i]/mid); 
        }

        if ( cnt < N ) { 
            right = mid - 1 ; 
        } else { 
            answer = max(answer, mid) ; 
            left = mid + 1 ;
        }
    }

    cout << answer << '\n' ; 
    return 0 ;
}