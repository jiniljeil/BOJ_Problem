#include <iostream> 
#include <vector> 
#include <queue> 
#define MAX 1001
using namespace std; 
int N, M; 
vector< pair<int,int> > v[MAX]; 
bool visited[MAX]; 
int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    cin >> N >> M; 

    int a,b,c; 
    for(int i = 0 ; i < M; i++) {
        cin >> a >> b >> c; 
        v[a].push_back(make_pair(b,c)); 
        v[b].push_back(make_pair(a,c)); 
    }

    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q ;
    
    visited[1] = true; 
    int result = 0;
    // 1 주위 탐색 
    for(int i = 0 ; i < v[1].size(); i++) {
        q.push(make_pair(v[1][i].second, v[1][i].first)); 
    }

    while(!q.empty()){
        int curr_w = q.top().first ;
        int curr_v = q.top().second; 
        q.pop(); 

        if( visited[curr_v] ) continue; 

        visited[curr_v] = true ;

        result += curr_w ; 

        for(int i = 0 ; i < v[curr_v].size(); i++) {
            q.push(make_pair(v[curr_v][i].second, v[curr_v][i].first));
        }
    }
    cout << result << "\n";

    
    return 0; 
}