#include <iostream>
#include <vector> 
#include <queue> 
#define MAX 1001
#define INF 1e8 
using namespace std;
int N, K, start_v, end_v; 
vector< pair<int,int> > v[MAX];  
vector<int> reverse_path ; 
int DIST[MAX];
int PATH[MAX]; 
int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 

    cin >> N >> K; 
    int a,b,c; 
    for(int i = 0 ;i  < K; i++){
        cin >> a >> b >> c ; 
        v[a].push_back(make_pair(b,c));
    }
    cin >> start_v >> end_v; 

    for(int i= 1; i <= N; i++) DIST[i] = INF; 
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q ; 

    q.push(make_pair(0, start_v)); // weight , start_vertex
    DIST[start_v] = 0 ;
    while(!q.empty()){
        int weight = q.top().first; 
        int curr_v = q.top().second; 

        q.pop(); 

        for(int i = 0 ; i < v[curr_v].size(); i++){
            int next_v = v[curr_v][i].first; 
            int next_w = v[curr_v][i].second; 

            if( DIST[next_v] > weight + next_w) { 
                PATH[next_v] = curr_v;
                DIST[next_v] = weight + next_w ;
                q.push(make_pair(DIST[next_v], next_v));
            }
        }
    }   
    cout << DIST[end_v] << "\n";
    int end_point = end_v; 
    while(end_point){
        reverse_path.push_back(end_point); 
        end_point = PATH[end_point]; 
    }
    cout << reverse_path.size() << "\n";
    for(int i = reverse_path.size()-1; i >= 0 ; i--){
        cout << reverse_path[i] << " "; 
    }
    cout << "\n";
    return 0;
}