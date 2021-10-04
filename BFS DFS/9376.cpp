#include <iostream> 
#include <queue> 
#include <vector> 
#include <string> 
#include <string.h> 
#define MAX 102 
#define INF 1e9
using namespace std; 

int dx[4] = {-1, 0, 1, 0} ;
int dy[4] = { 0, -1,0, 1} ; 
int testcase; 
int row, col ; 
int value[3][MAX][MAX] ; 
pair<int,int> person[3]; 

// BFS (상근이, 죄수1, 죄수2) ;
void BFS(char MAP[MAX][MAX]) { 
    priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, greater<pair<int, pair<int,int> > > >Q; 

    for (int i = 0 ; i < 3 ; i++) {
        for (int a = 0 ; a <= row+1 ; a++) {
            for(int b = 0 ;b <= col+1; b++) {
                value[i][a][b] = INT32_MAX ;
            }
        }
        pair<int,int> curr = person[i]; 
        Q.push(make_pair(0, curr)) ; 

        value[i][curr.first][curr.second] = 0 ; 
        while (!Q.empty()) {
            int curr_d = Q.top().first ; 
            int curr_y = Q.top().second.first ; 
            int curr_x = Q.top().second.second ; 
            Q.pop() ; 

            if (value[i][curr_y][curr_x] < curr_d) continue; 

            for (int k = 0 ; k < 4; k++) {
                int dir_y = curr_y + dy[k] ;
                int dir_x = curr_x + dx[k] ; 

                if ( dir_x < 0 || dir_x > col + 1 || dir_y < 0 || dir_y > row + 1 ) continue; 
                if ( MAP[dir_y][dir_x] == '*') continue; 
                int d = curr_d; 
                if (MAP[dir_y][dir_x] == '#') { 
                    d++; 
                }
                if ( value[i][dir_y][dir_x] > d) { 
                    value[i][dir_y][dir_x] = d ; 
                    Q.push(make_pair(d, make_pair(dir_y,dir_x)));
                }
            } 
        }
    }
}

void MinOpenDoor(char MAP[MAX][MAX]) { 
    long long result = INT32_MAX ; 
    for (int i = 0 ; i <= row + 1 ; i++) {
        for(int j = 0 ; j <= col + 1 ; j++) {
            if ( MAP[i][j] == '*' ) continue; 
            long long point = value[0][i][j] + value[1][i][j] + value[2][i][j] ;

            if ( MAP[i][j] == '#') { 
                point -= 2;  
            }
            result = min(result, point) ;
        }
    }

    cout << result << '\n';
}
int main(void) { 
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    int testcase = 0 ;
    cin >> testcase; 
    while(testcase--) { 
        char MAP[MAX][MAX] ;   
        cin >> row >> col ; 

        string s ; 
        int idx = 0 ;
        person[idx] = pair<int,int>(0,0);
        for (int i = 1; i <= row ; i++) {
            cin >> s ;
            s = '.' + s + '.'; 
            for (int j = 0 ; j <= col + 1; j++) {
                MAP[i][j] = s[j] ; 
                if (MAP[i][j] == '$') {
                    person[idx++] = pair<int,int>(i,j);
                }
            }
        }

        for (int i = 0; i <= col + 1; i++) {
            MAP[0][i] = '.' ;
            MAP[row + 1][i] = '.'; 
        }
        BFS(MAP); 
        MinOpenDoor(MAP) ;
    }   
    return 0;   
}