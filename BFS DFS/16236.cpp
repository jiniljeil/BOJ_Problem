#include <iostream> 
#include <queue> 
#include <cstring>
using namespace std ;

typedef struct FishStruct { 
    int x, y, d ; 
    bool operator<(const FishStruct &b) const {
        if ( d == b.d ) { 
            if ( y == b.y ) return x > b.x ; 
            else return y > b.y ; 
        } else return d > b.d ; 
    }
} FISH ; 

typedef struct SharkStruct { 
    int x, y, eat, size ; 
} SHARK ; 

int N ; 
int MAP[21][21] ; 
bool visited[21][21] ; 
SHARK shark ; 
queue<FISH> Q ; 
int dy[4] = {-1, 0,1, 0} ;
int dx[4] = {0,-1, 0, 1} ;
int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 

    cin >> N ; 

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) { 
            cin >> MAP[i][j] ; 
            if ( MAP[i][j] == 9 ) { 
                MAP[i][j] = 0 ; 
                shark.y = i ; shark.x = j ; 
            }
        }
    } 

    shark.eat = 0 ; shark.size = 2 ; 
    int answer = 0 ; 

    FISH start = {shark.x, shark.y, 0} ;
    Q.push(start) ; 
    visited[shark.y][shark.x] = true ;

    while (1) { 
        for (int i = 0 ; i < N ; i++) for (int j = 0 ; j < N ; j++) visited[i][j] = false ; 
        priority_queue<FISH> candidates ; 
        
        while (!Q.empty()) { 
            FISH curr = Q.front() ; Q.pop() ; 

            for (int k = 0 ; k < 4 ; k++) {
                int nx = curr.x + dx[k] ; 
                int ny = curr.y + dy[k] ; 

                if ( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue ; 
                if ( visited[ny][nx] || MAP[ny][nx] > shark.size ) continue ;
                
                FISH next = {nx, ny, curr.d + 1} ; 
                visited[ny][nx] = true ; 
                Q.push(next) ;
                
                if ( MAP[ny][nx] != 0 && shark.size > MAP[ny][nx] ) { 
                    candidates.push(next); 
                }
            }
        }

        if ( candidates.size() > 0 ) { 
            FISH fish = candidates.top() ; 
            shark.eat++; 
            if ( shark.eat == shark.size ) { 
                shark.eat = 0 ;
                shark.size++; 
            }

            MAP[fish.y][fish.x] = 0 ; 

            FISH next = {fish.x, fish.y, 0} ;
            visited[next.y][next.x] = true ;
            Q.push(next) ; 
            answer += fish.d ;
        } else { 
            break ;
        }
        
    }

    cout << answer << '\n'; 
    return 0 ;
}