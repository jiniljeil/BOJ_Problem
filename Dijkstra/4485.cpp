#include <iostream>
#include <cstring> 
#include <queue>
#define INF 1e8
using namespace std;
int N ; 
int arr[125][125]; 
int dist[125][125];
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0 , -1};
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int c = 1; 
    while(true) {
        cin >> N ; 
        if(N == 0) break ;
        for(int i = 0; i < N; i++) {
            for(int j = 0 ; j < N; j++) {
                cin >> arr[i][j];
                dist[i][j] = INF;
            }
        }
        
        priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > q; 
        q.push(make_pair(arr[0][0], make_pair(0,0)));
        dist[0][0] = arr[0][0]; 
        while(!q.empty()) {
            int curr_w = q.top().first; 
            int curr_y = q.top().second.first;
            int curr_x = q.top().second.second; 

            q.pop(); 

            for(int i = 0 ; i < 4; i++) {
                int next_y = curr_y + dy[i]; 
                int next_x = curr_x + dx[i]; 

                if( next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) continue; 
                if( dist[next_y][next_x] > curr_w + arr[next_y][next_x] ) {
                    dist[next_y][next_x] = curr_w + arr[next_y][next_x]; 
                    q.push(make_pair(dist[next_y][next_x], make_pair(next_y, next_x)));
                }
            }
        }

        cout << "Problem " << c << ": " << dist[N-1][N-1] << '\n';
        memset(arr, 0, sizeof(arr));
        c++;
    }
    return 0;
}