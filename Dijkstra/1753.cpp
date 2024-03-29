#include <iostream>
#include <vector>
#include <queue> 
#define MAX 20001 
#define INF 1e8
using namespace std;

int V,E,K; 
vector< pair<int,int> > v[MAX]; 
int DIST[MAX]; 

void Dijsktra(int start) { 
    for(int i = 1 ; i <= V; i++) DIST[i] = INF ;

    // priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int, int> > > q; 
    priority_queue< pair<int,int> > q ; 
    q.push(make_pair(0, start)); 
    DIST[start] = 0 ;

    while(!q.empty()){
        int curr_w = -q.top().first; 
        int curr_v = q.top().second;
        q.pop(); 

        for(int i = 0 ; i < v[curr_v].size(); i++){
            int next_v = v[curr_v][i].first; 
            int next_w = v[curr_v][i].second; 

            if( DIST[next_v] > curr_w + next_w) {
                DIST[next_v] = curr_w + next_w;
                q.push(make_pair(-DIST[next_v],next_v));
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    cin >> V >> E >> K; 
    int a,b,c; 
    for(int i = 0 ; i < E; i++){
        cin >> a >> b >> c; 
        v[a].push_back(make_pair(b, c)); 
    }

    Dijsktra(K) ; 

    for(int i = 1 ; i <= V; i++) {
        if(DIST[i] == INF){
            cout << "INF" << "\n";
        }else{
            cout << DIST[i] << "\n";
        }
    }
    return 0 ;
}


