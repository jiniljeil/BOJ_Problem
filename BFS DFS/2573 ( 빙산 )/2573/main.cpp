#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int dir_A[8][2] = {{-1,0},{-1,-1},{0,1},{1,-1},{1,0},{1,1},{0,-1},{-1,1}};
int pre_island;
bool ch ;
bool check(vector< vector<int> > c_map, int row, int column){
    bool check = false;
    
    for(int i = 0 ; i < row; i++){
        for(int j = 0 ; j< column ; j++){
            if(c_map[i][j] > 0){
                check = true;
            }
        }
    }
    if(pre_island == 1 && !check){
        ch = true;
    }
    if(!check){
        return false;
    }
    
    
    vector< vector<bool> > visit (row, vector<bool> (column, false ));
    int island = 0;
    
    for(int i = 0 ; i < row; i++){
        for(int j = 0 ;j < column ;j++){
            if(c_map[i][j] > 0 ){
                int curr_x = j ;
                int curr_y = i;
                queue<pair<int,int>> point;
                visit[curr_y][curr_x] = true;
                point.push(make_pair(curr_x,curr_y));
                
                while(!point.empty()){
                    curr_x = point.front().first;
                    curr_y = point.front().second;
                    point.pop();
                    for(int z = 0 ; z < 8 ; z++){
                        int dir_x = curr_x + dir_A[z][0];
                        int dir_y = curr_y + dir_A[z][1];
                        
                        if(dir_x >= 0 && dir_x < column && dir_y >= 0 && dir_y < row
                           && !visit[dir_y][dir_x] && c_map[dir_y][dir_x] > 0){
                            visit[dir_y][dir_x] = true;
                            c_map[dir_y][dir_x] = 0;
                            point.push(make_pair(dir_x, dir_y));
                        }
                    }
                }
                island++;
            }
        }
    }
    
    for(int i = 0 ; i < row; i++){
        visit[i].clear();
    }
    visit.clear();
    
    pre_island = island;
//    cout << island << endl;
    if(island < 2){
        return true;
    }
    return false;
}

int count_year(vector< vector<int> > map, int row, int column){
    
    int year = 0 ;
    
    vector< vector<int> > copy_map (row, vector<int>(column, 0));

    while(check(map, row, column)){
        for(int i =  0 ; i < row; i++){
            for(int j = 0 ; j < column ; j++){
                copy_map[i][j] = map[i][j];
            }
        }
        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < column; j++){
                if(copy_map[i][j] != 0){
                    int c = 0;
                    for(int k = 0 ; k < 4 ; k++){
                        if( i+ dir[k][1] >= 0 && i + dir[k][1] < row &&
                           j + dir[k][0] >= 0 && j + dir[k][0] < column &&
                            copy_map[i + dir[k][1]][j + dir[k][0]] == 0){
                            c++;
                        }
                    }
                    int v = map[i][j];
                    if( v - c < 0){
                        map[i][j] = 0;
                    }else{
                        map[i][j] = v-c;
                    }
                }
            }
        }
        
//        cout << endl ;
//        for(int i = 0 ; i <row; i++){
//            for(int j = 0 ; j< column ;j++){
//                cout << map[i][j] << " ";
//            }
//            cout << endl;
//        }
        year++;
    }
    
    if(ch){
        return 0;
    }
    
    for(int i = 0 ; i <row; i++){
        copy_map[i].clear();
    }
    copy_map.clear();
    
    return year ;
}

int main(void){
    int row, column ;
    cin >> row >> column;
    
    vector < vector < int > > map (row , vector < int > ( column, 0 ));
    
    for(int i = 0 ; i < row ;i++){
        for(int j = 0 ; j < column ; j++){
            cin >> map[i][j] ;
        }
    }
    
    int count = count_year(map, row, column);
    
    for(int i = 0 ; i <row; i++){
        map[i].clear();
    }
    map.clear();
    
    cout << count ;
    
    
    return 0;
}

/*
 5 7
 0 0 0 0 0 0 0
 0 2 4 5 3 0 0
 0 3 0 2 5 2 0
 0 7 6 2 4 0 0
 0 0 0 0 0 0 0
 */
