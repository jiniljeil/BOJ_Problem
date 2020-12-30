#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int virusComputer(vector<vector<int>> matrix, int numComputer){
    int count = 0;
    vector<int> check (numComputer, 0);
    queue<int> q;
    q.push(0);
    int x = 0 ;
    check[x] = 1;
    
    while(!q.empty()){
        x = q.front();
        q.pop();
        
        for(int i = 0 ; i < numComputer; i++){
            if(!check[i] && matrix[x][i] == 1){
                check[i] = 1;
                q.push(i);
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    int numComputer ;
    int n ;
    scanf("%d",&numComputer);
    scanf("%d", &n);
    
    vector<vector<int>> matrix (numComputer, vector<int> (numComputer,0));
    
    for(int i = 0 ; i < n ; i++){
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        matrix[n1-1][n2-1] = 1;
        matrix[n2-1][n1-1] = 1;
    }
    
    int count = virusComputer(matrix, numComputer);
    cout << count;
    return 0;
}
