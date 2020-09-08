#include <iostream>
#include <vector>

using namespace std;

bool check = true;

void dfs(int value, int **graph, vector<int> &countList, bool *visit, int size){
    if(visit[value]) return ;
    
    visit[value] = true;
    
    for(int i = 1 ; i < size; i++){
        if(graph[value][i]){
            countList[value]++;
            dfs(i, graph, countList, visit,size);
        }
    }
    
}

void checker (int **graph, bool *visit , int size){
    vector<int> countList (size, 0);
    int countPen = 0;
    int oddCount = 0 ;
    for(int i = 1 ; i < size; i++){
        if(!visit[i]){
            countPen++;
            dfs(i, graph, countList,visit,size);
            for(int j = 1 ; j < countList.size(); j++){
                if(countList[j] % 2 != 0 ){
                    oddCount++;
                }
            }
        }
    }
    
    if(countPen == 1 && (oddCount == 0 || oddCount == 2)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(void){
    int nLocation, numEdge;
    scanf("%d %d",&nLocation, &numEdge);
    bool *visit = new bool[nLocation+1]; // (nLocation+1, false);
    for(int i = 0 ; i < nLocation+1; i++){
        visit[i] = false;
    }
    int **graph = new int*[nLocation+1];
    for(int i = 0 ; i < nLocation+1; i++){
        graph[i] = new int[nLocation+1];
    }
    for(int i = 0 ; i < nLocation+1; i++){
        for(int j = 0; j < nLocation+1; j++){
            graph[i][j] = 0;
        }
    }
//    int graph[3001][3001] = {0,};
//    vector<vector<int>> graph ( nLocation+1, vector<int>(nLocation+1, 0));
    
    for(int i = 0 ; i < numEdge; i++){
        int t1,t2 ;
        scanf("%d %d",&t1,&t2);
        graph[t1][t2] = 1;
        graph[t2][t1] = 1;
    }
    
    checker(graph, visit, nLocation+1);
   
    return 0;
}
