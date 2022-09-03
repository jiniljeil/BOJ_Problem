#include <iostream> 
#include <algorithm>
#include <vector> 
#include <queue> 
using namespace std ;

int N ; 
pair<int, int> V [200010]; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N ; 

    for (int i = 0 ; i < N ; i++) { 
        cin >> V[i].first >> V[i].second ; 
    }

    sort(V, V + N) ; 

    int idx = N - 1; 

    priority_queue<int> pq; 

    long long answer = 0 ; 
    for (int i = N ; i > 0 ; i--) { 
        // 
        while (idx >= 0 && V[idx].first >= i) {
            pq.push(V[idx].second) ; 
            idx--; 
        }
        if ( !pq.empty() ) { 
            answer += pq.top() ; pq.pop() ; 
        }
    }

    cout << answer << '\n'; 

    return 0 ;
}