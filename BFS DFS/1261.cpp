#include <bits/stdc++.h>
#define SIZE 101

using namespace std ;
 
int N, M ; 
int A[SIZE][SIZE] ;
bool visited[SIZE][SIZE] ; 

int dx[4]={-1,0,1,0} ; 
int dy[4]={ 0,1,0,-1} ;
void bfs() { 
    priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, \
        greater<pair<int, pair<int,int> > > > Q; 
    Q.push({0,{0,0}}) ;
    visited[0][0] = true ; 

    int result = INT_MAX ; 
    while ( !Q.empty() ) { 
        int t = Q.top().first ;
        int y = Q.top().second.first; 
        int x = Q.top().second.second  ; 
        Q.pop() ; 

        if ( y == N - 1 && x == M - 1) { 
            cout << t << '\n';
            break ;
        }

        for (int k = 0 ; k < 4 ;k++) { 
            int nx = x + dx[k] ;  
            int ny = y + dy[k] ; 

            if ( nx < 0 || ny < 0 || nx >= M || ny >= N ) continue ; 
            if ( visited[ny][nx] ) continue ; 

            visited[ny][nx] = true;
            if ( A[ny][nx] == 1 ) {
                Q.push({t + 1, {ny, nx}}); 
            } else { 
                Q.push({t, {ny, nx}}); 
            }
            
        }
    }
}

int main() {

    scanf("%d %d",&M, &N) ;  
    for (int i = 0; i < N ; i++ ) {
        for (int j = 0 ; j < M ;j++) { 
            scanf("%1d", &A[i][j]) ;  
        }
    }

    bfs();
    return 0; 
}