#include <iostream>
#include <queue> 
#include <vector> 
#include <algorithm> 
#define MAX 1001
#define INF 1e8 
using namespace std; 

int N, M, X ; 
vector< pair<int,int> > v[MAX]; 
int result ; 
int DIST[MAX]; 
int Dijsktra(int start, int end) { 
    for(int i = 1 ; i <= N ; i++) DIST[i] = INF; 

    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q ;

    q.push(make_pair(0, start)); 
    DIST[start] = 0 ;
    while(!q.empty()){
        int weight = q.top().first ; 
        int curr_v = q.top().second ; 
        q.pop(); 

        for(int i = 0 ; i < v[curr_v].size(); i++) { 
            int next_v = v[curr_v][i].first ; 
            int next_w = v[curr_v][i].second; 

            if( DIST[next_v] > weight + next_w) { 
                DIST[next_v] = weight + next_w ;   
                q.push(make_pair(DIST[next_v], next_v)); 
            }
        }
    }
    return DIST[end] ;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    cin >> N >> M >> X ; 
    int a,b,c; 
    for(int i = 0 ; i < M ;i++) {
        cin >> a >> b >> c ; 
        v[a].push_back(make_pair(b,c)); 
    }

    vector< pair<int,int> > vc;
    
    for(int i = 1;  i <= N; i++) {
        if( i != X ) {
            vc.push_back(make_pair(i, Dijsktra(i, X))); 
        }
    }
    for(int i = 0; i < vc.size(); i++){
        int vertex = vc[i].first; 
        int cost = vc[i].second; 
        int back_cost = Dijsktra(X, vertex) ;
        result = max(result, cost + back_cost) ;
    }

    cout << result << "\n";
    return 0 ;
}