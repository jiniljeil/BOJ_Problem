#include <iostream>
#include <queue> 
#include <vector>
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
                    map[dir_x] = curr_x ; 
                    q.push(make_pair(dir_x, result + 1));
                }
            }else{
                dir_x = curr_x + dx[i];
                if( dir_x < 0 || dir_x > MAX - 1) continue; 
                if( !visited[dir_x] && map[dir_x] == 0){
                    visited[dir_x] = true; 
                    map[dir_x] = curr_x ;
                    q.push(make_pair(dir_x, result + 1)) ;
                }
            }
        }
    }
    vector<int> path ;
    int curr_loc = K ; 
    int pre_loc ;
    while(curr_loc != N) {
        path.push_back(curr_loc); 
        pre_loc = map[curr_loc]; 
        curr_loc = pre_loc;
    }
    path.push_back(curr_loc);
    for(int i = path.size() - 1; i >= 0; i--) { 
        cout << path[i] << " "; 
    } 
    cout << "\n";
    return 0;
}