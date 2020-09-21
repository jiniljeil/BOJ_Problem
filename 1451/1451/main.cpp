#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int row, column; // 세로 갯수 가로 갯수
    
    scanf("%d %d", &row,&column);
    vector<vector<int>> arr ( row+1, vector<int> (column+1, 0));
    for(int i = 1 ; i <= row; i++){
        for(int j = 1 ; j <= column; j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    
    for(int i = 1; i <= row; i++){
        for(int j = 1 ; j <= column; j++){
            arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    
    for(int i = 1; i <= row; i++){
        for(int j = 1 ; j <= column ;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
