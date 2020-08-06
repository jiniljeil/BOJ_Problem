#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/**
 6
 5
 1 2
 1 3
 3 4
 2 3
 4 5
 */
int numFriend(vector<vector<int>> matrix, int numofp){
    int count = 0 ;
    
    vector<int> check (numofp, 0);
    
    for(int i = 1 ; i < numofp; i++){
        if(matrix[0][i] == 1){ // friend of user
            for(int j = 0; j < numofp; j++){
                if(matrix[i][j] == 1 || matrix[j][i] == 1){
                    check[i] = check[j] = 1; // friend of friend
                }
            }
        }
    }
    for(int i = 1 ; i < check.size(); i++){
        if(check[i] == 1){
            count++;
        }
    }
    
    return count;
}

int main(void){
    int people ;
    int n ;
    scanf("%d",&people);
    scanf("%d",&n);
    
    vector<vector<int>> matrix (people, vector<int> (people, 0));
    for(int i = 0 ; i < n ; i++){
        int n1 , n2;
        scanf("%d %d",&n1,&n2);
        matrix[n1-1][n2-1] = 1;
        matrix[n2-1][n1-1] = 1;
    }
    int count = numFriend(matrix, people);
    cout << count << endl;
    return 0;
}
