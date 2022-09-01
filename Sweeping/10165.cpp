#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std ; 
typedef long long ll ; 
vector<pair<int,int> > V ; 
ll N, M ; 

int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 

    cin >> N >> M ; 

    for (int i = 0, a = 0, b = 0 ; i < M ; i++) { 
        cin >> a >> b ; 
        if ( a > b ) V.push_back(make_pair(b, a)) ; 
        else V.push_back(make_pair(a, b)); 
    }

    sort(V.begin(), V.end()) ; 

    for (int i = 0 ; i < V.size(); i++) { 
        int start = V[i].first ; 
        int end = V[i].second ; 

        
    }
    return 0 ;
}