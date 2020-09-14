#include <iostream>
#include <queue>

using namespace std;

int row, column, unitRow, unitCol, blockNum ;
int start_x,start_y,end_x,end_y;
int **Map , **countPath;

int dfs(){
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int curr_x = start_x, curr_y = start_y ;
    
    countPath[curr_y][curr_x] = 1;
    
    queue<int> x_point;
    queue<int> y_point;
    
    x_point.push(curr_x);
    y_point.push(curr_y);
    
    while(!x_point.empty() && ! y_point.empty()){
        curr_x = x_point.front() ;
        curr_y = y_point.front() ;
        
        if(curr_x == end_x && curr_y == end_y ){
            break;
        }
        x_point.pop();
        y_point.pop();
        
        for(int k = 0 ; k < 4 ;k++){
            bool check = true;
            int dir_x = curr_x + dir[k][0];
            int dir_y = curr_y + dir[k][1];
            
            // 갈 수 있는 길 인지 확인
            for(int i = 0 ; i < unitRow; i++){
                for(int j = 0 ; j < unitCol; j++){
                    int check_x = j + curr_x + dir[k][0];
                    int check_y = i + curr_y + dir[k][1];
                    
                    if((check_x >= 1 && check_x < column+1) && (check_y >= 1 && check_y < row+1)){
                        if(Map[check_y][check_x] == 1){
                            check = false;
                            break;
                        }
                    }else{
                        check = false;
                        break;
                    }
                }
                if(!check){
                    break;
                }
            }
            if(check && countPath[dir_y][dir_x] == 0){
                countPath[dir_y][dir_x] = countPath[curr_y][curr_x] + 1;
                x_point.push(dir_x);
                y_point.push(dir_y);
            }
        }
    }
    
    return countPath[end_y][end_x] -1;
}

int main(void){
    
    scanf("%d %d %d %d %d", &row, &column, &unitRow, &unitCol, &blockNum);
    Map = new int*[row+1];
    countPath = new int*[row+1];
    for(int i = 0 ; i < row + 1 ;i++){
        Map[i] = new int[column+1];
        countPath[i] = new int[column+1];
    }
    
    for(int i = 0 ; i < row + 1; i++){
        for(int j = 0 ; j <column + 1; j++){
            Map[i][j] = 0;
            countPath[i][j] = 0;
        }
    }
    for(int i = 0 ; i < blockNum; i++){
        int t1 = 0, t2 = 0;
        scanf("%d %d",&t1,&t2);
        
        Map[t1][t2] = 1; // block
    }
    
    scanf("%d %d",&start_y,&start_x);
    scanf("%d %d",&end_y,&end_x);
    
    int result = dfs();
    cout << result << endl ;
    
    for(int i = 0 ; i < row + 1; i++){
        delete [] Map[i];
        delete [] countPath[i];
    }
    delete [] Map;
    delete [] countPath;
    return 0;
}
