#include <iostream> 
#include <queue> 
#include <vector> 
#define MAX 101
using namespace std ;
int N, M; 
vector<pair<int,int> > arr[MAX][MAX]; 
bool visited[MAX][MAX] ;
bool on[MAX][MAX];
queue<pair<int,int> > q; 
int dx[4] = {-1, 0, 1, 0} ;
int dy[4] = {0, 1, 0 ,-1}; 
int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> N >> M; 
    int a,b,c,d; 
    for(int i = 0 ; i < M; i++) {
        cin >> a >> b >> c >> d ; 
        arr[a][b].push_back(make_pair(c,d));
    }
    q.push(make_pair(1,1)); 
    on[1][1] = true; 
    visited[1][1] = true;
    int lightOn = 1 ;
    while(!q.empty()) {
        int curr_x = q.front().first ;
        int curr_y = q.front().second; 
        q.pop();

        // Turn on light 
        for(int i = 0 ; i < arr[curr_y][curr_x].size(); i++) {
            int next_y = arr[curr_y][curr_x][i].first; 
            int next_x = arr[curr_y][curr_x][i].second; 

            if( !on[next_y][next_x]) {
                lightOn++;
                on[next_y][next_x] = true;

                for(int j = 0; j < 4; j++) {
                    int dir_x = next_x + dx[j]; 
                    int dir_y = next_y + dy[j]; 

                    if( dir_x <= 0 || dir_x > N || dir_y <= 0 || dir_y > N) continue; 
                    if( visited[dir_y][dir_x] ) {
                        q.push(make_pair(dir_x,dir_y));
                        break;
                    }
                }
            }
        }

        // 불 켜진 곳에 방문
        for(int i = 0 ; i < 4; i++) {
            int dir_x = curr_x + dx[i]; 
            int dir_y = curr_y + dy[i]; 
            
            if( dir_x <= 0 || dir_x > N || dir_y <= 0 || dir_y > N) continue;
            if( visited[dir_y][dir_x] || !on[dir_y][dir_x]) continue; 
            visited[dir_y][dir_x] = true; 
            q.push(make_pair(dir_x,dir_y));
        }
    }
    
    cout << lightOn << "\n";
    return 0;
}