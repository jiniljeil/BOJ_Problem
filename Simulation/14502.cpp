#include <iostream>
#include <queue> 
#include <string.h>

using namespace std ;

int N, M, max_result; 
int map[9][9];
int copy_map[9][9];
int visited[9][9];
int dx[4] = {-1, 0, 1, 0} ;
int dy[4] = { 0, 1, 0, -1};
void BFS() {
    memset(visited, 0, sizeof(visited));
    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < M; j++) {
            if( !visited[i][j] && copy_map[i][j] == 2){ 
                queue<pair<int,int> > q ;
                q.push(make_pair(j,i));
                visited[i][j] = true; 

                while(!q.empty()) {
                    int curr_x = q.front().first ;
                    int curr_y = q.front().second; 

                    q.pop(); 

                    for(int k = 0 ; k < 4; k++) {
                        int dir_x = curr_x + dx[k]; 
                        int dir_y = curr_y + dy[k]; 
                        if( dir_x < 0 || dir_x >= M || dir_y < 0 || dir_y >= N) continue;
                        if( !visited[dir_y][dir_x] && copy_map[dir_y][dir_x] == 0) { 
                            copy_map[dir_y][dir_x] = 2; 
                            visited[dir_y][dir_x] = true; 
                            q.push(make_pair(dir_x, dir_y));
                        }
                    }
                }
            }
        }
    }
    int c = 0 ;
    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < M; j++) {
            if( copy_map[i][j] == 0) {
                c++; 
            }
        }
    }

    max_result = (max_result < c) ? c : max_result ; 
}

void COPY() {
    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < M; j++) {
            copy_map[i][j] = map[i][j];
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> N >> M; 
    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j< M; j++) {
            cin >> map[i][j]; 
        }
    }

    for(int i = 0 ; i < N; i++) { 
        for(int j = 0 ; j < M; j++) { 
            if(map[i][j] != 0) continue; 
            for(int k1 = 0; k1 < N; k1++) {
                for(int k2 = 0 ; k2 < M; k2++){
                    if((i == k1 && j == k2) || map[k1][k2] != 0 ) continue;
                    for(int a = 0; a < N; a++) {
                        for(int b = 0 ; b < M; b++) {
                            if((i == a && j == b) || (k1 == a && k2 == b) || map[a][b] != 0) continue;
                            COPY(); 
                            copy_map[i][j] = copy_map[k1][k2] = copy_map[a][b] = 1; 
                            BFS();
                        }
                    }

                }
            }

        }
    }

    cout << max_result << '\n';
    return 0; 
}