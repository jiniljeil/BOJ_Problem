#include <iostream> 
#include <vector>
#include <queue> 
#include <stdint.h> 

using namespace std ;
typedef long long ll ;
typedef pair<ll, ll> pi; 
int N, K ; 
int cnt ;
vector<pi> V;
int id, w; 
typedef struct user {
    ll idx ; 
    ll id ; 
    ll w ; 
} USER ; 

struct compare { 
    bool operator() (const USER &a, const USER &b) { 
        if ( a.w == b.w ) return a.idx < b.idx ; 
        else return a.w > b.w ; 
    }
};
priority_queue<USER, vector<USER>, compare> pq ; 
vector<USER> users ; 
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> N >> K ; 
    for (int i = 0 ; i < N ; i++) {
        cin >> id >> w ; V.push_back({id, w}) ;
        if ( i < K ) pq.push({i, id, w}) ;
    } 
    uint64_t result = 0 ; 
    int num = K ; 
    while ( cnt < N ) {
        users.clear() ; 
        int t = pq.top().w ; 
        while (!pq.empty() && t == pq.top().w) { 
            users.push_back(pq.top()) ; pq.pop(); 
        }
        for (int i = 0 ; i < users.size() ;i++) { 
            result += (++cnt) * users[i].id ; 
        }
        int i = users.size() -1 ; 
        while ( i >= 0 && num < N ) { 
            pq.push({users[i].idx, V[num].first, V[num].second + t }) ;
            i-- ; num++; 
        }
    }
    cout << result << '\n'; 
    return 0 ;
}