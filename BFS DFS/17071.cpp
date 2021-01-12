#include <iostream>
#include <queue> 
#define MAX 500001
using namespace std; 

int N, K;
int visited[2][MAX];
int dx[3] = {2, -1, 1} ;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    queue< pair<int,int> > q; 

    cin >> N >> K ; 
    q.push(make_pair(N, 0));
    visited[0][N] = true ;
    int add = 0 ;
    bool check = false;
    while(!q.empty()) {
        int curr_x = q.front().first;
        int time = q.front().second; 
        q.pop(); 

        int m = (time + 1) % 2;
        if( visited[add % 2][K]) {
            check = true; 
            cout << add << "\n";
            break;
        }
        if( time > add) K += (++add);
        if( K > MAX - 1) { 
            break;
        }
        for(int i = 0 ; i < 3; i++) {
            int dir_x;
            if( i == 0 ) {
                dir_x = curr_x * dx[i];
                if( dir_x < 0 || dir_x > MAX - 1) continue; 
                if( !visited[m][dir_x]) {
                    visited[m][dir_x] = true; 
                    q.push(make_pair(dir_x, time + 1));
                }
            }else{
                dir_x = curr_x + dx[i];
                if( dir_x < 0 || dir_x > MAX - 1) continue; 
                if( !visited[m][dir_x]){
                    visited[m][dir_x] = true; 
                    q.push(make_pair(dir_x, time + 1)) ;
                }
            }
        }
    }
    if(!check) cout << "-1" << '\n';
    return 0;
}