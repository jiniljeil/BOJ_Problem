#include <iostream>
#include <queue> 
#include <algorithm> 
using namespace std;

int map[101][101]; 
int value[101][101]; 
bool visited[101][101]; 
int M, N, K; 

int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0 ,1 , 0, -1} ;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    
    cin >> M >> N >> K ;  

    for(int i = 0 ; i < K ; i++){
        int x1,y1,x2,y2; 
        cin >> x1 >> y1 >> x2 >> y2; 

        for(int j = y1; j < y2; j++){
            for(int k = x1; k < x2; k++){
                map[j][k] += 1; 
            }
        }
    }
    vector<int> result ; 
    int divide = 0 ;
    for(int i = 0 ;i < M; i++){
        for(int j = 0 ; j < N; j++){
            if( map[i][j] == 0 && !visited[i][j]){
                int c = 0 ; 
                value[i][j] = 1; 
                queue< pair<int,int> > q ; 
                q.push(make_pair(j,i));
                visited[i][j] = true;
                while(!q.empty()){
                    int curr_x = q.front().first; 
                    int curr_y = q.front().second; 
                    c++ ;
                    q.pop(); 

                    for(int k = 0 ; k < 4 ;k++){
                        int dir_x = curr_x + dx[k]; 
                        int dir_y = curr_y + dy[k]; 

                        if( dir_x >= 0 && dir_x < N && dir_y >= 0 && dir_y < M) { 
                            if( !visited[dir_y][dir_x] && map[dir_y][dir_x] == 0 ){
                                visited[dir_y][dir_x] = true; 
                                q.push(make_pair(dir_x,dir_y));  
                            }
                        }
                    }
                }  
                result.push_back(c); 
                divide++; 
            }
        }
    }
    sort(result.begin(), result.end());
    cout << divide << "\n"; 
    for(int i = 0 ; i < result.size(); i++){
        cout << result[i] << " "; 
    }
}