#include <iostream> 
#include <queue> 
using namespace std; 

int row, col, height; 
int arr[101][101][101];
int dx[6] = {1, 0, -1, 0, 0, 0} ;
int dy[6] = {0, 1, 0, -1, 0, 0} ;
int dz[6] = {0, 0, 0, 0, 1, -1};

bool result_check() {
    bool checker = true; 
    for(int k = 0 ; k < height; k++) {
        for(int i = 0 ; i < row; i++ ){
            for(int j = 0 ; j < col ;j++ ){
                if( arr[i][j][k] == 0 ) {
                    return false;
                }
            }
        }
    }
    return checker; 
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> col >> row >> height ; 
    bool check = false; 
    queue<pair< pair<int,int>, int> > q; 
    for(int k = 0 ; k < height; k++) {
        for(int i = 0; i < row ; i++) {
            for(int j = 0 ; j < col; j++) {
                cin >> arr[i][j][k];
                if( arr[i][j][k] == 0) { 
                    check = true;
                }
                if( arr[i][j][k] == 1 ) {
                    q.push(make_pair(make_pair(j,i), k )) ;
                }
            }
        }
    }
    if(!check) { 
        cout << "0" << "\n";
        return 0; 
    }

    int c = 0 ; 
    while(!q.empty()) {
        int size = q.size(); 
        for(int i = 0 ; i < size; i++) {
            int curr_x = q.front().first.first ; 
            int curr_y = q.front().first.second;
            int curr_z = q.front().second; 
            q.pop();

            for(int j = 0 ; j < 6; j++) {
                int dir_x = curr_x + dx[j]; 
                int dir_y = curr_y + dy[j]; 
                int dir_z = curr_z + dz[j]; 
                if( dir_x < 0 || dir_x >= col || dir_y < 0 || dir_y >= row || dir_z < 0 || dir_z >= height) continue;
                if( arr[dir_y][dir_x][dir_z] == 0 ) {
                    arr[dir_y][dir_x][dir_z] = 1; 
                    q.push(make_pair(make_pair(dir_x,dir_y),dir_z));
                }
            }
        }
        if( q.size() == 0) {
            bool p = result_check();
            if( p == true ) {
                cout << c << "\n";
                break;
            }else{
                cout << "-1" << "\n";
                break;
            }
        }
        c++; 
    }
    
    return 0;
}