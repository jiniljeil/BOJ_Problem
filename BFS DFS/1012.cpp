#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int numofG(vector<vector<int>> ground, int row ,int column){
    int count = 0;
    vector<vector<int>> check (row,vector<int>(column, 0));
    
    
    for(int i = 0 ; i < row; i++){
        for(int j = 0 ;j < column; j++){
            if(ground[i][j] == 1){
                queue<pair<int,int>> point;
                int curr_x = j, curr_y = i;
                ground[curr_y][curr_x] = 0 ;
                point.push(make_pair(curr_x, curr_y));
                
                while(!point.empty()){
                    curr_x = point.front().first;
                    curr_y = point.front().second;
                    
                    point.pop();
                    for(int z = 0 ; z < 4 ; z++){
                        
                        int dir_x = curr_x + dir[z][0];
                        int dir_y = curr_y + dir[z][1];
                        
                        if(dir_y >= 0 && dir_y < row && dir_x >= 0 && dir_x < column
                           && check[dir_y][dir_x] == 0 && ground[dir_y][dir_x] == 1){
                            check[dir_y][dir_x] = 1;
                            ground[dir_y][dir_x] = 0;
                            point.push(make_pair(dir_x, dir_y));
                        }
                    }
                }
                count++;
            }
        }
    }
    
    return count;
}

int main(void){
    int n = 0;
    vector<int> c ;
    scanf("%d",&n);
    
    for(int i = 0 ; i < n ; i++){
        int row, column;
        scanf("%d %d",&column, &row);
        
        vector<vector<int>> ground (row, vector<int>(column ,0));
        
        int numBaechu;
        scanf("%d",&numBaechu);
        
        for(int j = 0; j < numBaechu; j++){
            int k1,k2 ;
            scanf("%d %d",&k1,&k2);
            if(k1 >= 0 && k1 < column && k2 >= 0 && k2 < row){
                ground[k2][k1] = 1;
            }
        }
        
        int count = numofG(ground, row, column);
        c.push_back(count);
    }
    
    for(int i = 0 ; i < c.size(); i++){
        cout << c[i] << endl;
    }
    
    return 0;
}
