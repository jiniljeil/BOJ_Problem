#include <iostream>
#include <vector>
#include <queue> 
#include <limits.h>
#define MAX 1001 
#define INF INT_MAX
using namespace std;

int N, M; 
int S, E; 
vector< pair<int,int> > v[MAX]; 
int DIST[MAX]; 

int Dijsktra(int start, int end) { 
    for(int i = 1 ; i <= N; i++) DIST[i] = INF ;

    // priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int, int> > > q; 
    priority_queue< pair<int,int> > q ; 
    q.push(make_pair(0, start)); 
    DIST[start] = 0 ;

    while(!q.empty()){
        int curr_w = -q.top().first; 
        int curr_v = q.top().second;
        q.pop(); 

        // Key Point
        if ( DIST[curr_v] < curr_w ) continue ; 

        for(int i = 0 ; i < v[curr_v].size(); i++){
            int next_v = v[curr_v][i].first; 
            int next_w = v[curr_v][i].second; 

            if( DIST[next_v] > curr_w + next_w) {
                DIST[next_v] = curr_w + next_w;
                q.push(make_pair(-DIST[next_v],next_v));
            }
        }
    }
    return DIST[end] ; 
}

void Input() {
    cin >> N >> M ; 
    int a,b,c; 
    for(int i = 0 ; i < M; i++){
        cin >> a >> b >> c; 
        v[a].push_back(make_pair(b, c)); 
    }
    cin >> S >> E ; 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Input(); 
    cout << Dijsktra(S, E) << '\n';

    return 0 ;
}
