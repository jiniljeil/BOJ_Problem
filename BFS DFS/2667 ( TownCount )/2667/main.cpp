#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void HouseCount(vector<vector<int>> map, vector<vector<int>> check , int size){
    int curr_x = 0 , curr_y = 0;
    int c = 0 ; // house count
    const int ec = 0 ; // each house count
    vector<int> count ;
    queue<int> x_point ;
    queue<int> y_point ;
    
    for(int i = 0 ; i < size; i++){
        for(int j = 0 ; j <size ; j++){
            if (map[i][j] == 1){
                curr_y = i;
                curr_x = j;
                count.push_back(ec+1);
                check[curr_y][curr_x] = 1;
                map[curr_y][curr_x] = 0;
                x_point.push(curr_x);
                y_point.push(curr_y);
                while(!x_point.empty() && !y_point.empty()){
                    curr_x = x_point.front();
                    curr_y = y_point.front();
                    x_point.pop();
                    y_point.pop();
                    
                    for(int i = 0 ;i < 4; i++){
                        int dir_x = curr_x + dir[i][0];
                        int dir_y = curr_y + dir[i][1];
                        
                        if(dir_x >= 0 && dir_x < size && dir_y >= 0 && dir_y < size
                           && map[dir_y][dir_x] == 1 && check[dir_y][dir_x] == 0) {
                            check[dir_y][dir_x] = check[curr_y][curr_x] + 1 ;
                            map[dir_y][dir_x] = 0 ;
                            count[c]++;
                            x_point.push(dir_x);
                            y_point.push(dir_y);
                        }
                    }
                }
                c++;
            }
        }
    }
    cout << c << endl; // town count
    sort(count.begin(),count.end());
    for(int i = 0; i < count.size(); i++){
        cout << count[i] << endl;
    }
}

int main(void){
    int size = 0;
    scanf("%d", &size);
    
    vector<vector<int>> map (size, vector<int> (size, 0));
    vector<vector<int>> check (size, vector<int> (size, 0));
    
    for(int i = 0 ; i < size; i++){
        for(int j = 0 ; j <size; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    HouseCount(map,check, size);
    
    return 0;
}
