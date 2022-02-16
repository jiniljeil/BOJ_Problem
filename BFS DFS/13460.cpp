#include <iostream> 
#include <queue> 
#include <cstring> 
#define MAX 11 
#define L 1 
#define U 2 
#define R 3 
#define D 4 
using namespace std ; 

int N, M; 
char MAP[MAX][MAX]; 
bool visited[MAX][MAX]; 
int value[MAX][MAX] ; 
pair<int,int> Red, Blue, Hole; 
int dx[4] = {-1, 0, 1, 0} ; 
int dy[4] = { 0, 1, 0,-1} ; 

int point_to_dir(int d) { 
    if ( d == 0 ) return L  ;
    else if ( d == 1 ) return U ; 
    else if ( d == 2 ) return R ; 
    else if ( d == 3 ) return D ;  
    return 0; 
}

int BFS(int y, int x)  {
    // < <LURD, Count>, <x, y> >
    queue<pair<pair<int,int>, pair<int,int> > > Q; 
    Q.push(make_pair(make_pair(0, 0), make_pair(x,y))); 
    visited[y][x] = true; 
    value[y][x] = 0; 
    while(!Q.empty()) { 
        int Direction = Q.front().first.first ; 
        int Count = Q.front().first.second ; 
        int curr_x = Q.front().second.first; 
        int curr_y = Q.front().second.second ; 

        Q.pop(); 

        if ( Count == 10 ) return -1;  
        // if ( curr_y == Hole.first && curr_x == Hole.second ) return Count ; 

        for (int i = 0 ; i < 4 ; i++) { 
            int dir_x = curr_x + dx[i] ; 
            int dir_y = curr_y + dy[i] ; 
            
            if (dir_x < 0 || dir_x >= M || dir_y < 0 || dir_y >= N ) continue ; 
            if ( MAP[dir_y][dir_x] == '.' && value[dir_y][dir_x] == -1 ) { 
                // visited[dir_y][dir_x] = true ; 
                if ( Direction == point_to_dir(i) ) { 
                    value[dir_y][dir_x] = value[curr_y][curr_x] ; 
                    Q.push(make_pair(make_pair(point_to_dir(i), Count), make_pair(dir_x, dir_y))) ; 
                } else { 
                    value[dir_y][dir_x] = value[curr_y][curr_x] + 1; 
                    Q.push(make_pair(make_pair(point_to_dir(i), Count + 1), make_pair(dir_x, dir_y))) ; 
                }
            } 
            else if ( MAP[dir_y][dir_x] == 'O') { 
                if ( Direction == point_to_dir(i) ) { 
                    value[dir_y][dir_x] = value[curr_y][curr_x] ; 
                    return Count ; 
                } else{ 
                    value[dir_y][dir_x] = value[curr_y][curr_x] + 1 ; 
                    return Count + 1; 
                }
            }
        }
    }
    return -1 ; 
}

void Input() { 
    cin >> N >> M ; 
    for (int i = 0 ; i < N ; i++) { 
        string s ; 
        cin >> s ; 
        for (int j = 0 ; j < M ; j++) {
            MAP[i][j] = s[j] ; 

            if ( MAP[i][j] == 'R') { 
                Red = make_pair(i, j) ;
            } else if ( MAP[i][j] == 'B') { 
                Blue = make_pair(i, j) ; 
            } else if ( MAP[i][j] == 'O') {
                Hole = make_pair(i, j) ; 
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0);

    Input(); 
    memset(value, -1, sizeof(value)) ; 
    // memset(visited, false, sizeof(visited)) ; 
    int hole_a = BFS(Red.first, Red.second) ; 

    for (int i = 0 ; i < N; i++) {
        for (int j = 0 ; j < M; j++) { 
            cout << value[i][j] << ' '; 
        }
        cout << '\n';
    }
    cout << hole_a << '\n';

    memset(value, -1, sizeof(value)) ; 
    // memset(visited, false, sizeof(visited)) ; 
    int hole_b = BFS(Blue.first, Blue.second) ;

    for (int i = 0 ; i < N; i++) {
        for (int j = 0 ; j < M; j++) { 
            cout << value[i][j] << ' '; 
        }
        cout << '\n';
    }
    cout << hole_b << '\n';

    if ( hole_a == -1 ) { 
        cout << -1 << '\n'; 
    } else { 
        if ( hole_a == hole_b ) { 
            cout << -1 << '\n'; 
        } else if ( hole_a < hole_b ) { 
            cout << hole_a << '\n'; 
        }
    }
    return 0 ;
}