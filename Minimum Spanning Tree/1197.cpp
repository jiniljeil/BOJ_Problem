#include <iostream>
#include <queue> 
#include <vector>
#define MAX 10001
using namespace std ;

int V, E; 
bool visited[MAX]; 
vector< pair<int,int> > v[MAX]; 

// prim's algorithm 
void prim_algo(int start) { // prim's algorithm 
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q ;
    int result = 0 ;
    visited[start] = true; 
    
    // 먼저, 1번째 노드를 중심으로 탐색 
    for(int i = 0; i < v[start].size(); i++) {
        int next_v = v[start][i].first ; 
        int next_w = v[start][i].second ;

        q.push(make_pair(next_w, next_v)); 
    }
    
    while(!q.empty()){
        int curr_w = q.top().first ;
        int curr_v = q.top().second; 
        q.pop() ;

        if( visited[curr_v] ) continue; 
        
        visited[curr_v] = true; 

        result += curr_w ; 

        for(int i = 0; i < v[curr_v].size(); i++) {
            int next_v = v[curr_v][i].first; 
            int next_w = v[curr_v][i].second; 
            q.push(make_pair(next_w, next_v)) ;
        }
    }
    cout << result << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin >> V >> E ; 
    int a,b,c; 
    for(int i = 0 ; i < E; i++){
        cin >> a >> b >> c; 
        v[a].push_back(make_pair(b,c)); 
        v[b].push_back(make_pair(a,c));
    }
    prim_algo(1);
    return 0;
}