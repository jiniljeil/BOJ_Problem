#include <iostream> 
#include <queue> 
#include <queue> 
#include <algorithm>
#include <string.h> 
#define INF 2100000000
using namespace std ;

int testcase ;
int n, m, t ; // 각각 교차로, 도로, 목적지 후보의 개수 
int s, g, h ; // s는 예술가들의 출발지, g-h, h-g 해당 간선은 무조건 지나야함 
int dest ; 
int hg_gh_path_cost; 
int dist_S[2001], dist_G[2001],dist_H[2001] ; 

void Dijkstra(int start, int dist[2001], vector<pair<int,int> > a[]){
    for(int i = 1; i <= n; i++) dist[i] = INF;

    dist[start] = 0;
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(-0, start));

    while(!pq.empty()){
        int curr_v = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();

        for (int i = 0 ; i < a[curr_v].size(); i++) {
            int next_v = a[curr_v][i].first ; 
            int next_w = a[curr_v][i].second ;  

            if (dist[next_v] > dist[curr_v] + next_w) { 
                dist[next_v] = dist[curr_v] + next_w ; 
                pq.push(make_pair(-dist[next_v], next_v)); 
            }
        }
    }
}

int main(void) { 
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> testcase ; 
    clock_t start, end ; 
    for(int k = 0 ; k < testcase ; k++) {
        
        vector<pair<int, int> > v[2001]; 
        vector<int> candidate ; 
        vector<int> result ; 
        cin >> n >> m >> t ; 
        cin >> s >> g >> h ; 

        for (int a, b, c, j = 0 ; j < m ;j++) {
            cin >> a >> b >> c ; 
            v[a].push_back(make_pair(b, c)); 
            v[b].push_back(make_pair(a, c)); 
            if ((a == g && b == h) || (a == h && b == g)) hg_gh_path_cost = c ; 
        } 
        
        for (int i = 0 ; i < t ; i++) {
            cin >> dest ; 
            candidate.push_back(dest) ;
        }

        Dijkstra(s, dist_S, v) ;
        Dijkstra(g, dist_G, v) ; 
        Dijkstra(h, dist_H, v) ; 

        for (int i = 0; i < candidate.size(); i++) {
            if (dist_S[candidate[i]] == dist_S[g] + hg_gh_path_cost + dist_H[candidate[i]]) result.push_back(candidate[i]); 
            else if (dist_S[candidate[i]] == dist_S[h] + hg_gh_path_cost + dist_G[candidate[i]]) result.push_back(candidate[i]); 
        }
        sort(result.begin(), result.end()); 

        for(int i = 0 ; i < result.size() ;i++) { 
            cout << result[i] << ' ' ;
        }
        cout << '\n'; 
    }
    return 0; 
}