#include <iostream>
#include <queue> 
#include <string.h> 
using namespace std; 

int arr[100001], visited[100001] ;
bool cycle[100001]; 
int T, n ; 

// visited (-1: 더 이상 방문X, 0: 아직 방문 X, 1: 방문 중)
void DFS(int x, int &c){ // Find Cycle 
    if( cycle[x] || visited[x] == -1){
        return ; 
    } 
    if( visited[x] == 0) { 
        visited[x] = 1; 
    }else if( visited[x] == 1 ){
        cycle[x] = true; 
        c++; 
    }
    DFS(arr[x], c); 
    visited[x] = -1 ;
}
int main(void){
    ios::sync_with_stdio(false) ; 
    cin.tie(NULL); 
    cout.tie(NULL); 

    cin >> T ; 
    for(int i = 0 ; i < T ; i++){
        cin >> n ; 
        int c = 0 ;

        for(int j = 1 ; j <= n; j++) {
            cin >> arr[j] ; 
        }
        for(int j = 1 ; j <= n; j++){
            if( !visited[arr[j]] ){
                DFS(j, c); 
            }
        }
        cout << n - c << "\n";

        for(int i = 1 ; i <= n; i++){
            arr[i] = 0 ;
            visited[i] = 0 ; 
            cycle[i] = 0 ;
        }
    }

    return 0; 
}

/*
6
2 3 4 5 6 2
output : 1

5
2 5 4 5 2
output : 3

6
1 3 4 3 2 6
output : 2

13
2 4 5 2 4 1 8 9 10 11 9 10 10
output : 8

10
2 5 7 1 6 8 8 3 5 10
output : 6

10
2 7 10 5 3 3 9 10 6 3
output : 8

6
2 1 1 2 6 3
output : 4
*/
