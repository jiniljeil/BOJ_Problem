#include <iostream> 
#include <vector> 
#include <algorithm>
#include <queue> 
using namespace std ;
int N ; 
vector<pair<int,int> > V;  
int a,b ; 
int main(void) {
    ios::sync_with_stdio(false) ; cin.tie(0) ; 

    cin >> N ; 

    for (int i = 0 ; i < N ;i++) { 
        cin >> a >> b ; 
        V.push_back(make_pair(a, b)) ; 
    }

    sort(V.begin(), V.end()); 

    int answer = 1 ; 
    priority_queue<int, vector<int>, greater<int> > pq ; 

    pq.push(V[0].second) ; 
    for (int i = 1 ; i < V.size(); i++) { 
        while (!pq.empty() && V[i].first >= pq.top()) { 
            pq.pop() ; 
        }

        pq.push(V[i].second) ; 

        answer = (answer < pq.size()) ? pq.size() : answer ; 
    }
    cout << answer << '\n'; 
    return 0 ;
}