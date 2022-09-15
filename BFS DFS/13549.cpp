#include <iostream> 
#include <queue> 
#define MAX 100001 
using namespace std ;

int N, K ; 
int MAP[MAX] ; 
queue<pair<int, int> > Q ; 
int dx[3] = {2, -1, 1} ; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N >> K ;

    MAP[N] = 1 ; 
    Q.push(make_pair(N, 0)) ; 
    
    while (!Q.empty()) { 
        pair<int,int> curr = Q.front(); Q.pop() ;

        if ( curr.first == K ) { cout << curr.second << '\n'; break ;}

        for (int i = 0 ; i < 3; i++) { 
            if ( i == 0 ) { 
                int nx = curr.first * dx[i] ; 
                if ( nx < 0 || nx >= MAX || MAP[nx] != 0 ) continue ;
                MAP[nx] = MAP[curr.first] ; 
                Q.push(make_pair(nx, curr.second)) ; 
            } else {
                int nx = curr.first + dx[i] ; 
                if ( nx < 0 || nx >= MAX || MAP[nx] != 0 ) continue ;
                MAP[nx] = MAP[curr.first] + 1 ; 
                Q.push(make_pair(nx, curr.second + 1)) ; 
            }
        }
    }

    return 0; 
}