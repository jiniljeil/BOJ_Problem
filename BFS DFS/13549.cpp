#include <iostream>
#include <queue> 
#define MAX 100001
using namespace std; 

int N, K;
int visited[MAX];
int map[MAX];
int dx[3] = {2, -1, 1} ;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    queue<pair<int,int> > q; 

    cin >> N >> K ; 
    q.push(make_pair(N, 0));
    visited[N] = true ;
    map[N] = 1; 

    while(!q.empty()) {
        int curr_x = q.front().first;
        int result = q.front().second; 
        q.pop(); 

        if( curr_x == K) {
            cout << result << "\n";
            break;
        }

        for(int i = 0 ; i < 3; i++) {
            int dir_x;
            if( i == 0 ) {
                dir_x = curr_x * dx[i];
                if( dir_x < 0 || dir_x > MAX - 1) continue; 
                if( !visited[dir_x] && map[dir_x] == 0) {
                    visited[dir_x] = true; 
                    map[dir_x] = map[curr_x]; 
                    q.push(make_pair(dir_x, result));
                }
            }else{
                dir_x = curr_x + dx[i];
                if( dir_x < 0 || dir_x > MAX - 1) continue; 
                if( !visited[dir_x] && map[dir_x] == 0){
                    visited[dir_x] = true; 
                    map[dir_x] = map[curr_x] + 1; 
                    q.push(make_pair(dir_x, result + 1)) ;
                }
            }
        }
    }

    return 0;
}