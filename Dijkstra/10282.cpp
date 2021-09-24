#include <iostream>
#include <queue> 
#include <vector> 
#include <string.h> 
#define MAX 10001 
#define INF 1e9
using namespace std; 

// 첫 번째 줄에 컴퓨터 개수 n, 의존성 개수 d, 해킹당한 컴퓨터의 번호 c가 주어진다
// (1 ≤ n ≤ 10,000, 1 ≤ d ≤ 100,000, 1 ≤ c ≤ n).

//이어서 d개의 줄에 각 의존성을 나타내는 정수 a, b, s가 주어진다(1 ≤ a, b ≤ n, a ≠ b, 0 ≤ s ≤ 1,000). 
// 이는 컴퓨터 a가 컴퓨터 b를 의존하며, 컴퓨터 b가 감염되면 s초 후 컴퓨터 a도 감염됨을 뜻한다.
int testcase ;
int n, d, c ; 
vector<pair<int,int> > v[MAX]; 
int dist[MAX]; 
vector<pair<int, int> > result; 
void Dijkstra(int start) {
    int num_of_computer = 0, time = 0 ;
    for(int i = 1 ; i <= n; i++) dist[i] = INF ; 

    priority_queue<pair<int,int> > pq ;
    pq.push(make_pair(-0, start)); 
    dist[start] = 0 ; 

    while(!pq.empty()) {
        int weight = -pq.top().first ;
        int curr = pq.top().second; 
        pq.pop() ;

        for (int i = 0 ; i < v[curr].size(); i++) {
            int next_v = v[curr][i].first; 
            int next_w = v[curr][i].second; 
            if (dist[next_v] > dist[curr] + next_w) { 
                dist[next_v] = dist[curr] + next_w ; 
                pq.push(make_pair(-dist[next_v], next_v)); 
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if ( dist[i] != INF ) {
            num_of_computer++; 
            time = max(time, dist[i]) ;
        }
    }

    cout << num_of_computer << ' ' << time << '\n';
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0) ;cout.tie(0); 

    cin >> testcase ;

    for (int i = 0 ; i < testcase; i++) {
        cin >> n >> d >> c ; 

        for(int a, b, s, j = 0 ; j < d ; j++) {
            cin >> a >> b >> s ; 
            v[b].push_back(make_pair(a, s)); 
        }
        Dijkstra(c); 
        for(int k = 1 ; k <= n ; k++) { 
            if (v[k].size() > 0) v[k].clear();  
        }
    }
    return 0;
}
