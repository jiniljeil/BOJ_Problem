#include <iostream> 
#include <queue> 
using namespace std ;
int N ; 
priority_queue<int, vector<int>, greater<int> > pq ; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ;
    cin >> N ; 

    for (int i = 0, n ; i < N * N ; i++) { 
        cin >> n ; 
        if ( pq.size() < N ) { 
            pq.push(n) ; 
        } else { 
            pq.push(n) ; 
            pq.pop() ; 
        }
    }
    cout << pq.top() << '\n';

    return 0 ;
}