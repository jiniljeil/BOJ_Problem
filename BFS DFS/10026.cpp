#include <iostream> 
#include <queue> 
#include <cstring> 
using namespace std; 
int N ;
char map[101][101];
bool visited[101][101]; 
int dx[4] = {-1, 0, 1, 0 } ;
int dy[4] = {0 , 1, 0 ,-1 }; 

void HaveNot() { 
    int result = 0 ; 
    
    queue<pair<int,int> > q; 
    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < N; j++) { 
            if( !visited[i][j]) {
                char curr = map[i][j]; 
                visited[i][j] = true; 
                q.push(make_pair(j,i)); 
                while(!q.empty()) {
                    int curr_x = q.front().first ; 
                    int curr_y = q.front().second; 
                    q.pop(); 

                    for(int k = 0 ; k < 4; k++) {
                        int dir_x = curr_x + dx[k] ;
                        int dir_y = curr_y + dy[k] ; 
                        if( dir_x < 0 || dir_x > N || dir_y < 0 || dir_y > N) continue; 
                        if( !visited[dir_y][dir_x] && map[dir_y][dir_x] == curr) { 
                            visited[dir_y][dir_x] = true; 
                            q.push(make_pair(dir_x,dir_y));
                        }
                    }
                }
                result++; 
            }
        }
    }

    cout << result << " ";
}

void Have() {
    int result = 0 ;
    queue<pair<int,int> > q ;
    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if( !visited[i][j] ) {
                char curr = map[i][j];
                visited[i][j] = true; 
                q.push(make_pair(j,i));
                while(!q.empty()) {
                    int curr_x = q.front().first; 
                    int curr_y = q.front().second ;
                    q.pop(); 
                    for(int k = 0 ; k < 4; k++) {
                        int dir_x = curr_x + dx[k]; 
                        int dir_y = curr_y + dy[k] ; 
                        if( dir_x < 0 || dir_x > N || dir_y < 0 || dir_y > N) continue; 
                        if( !visited[dir_y][dir_x]) {
                            if( curr == 'R' && (map[dir_y][dir_x] == 'R' || map[dir_y][dir_x] == 'G')) {
                                visited[dir_y][dir_x] = true; 
                                q.push(make_pair(dir_x,dir_y));
                            }else if( curr == 'G' && (map[dir_y][dir_x] == 'R' || map[dir_y][dir_x] == 'G')) {
                                visited[dir_y][dir_x] = true; 
                                q.push(make_pair(dir_x,dir_y));
                            }else if( map[dir_y][dir_x] == curr){ 
                                visited[dir_y][dir_x] = true; 
                                q.push(make_pair(dir_x,dir_y));
                            }
                        }
                    }
                }
                result++; 
            }
        }
    }
    cout << result << "\n";
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0) ;
    cout.tie(0) ;

    cin >> N ; 

    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N; j++) {
            cin >> map[i][j] ;
        }
    }

    HaveNot(); 
    memset(visited, 0 , sizeof(visited));
    Have(); 

    return 0;
}