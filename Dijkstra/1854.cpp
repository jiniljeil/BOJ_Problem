#include <iostream> 
#include <vector> 
#include <queue> 
#include <algorithm> 
#include <cstring> 
#define INF 1e8
using namespace std ;
int n, m, k ;
vector<pair<int,int> > v[1001] ;
priority_queue<int> store_dist[1001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0) ;
    cin >> n >> m >> k; 

    int a,b,c;
    for(int i = 0 ; i < m; i++) {
        cin >> a >> b >> c ;
        v[a].push_back(make_pair(b,c));
    }

    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > > q ;
    q.push(make_pair(0,1));
    store_dist[1].push(0);
    
    while(!q.empty()) {
        int curr_w = q.top().first; 
        int curr_v = q.top().second; 

        q.pop(); 

        for(int i = 0 ; i < v[curr_v].size(); i++) {
            int next_v = v[curr_v][i].first ;
            int next_w = v[curr_v][i].second ;

            if( store_dist[next_v].size() < k) {
                store_dist[next_v].push(curr_w + next_w);
                q.push(make_pair(curr_w + next_w, next_v));
            }else if(store_dist[next_v].top() > curr_w + next_w){
                store_dist[next_v].pop();
                store_dist[next_v].push(curr_w + next_w);
                q.push(make_pair(curr_w + next_w, next_v));
            }
        }
    }

    for(int i = 1 ; i <= n; i++) {
        if( store_dist[i].size() < k) cout << "-1" << '\n';
        else cout << store_dist[i].top() << '\n';
    }
    return 0;
}