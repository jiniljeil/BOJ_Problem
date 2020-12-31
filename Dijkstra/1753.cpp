#include <iostream>
#include <vector>
#include <queue> 
#define MAX 20001 
#define INF 1e8
using namespace std;

int V,E,K; 
vector< pair<int,int> > v[MAX]; 
int DIST[MAX]; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    cin >> V >> E >> K; 
    int tmp1,tmp2,tmp3; 
    for(int i = 0 ; i < E; i++){
        cin >> tmp1 >> tmp2 >> tmp3; 
        v[tmp1].push_back(make_pair(tmp2, tmp3)); 
    }

    for(int i = 1 ; i <= V; i++) DIST[i] = INF ;

    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int, int> > > q; 

    q.push(make_pair(0, K)); 
    DIST[K] = 0 ;

    while(!q.empty()){
        int weight = q.top().first; 
        int curr_vertex = q.top().second;
        q.pop(); 

        for(int i = 0 ; i < v[curr_vertex].size(); i++){
            int next_v = v[curr_vertex][i].first; 
            int next_w = v[curr_vertex][i].second; 

            if( DIST[next_v] > weight + next_w) {
                DIST[next_v] = weight + next_w;
                q.push(make_pair(DIST[next_v],next_v));
            }
        }
    }

    for(int i = 1 ; i <= V; i++) {
        if(DIST[i] == INF){
            cout << "INF" << "\n";
        }else{
            cout << DIST[i] << "\n";
        }
    }
    return 0 ;
}


