#include <iostream> 
#include <queue> 
#include <string.h> 
#include <math.h> 
#include <vector> 

using namespace std; 

int dx[4] = { 1, 0, -1, 0}; 
int dy[4] = { 0, 1, 0, -1}; 
int N, L, R ;
int arr[51][51]; 
int result = 0 ; 
bool visited[51][51] ;
int sum, num; 
queue<pair<int,int> > location ; 
void DFS(int curr_y, int curr_x) { 
    for (int i = 0 ; i < 4 ; i++) {
        int next_y = curr_y + dy[i] ; 
        int next_x = curr_x + dx[i] ; 

        if ( next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) continue; 

        int gap = abs(arr[next_y][next_x] - arr[curr_y][curr_x]); 

        if (!visited[next_y][next_x] && gap >= L && gap <= R) { 
            visited[next_y][next_x] = true; 
            location.push(make_pair(next_y, next_x)) ;
            sum += arr[next_y][next_x]; 
            num += 1; 
            DFS(next_y, next_x); 
        }
    }
}
int main(void) { 
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> N >> L >> R ; 

    for (int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < N ;j++) {
            cin >> arr[i][j]; 
        }
    }

    while (1)  {
        bool check = false; 
        memset(visited, false, sizeof(visited)); 

        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < N ; j++) {
                if (visited[i][j]) continue; 
                sum = arr[i][j]; num = 1 ; 
                while(!location.empty()) location.pop();
                location.push(make_pair(i, j)) ;
                visited[i][j] = true; 
                DFS(i, j) ;
                if ( num >= 2 ) {
                    if (!check) check = true; 
                    while(!location.empty()) {
                        int y = location.front().first;  
                        int x = location.front().second ;
                        location.pop(); 
                        arr[y][x] = sum / num ; 
                    }
                }
            }
        }

        if(!check) break; 
        else result++; 
    }   
    cout << result << '\n'; 
    return 0;
}