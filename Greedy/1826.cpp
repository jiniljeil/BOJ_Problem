#include <iostream> 
#include <vector> 
#include <algorithm>
#include <queue>
using namespace std ;
int N ;
int a, b;  
int L, P ; 
vector<pair<int, int> > V ; 
priority_queue<int> pq ; 
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0) ;

    cin >> N ; 

    for (int i = 0 ; i < N ; i++) { 
        cin >> a >> b ; 
        V.push_back(make_pair(a, b)) ;
    }

    sort(V.begin(), V.end()) ; 

    cin >> L >> P ; 

    int curr_d = P ; 
    int idx = 0 ; 
    int answer = 0 ; 

    while (curr_d < L) { 
        while ( idx < V.size() && V[idx].first <= curr_d ) {
            pq.push(V[idx].second) ; idx++;
        }
        if ( pq.empty() ) { 
            answer = -1;
            break; 
        }

        curr_d += pq.top() ; pq.pop() ; 
        answer++; 
    }

    cout << answer << '\n'; 
    
    return 0 ;
}