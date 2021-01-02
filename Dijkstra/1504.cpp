#include <iostream> 
#include <vector> 
#include <queue>
#include <algorithm> 
#define MAX 801
#define INF 1e8 

using namespace std;

int N, E, v1, v2; 
int DIST[MAX] ;
vector< pair<int,int> > v[MAX];  
int short_path1, short_path2 ;
bool connect1 = true, connect2 = true; 
void Dijsktra(int start){
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
    DIST[start] = 0 ; // 이것 실수로 계속 틀림 
    q.push(make_pair(0, start));

    while(!q.empty()){
        int weight = q.top().first ;
        int curr_v = q.top().second ;
        q.pop(); 

        for(int i = 0 ; i < v[curr_v].size(); i++){
            int next_v = v[curr_v][i].first ;
            int next_w = v[curr_v][i].second; 
            
            if( DIST[next_v] > weight + next_w) {
                DIST[next_v] = weight + next_w; 
                q.push(make_pair(DIST[next_v] , next_v));
            }
        }
    }
}
int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    cin >> N >> E; 
    int a,b,c; 
    for(int i = 0 ; i < E ;i++){
        cin >> a >> b >> c; 
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    cin >> v1 >> v2; 
    // 1 -> A || B 
    for(int i = 1 ; i <= N ; i++) DIST[i] = INF; 
    Dijsktra(1); 
    if( DIST[v1] == INF ) connect1 = false; 
    if( DIST[v2] == INF ) connect2 = false;
    short_path1 += DIST[v1]; 
    short_path2 += DIST[v2]; 

    // A -> B , B -> A  (Path 동일)
    for(int i = 1 ; i <= N ; i++) DIST[i] = INF; 
    Dijsktra(v1) ;
    if(connect1) short_path1 += DIST[v2] ;
    if(connect2) short_path2 += DIST[v2] ;

    // 1 -> A -> B -> N 
    for(int i = 1 ; i <= N ; i++) DIST[i] = INF; 
    Dijsktra(v2); 
    if(connect1) short_path1 += DIST[N]; 

    // 1 -> B -> A -> N
    for(int i = 1 ; i <= N ; i++) DIST[i] = INF;
    Dijsktra(v1);
    if(connect2) short_path2 += DIST[N]; 
    
    // Connection X 
    if( !connect1 && !connect2) cout << "-1" << "\n"; 
    else{
        // cout << short_path1 << " " << short_path2 << "\n";
        int result = min(short_path1, short_path2); 
        if( result == INF ) cout << "-1" << "\n"; 
        else cout << result << "\n";
    }

    return 0;
}