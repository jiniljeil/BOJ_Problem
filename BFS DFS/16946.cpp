#include <iostream> 
#include <queue> 
#include <vector> 
#include <cstring> 
#define MAX 1001
using namespace std ;

int N, M ; 
int MAP[MAX][MAX] ;
int value[MAX][MAX] ; 
bool visitedWall[MAX][MAX] ; 
bool visited[MAX][MAX] ; 

int dx[4] = {-1, 0, 1, 0} ; 
int dy[4] = { 0,-1, 0, 1} ; 

void BFS(int x, int y) {
    vector<pair<int,int> > wall; 
    queue<pair<int,int> > Q ; 
    Q.push(make_pair(x, y)) ; 

    visited[y][x] = true ; 
    int cnt = 1 ; 
    while (!Q.empty()) { 
        int curr_x = Q.front().first ; 
        int curr_y = Q.front().second ;  
        Q.pop() ;

        for (int i = 0 ; i < 4; i++) {
            int dir_x = curr_x + dx[i] ; 
            int dir_y = curr_y + dy[i] ; 
            
            if ( dir_x < 0 || dir_x >= M || dir_y < 0 || dir_y >= N) continue ; 

            if ( MAP[dir_y][dir_x] == 0 && !visited[dir_y][dir_x]) { 
                visited[dir_y][dir_x] = true;  
                Q.push(make_pair(dir_x, dir_y)) ; 
                cnt++; 
            } else if ( MAP[dir_y][dir_x] == 1 && !visitedWall[dir_y][dir_x] ) { 
                visitedWall[dir_y][dir_x] = true ; 
                wall.push_back(make_pair(dir_x, dir_y)) ; 
            }
        }
    } 

    for (int i = 0 ; i < wall.size(); i++) { 
        int x = wall[i].first ; 
        int y = wall[i].second ; 
        value[y][x] += cnt ; 
    }
}

void Solution() { 
    for(int i = 0 ; i < N ;i++) { 
        for(int j = 0 ; j < M; j++) {
            if ( MAP[i][j] == 0 && !visited[i][j]) { 
                memset(visitedWall, false, sizeof(visitedWall)) ;
                BFS(j, i); 
            }
        }
    }
    for (int i = 0 ; i < N ;i++) {
        for (int j = 0 ; j < M ; j++) {
            cout << value[i][j] % 10; 
        }
        cout << '\n';
    }
}

void Input() { 
    cin >> N >> M ; 

    for (int i = 0 ; i < N ; i++) { 
        string s ;
        cin >> s ; 
        for (int j = 0 ; j < M; j++) { 
            value[i][j] = MAP[i][j] = s[j] - '0'; 
        }
    }
}

int main(void) { 
    ios::sync_with_stdio(false) ; 
    cin.tie(0); 

    Input() ; 
    Solution(); 

    return 0 ;
}