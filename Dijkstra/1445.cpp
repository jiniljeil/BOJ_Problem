#include <iostream> 
#include <string> 
#include <vector>
#include <queue> 
#include <climits>
#define INF INT_MAX
using namespace std ;
typedef pair<int, int> pi ;

int map[51][51] ; 
int N, M ;
pi startPoint, endPoint ;
vector<pi> trash ;
long long int value[51][51]; 

int dx[4] = {-1, 0, 1, 0} ; 
int dy[4] = { 0,-1, 0, 1} ;

typedef struct info { 
    long long int num_of_trash ; 
    pi point; 
} INFO ;

struct compare {
    bool operator() (const INFO &a, const INFO &b) { 
        return a.num_of_trash > b.num_of_trash ; 
    }
}; 

priority_queue<INFO, vector<INFO>, compare > pq ; 

void dijkstra() { 
    pq.push({0, startPoint}) ;
    
    while (!pq.empty()) { 
        int nt = pq.top().num_of_trash ; 
        int y = pq.top().point.first ;
        int x = pq.top().point.second ;
        pq.pop() ; 

        if ( endPoint.first == y && endPoint.second == x ) { 
            cout << value[y][x] / 100000 << ' ' << value[y][x] % 100000 << '\n';
        }

        for (int k = 0 ; k < 4; k++) {
            int nx = x + dx[k] ;
            int ny = y + dy[k] ; 
            
            int ntt = nt ;
            if ( nx < 0 || ny < 0 || nx >= M || ny >= N) continue ;     
            if ( map[ny][nx] == 2 ) { 
                ntt += 100000 ;
            } else if ( map[ny][nx] == 1 ) { 
                ntt += 1 ; 
            }

            if (value[ny][nx] > ntt) {
                value[ny][nx] = ntt; 
                pq.push({ntt, {ny, nx}}) ; 
            }
        }
    }
}

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0); 

    
    cin >> N >> M ; 
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) { 
            value[i][j] = INF ; 
        }
    }

    for (int i = 0 ; i < N ; i++) { 
        string s ; cin >> s ;
        for (int j =0 ; j < M ; j++) { 
            if ( s[j] == 'S') { startPoint = {i, j}; } 
            else if ( s[j] == 'F') { endPoint = {i, j}; } 
            else if ( s[j] == 'g' ) { map[i][j] = 2 ; trash.push_back({i, j}) ;}
        } 
    }

    for (int i = 0 ; i < trash.size() ;i++) { 
        int y = trash[i].first ; 
        int x = trash[i].second ; 

        for (int k = 0 ; k < 4; k++) { 
            int nx = x + dx[k]; 
            int ny = y + dy[k]; 
            if ( nx < 0 || ny < 0 || nx >= M || ny >= N ) continue ;
            if ( map[ny][nx] ) continue ; // 이미 g가 있는 경우
            map[ny][nx] = 1 ; 
        }
    }

    map[startPoint.first][startPoint.second] = 0 ;
    map[endPoint.first][endPoint.second] = 0 ;

    dijkstra() ; 

    return 0; 
}