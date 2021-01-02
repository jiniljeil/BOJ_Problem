#include <iostream> 
#include <queue> 
#include <vector> 
#define MAX 5001 
#define INF 1e8
using namespace std ;

int V,E,P; // 건우가 위치한 곳: P 
vector< pair<int,int> > v[MAX]; 
int DIST[MAX]; 
int short_path, gunwo_path ;
void Dijsktra(int start){
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q ; 
    DIST[start] = 0 ;
    q.push(make_pair(0, start )); 

    while(!q.empty()){
        int weight = q.top().first ; 
        int curr_v = q.top().second ; 
        q.pop(); 
        for(int i = 0 ; i < v[curr_v].size(); i++){
            int next_v = v[curr_v][i].first ;
            int next_w = v[curr_v][i].second ;
            if( DIST[next_v] > weight + next_w ){
                DIST[next_v] = weight + next_w; 
                q.push(make_pair(DIST[next_v], next_v));
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> P ; 
    int a,b,c ;
    for(int i = 0 ; i < E ;i++){
        cin >> a >> b >> c ; 
        v[a].push_back(make_pair(b,c)); 
        v[b].push_back(make_pair(a,c));
    }

    for(int i = 1 ; i <= V ; i++) DIST[i] = INF; 
    Dijsktra(1) ;
    if( DIST[P] == INF ) {
        cout << "GOOD BYE" << "\n";
        return 0; 
    }
    short_path = DIST[V];
    gunwo_path = DIST[P]; 

    for(int i = 1 ; i <= V ; i++) DIST[i] = INF; 
    Dijsktra(P); 
    if( DIST[V] == INF) {
        cout << "GOOD BYE" << "\n";
        return 0; 
    }
    gunwo_path += DIST[V]; 
    if( short_path < gunwo_path) {
        cout << "GOOD BYE" << "\n";
    }else{
        cout << "SAVE HIM" << "\n"; 
    }
    return 0 ;
}