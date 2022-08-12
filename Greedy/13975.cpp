#include <iostream> 
#include <algorithm>
#include <queue> 
using namespace std; 
typedef long long ll ; 
int TC ; 
int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 

    cin >> TC ;

    while(TC--) {
        priority_queue<ll, vector<ll>, greater<ll> > pq ; 
        int n, num; cin >> n ; 
        for (int i = 0 ; i < n ;i++) { 
            cin >> num ; 
            pq.push(num) ; 
        }

        ll answer = 0 ; 
        while(pq.size() > 1) { 
            ll a = pq.top(); pq.pop(); ll b = pq.top() ; pq.pop();
            ll sum = a + b ;
            answer += sum ;
            pq.push(sum) ;  
        }
        cout << answer << '\n'; 
    }
    return 0; 
}