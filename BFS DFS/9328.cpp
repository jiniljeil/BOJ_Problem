#include <iostream>
#include <cstdlib> 
#include <cstring>
#include <queue> 
#define MAX 102
using namespace std; 

int T, N, M ;
char MAP[MAX][MAX] ;
bool visited[MAX][MAX] ;   
string key ; 
int result = 0 ; 

int dx[4] = {-1, 0, 1, 0} ; 
int dy[4] = { 0, 1, 0,-1} ; 
void Input() {
    string s ; 
    memset(MAP, '0', sizeof(MAP)); 

    cin >> N >> M ; 

    for (int i = 0 ; i <= M + 1; i++) {
        MAP[0][i] = MAP[N + 1][i] = '.' ;
    }
    for (int i = 1 ; i <= N; i++) {
        MAP[i][0] = '.'; 
        cin >> s ; 
        for (int j = 1 ; j <= M ; j++) {
            MAP[i][j] = s[j - 1] ; 
        }
        MAP[i][M + 1] = '.' ; 
    }
    
    cin >> key ; 
}

void Solve() { 
    memset(visited, false, sizeof(visited)) ;

    queue<pair<int, int> > Q ; 
    Q.push(make_pair(0, 0)); // x, y  
    visited[0][0] = true ; 

    while(!Q.empty()) {
        int curr_x = Q.front().first; 
        int curr_y = Q.front().second ; 
        Q.pop() ;

        for (int k = 0 ; k < 4 ; k++) {
            int dir_x = curr_x + dx[k] ; 
            int dir_y = curr_y + dy[k] ; 
                
            if ( dir_x < 0 || dir_x > M + 1 || dir_y < 0 || dir_y > N + 1) continue; 
            if ( visited[dir_y][dir_x] != false ) continue ; 
            
            if ( MAP[dir_y][dir_x] == '.') { 
                visited[dir_y][dir_x] = true ; 
                Q.push(make_pair(dir_x,dir_y)) ;
            }
            // 문서
            if ( MAP[dir_y][dir_x] == '$') {
                MAP[dir_y][dir_x] = '.' ; 
                visited[dir_y][dir_x] = true;
                Q.push(make_pair(dir_x, dir_y)) ; 
                result++ ; 
            }
            // 소문자 (키)
            if ( MAP[dir_y][dir_x] >= 'a' && MAP[dir_y][dir_x] <= 'z') { 
                key += MAP[dir_y][dir_x] ; 
                MAP[dir_y][dir_x] = '.' ; 
                memset(visited, false, sizeof(visited)) ; // 초기화 
                while(!Q.empty()) { Q.pop(); }
                visited[dir_y][dir_x] = true ; 
                Q.push(make_pair(dir_x,dir_y)); 
            }
                // 대문자 (문)
            if ( MAP[dir_y][dir_x] >= 'A' && MAP[dir_y][dir_x] <= 'Z') { 
                int found ; 
                if ( (found = key.find(MAP[dir_y][dir_x] + 32)) != string::npos ){
                    MAP[dir_y][dir_x] = '.' ; 
                    visited[dir_y][dir_x] = true ; 
                    Q.push(make_pair(dir_x, dir_y)) ; 
                } 
            }
        }
    }

    cout << result << '\n' ; 
}

int main(void) {
    ios::sync_with_stdio(0) ; 
    cin.tie(0) ; 

    
    cin >> T ; 
    for (int i = 0 ; i < T ; i++) {
        Input() ; 
        Solve() ; 
        result = 0 ;
    }
    
    return 0 ;
}