#include <iostream> 
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;  

int N ; 
vector<pair<int, int> > V ;  
priority_queue<int, vector<int>, greater<int> > pq ; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N ; 
    for (int i = 0,a,b,c; i < N; i++) { 
        cin >> a >> b >> c ;
        V.push_back(make_pair(b, c)); 
    }
    sort(V.begin(), V.end()) ; 

    pq.push(V[0].second) ; 
    long long answer = 1 ; 
    for (int i = 1 ; i < V.size(); i++) { 
        int end = pq.top(); 
        if ( V[i].first < end ) { 
            answer++; 
        } else { 
            pq.pop(); 
        }
        pq.push(V[i].second) ; 
    }
    cout << answer << '\n'; 
    return 0 ;
}