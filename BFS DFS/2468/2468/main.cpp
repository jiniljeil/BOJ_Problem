#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int check[101][101];
bool visit[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(int size){
    int count = 0 ;
    
    
    for(int i = 0 ; i < size; i++){
        for(int j = 0 ;j < size; j++){
            if( check[i][j] == 1){
                queue<pair<int,int>> queue ;
                queue.push({j,i});
                
                while(!queue.empty()){
                    int curr_x = queue.front().first ;
                    int curr_y = queue.front().second ;
                    check[curr_y][curr_x] = 0;
                    queue.pop();
                    for(int k = 0; k < 4; k++){
                        int dir_x = curr_x + dx[k];
                        int dir_y = curr_y + dy[k];
                        
                        if( (dir_x >= 0 && dir_x < size) && (dir_y >= 0 && dir_y < size)
                           && (check[dir_y][dir_x] == 1) && (!visit[dir_y][dir_x])){
                            visit[dir_y][dir_x] = true;
//                            check[dir_y][dir_x] = 0;
                            queue.push({dir_x,dir_y});
                        }
                    }
                }
                count++;
            }
        }
    }
    return count;
}
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    int max = 0 , region = 0 ;
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < n ;j++){
            if( j == n - 1 ){
                scanf("%d",&map[i][j]);
            }else{
                scanf("%d ",&map[i][j]);
            }
            if(map[i][j] > max){
                max = map[i][j];
            }
        }
    }
    
    for(int i = 0 ; i < max ; i++){
        for(int j = 0 ; j < n ;j++){ // 초기화
            for(int k = 0 ; k < n; k++){
                check[j][k] = 0 ;
                visit[j][k] = false;
            }
        }
        
        for(int j = 0 ; j < n ;j++){
            for(int k = 0 ; k < n; k++){
                if(map[j][k] > i){
                    check[j][k] = 1;
                }
            }
        }
        
        // print
//        printf("TEST %d\n",i);
//        for(int j = 0 ; j < n ; j++){
//            for(int k = 0 ; k < n; k++){
//                printf("%d ",check[j][k]);
//            }
//            printf("\n");
//        }
        
        int tmp = BFS(n);
        if( tmp > region){
            region = tmp ;
        }
    }
    
    printf("%d\n",region);
    return 0;
}
