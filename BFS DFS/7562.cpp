#include <iostream>
#include <queue> 
#include <cstring> 
using namespace std; 

int T, S, start_x, start_y, end_x, end_y;
bool visited[300][300];
int dx[8] = {-2,-1, 1, 2, 2, 1, -1, -2 } ;
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1} ;

int main(void) {
    ios::sync_with_stdio(0) ;
    cin.tie(0); cout.tie(0) ;

    cin >> T ; 
    for(int i = 0 ; i < T; i++) {
        cin >> S ;  // size 
        cin >> start_y >> start_x ;
        cin >> end_y >> end_x; 

        queue<pair<pair<int,int>, int> > q; 

        q.push(make_pair(make_pair(start_x, start_y), 0));
        visited[start_y][start_x] = true; 
        bool check = false; 

        while(!q.empty()) { 
            int size = q.size(); 
            for(int j = 0 ; j < size; j++) {
                int curr_x = q.front().first.first ;
                int curr_y = q.front().first.second ;
                int result = q.front().second; 
                q.pop() ; 

                if(curr_y == end_y && curr_x == end_x) {
                    cout << result << "\n" ; 
                    check = true; 
                    break; 
                }
                for(int k = 0 ; k < 8; k++) {
                    int dir_x = curr_x + dx[k]; 
                    int dir_y = curr_y + dy[k] ;
                    if( dir_x < 0 || dir_x >= S || dir_y < 0 || dir_y >= S) continue; 
                    if( !visited[dir_y][dir_x] ) {
                        visited[dir_y][dir_x] = true; 
                        q.push(make_pair(make_pair(dir_x,dir_y), result+1));
                    } 
                }
            }
            if( check ) {
                break; 
            }
        }
        memset(visited, false, sizeof(visited));
    }
    return 0;
}