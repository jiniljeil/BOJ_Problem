#include <iostream>
#include <queue>
using namespace std;

/*
3 9
...XXX...
.X.....X.
...XXX...
 */
char **map;
int row, column;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool check = false;
void pathFinder(){
    for(int i = 0 ; i < row; i++){
        for(int j = 0 ; j < column ;j++){
            if( map[i][j] == '.'){
                int curr_x = j;
                int curr_y = i;
                int count = 0 ;
                
                for (int k = 0 ; k < 4; k++){
                    int dir_x = curr_x + dx[k];
                    int dir_y = curr_y + dy[k];
                    
                    if( dir_x >= 0 && dir_x < column && dir_y >= 0 && dir_y < row && map[dir_y][dir_x] == '.') {
                        count++;
                    }
                    
                }
                if( count <= 1){
                    check = true;
                    break;
                }
            }
            if( check ) break;
        }
        if( check ) break;
    }
    
    if( check ){
        cout << "1" << endl;
    }else {
        cout << "0" << endl;
    }
}

int main(void){
    
    
    scanf("%d %d",&row, &column);
    getchar();
    map = new char*[row];
    for(int i = 0 ; i < row; i++){
        map[i] = new char[column];
    }
    for (int i = 0 ; i < row ; i++ ){
        for (int j = 0 ; j <column; j++){
            scanf("%c", &map[i][j]);
        }
        getchar();
    }
    
    pathFinder();
    
    for(int i = 0 ; i <row; i++){
        delete [] map[i];
    }
    delete [] map;
    return 0;
}
