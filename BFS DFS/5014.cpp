#include <iostream>
#include <queue>
using namespace std ;

int F,S,G,U,D; 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    queue<pair<int,int> > q; 
    // F: 층수, S: 현재 층, G: 도착 층, U: 업, D: 다운 
    cin >> F >> S >> G >> U >> D ; 
    int *arr = new int[F + 1] ; 
    int *visited = new int[F + 1]; 
    q.push(make_pair(S, 0));
    visited[S] = true; 
    bool check = false; 
    while(!q.empty()) {
        int curr = q.front().first ; 
        int result = q.front().second; 
        q.pop(); 

        if( curr == G) { 
            check = true; 
            cout << result << "\n";
            break;
        }
        if( curr + U <= F && !visited[curr + U]) { 
            visited[curr+U] = true ; 
            q.push(make_pair(curr + U, result + 1)) ;
        }
        if( curr-D >= 1 && !visited[curr - D]) {
            visited[curr-D] = true; 
            q.push(make_pair(curr - D, result + 1));
        }
    }
    free(arr);
    free(visited);
    if( !check ) {
        cout << "use the stairs" << "\n";
    }
    return 0;
}