#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Finder(vector<vector<int>> map, vector<vector<int>> count, int row, int column){
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int curr_x = 0, curr_y = 0;
    
    count[curr_y][curr_x] = 1;
    
    queue<int> x_point;
    queue<int> y_point;
    
    x_point.push(curr_x);
    y_point.push(curr_y);
    
    while(!x_point.empty() && !y_point.empty()) {
        curr_x = x_point.front();
        curr_y = y_point.front();
        
        if(curr_x == column-1 && curr_y == row-1 ){
            break;
        }
        x_point.pop();
        y_point.pop();
        
        for(int i = 0; i < 4 ; i++){
            int dir_x = curr_x + dir[i][0];
            int dir_y = curr_y + dir[i][1];
            
            if((dir_x >= 0 && dir_x < column) && (dir_y >= 0 && dir_y < row)
               && map[dir_y][dir_x] == 1 && count[dir_y][dir_x] == 0){
                count[dir_y][dir_x] = count[curr_y][curr_x] + 1 ;
                x_point.push(dir_x);
                y_point.push(dir_y);
            }
        }
    }
    
    return count[row-1][column-1];
}

int main(void){
    int row, column;
    cin >> row >> column;
    
    vector<vector<int>> map (row, vector<int>(column, 0));
    vector<vector<int>> count (row, vector<int> (column, 0));
    
    for(int i = 0; i < row; i++){
        for(int j = 0 ; j < column; j++){
            scanf("%1d",&map[i][j]);
        }
    }
    
    int value = Finder(map,count,row,column);
    cout << value ;
    
    
    return 0;
}



/*
 
 int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
 int curr_x = 0, curr_y = 0;
 
 count[curr_y][curr_x] = 1;
 
 queue<int> x_point;
 queue<int> y_point;
 
 x_point.push(curr_x);
 y_point.push(curr_y);
 
 while(!x_point.empty() && !y_point.empty()) {
     curr_x = x_point.front();
     curr_y = y_point.front();
     
     if(curr_x == column-1 && curr_y == row-1 ){
         break;
     }
     x_point.pop();
     y_point.pop();
     
     for(int i = 0; i < 4 ; i++){
         int dir_x = curr_x + dir[i][0];
         int dir_y = curr_y + dir[i][1];
         
         if((dir_x >= 0 && dir_x < column) && (dir_y >= 0 && dir_y < row)
            && map[dir_y][dir_x] == 1 && count[dir_y][dir_x] == 0){
             count[dir_y][dir_x] = count[curr_y][curr_x] + 1 ;
             x_point.push(dir_x);
             y_point.push(dir_y);
             for(int i = 0 ; i < row; i++){
                 for(int j = 0 ; j< column ;j++){
                     cout << count[i][j] << " ";
                 }
                 cout << endl;
             }
             cout << endl;
         }
     }
 }
 */
