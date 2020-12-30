#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{1,-1},{1,1},{-1,1}};

int search_island(vector < vector< int > >chart , int n1, int n2);
void search(vector < vector < int > >& chart , int n1, int n2, int x, int y );

int main(void){
    int num1 = 1;
    int num2 = 1;
    vector<int> count ;
    
    while(!(num1 == 0 && num2 == 0)){
        cin >> num1 >> num2 ;
        int temp = num1;
        num1 = num2;
        num2 = temp;
        
        vector < vector < int > > chart ( num1 ,  vector < int > (num2,0));
        
        for(int i = 0 ;i < num1; i++){
            for(int j = 0; j < num2; j++){
                cin >> chart [i][j];
            }
        }

        int c = search_island(chart, num1, num2);
        count.push_back(c);
        
        for(int i = 0 ; i < num1; i++){
            chart[i].clear();
        }
        chart.clear();
    };
    
    for(int i = 0 ; i < count.size() -1; i++){
        cout << count[i] << endl;
    }
    
}

int search_island(vector < vector< int > > chart, int row, int column ){ // row , column
    vector<vector<bool>> check (row, vector<bool> (column, false));
    int count = 0 ;
    
    for(int i = 0 ;i < chart.size(); i++){
        for(int j = 0 ; j < chart[i].size(); j++){
            if(chart[i][j] == 1){
                int curr_x = j ;
                int curr_y = i ;
                
                queue<int> x_point ;
                queue<int> y_point ;
                
                x_point.push(curr_x);
                y_point.push(curr_y);
                
                while(!x_point.empty() && !y_point.empty()){
                    curr_x = x_point.front();
                    curr_y = y_point.front();
                    
                    x_point.pop();
                    y_point.pop();
                    
                    chart[curr_y][curr_x] = 0;
                    
                    for(int z = 0 ; z < 8; z++){
                        int dir_x = curr_x + dir[z][0];
                        int dir_y = curr_y + dir[z][1];
                        
                        if(dir_x >= 0 && dir_x < column && dir_y >= 0 && dir_y < row
                           && !check[dir_y][dir_x] && chart[dir_y][dir_x] == 1){
                            check[dir_y][dir_x] = true;
                            chart[dir_y][dir_x] = 0;
                            
                            x_point.push(dir_x);
                            y_point.push(dir_y);
                        }
                    }
                }
                
                count++;
            }
        }
    }
    
    
    
    return count;
}

/*
 1 1
 0
 2 2
 0 1
 1 0
 3 2
 1 1 1
 1 1 1
 5 4
 1 0 1 0 0
 1 0 0 0 0
 1 0 1 0 1
 1 0 0 1 0
 5 4
 1 1 1 0 1
 1 0 1 0 1
 1 0 1 0 1
 1 0 1 1 1
 5 5
 1 0 1 0 1
 0 0 0 0 0
 1 0 1 0 1
 0 0 0 0 0
 1 0 1 0 1
 0 0
 */
