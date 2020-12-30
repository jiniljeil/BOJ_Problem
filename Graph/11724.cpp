// connection component 

#include <iostream>
#include <vector>

using namespace std;

int result;

void BFS(int **map, bool *visit, int k, int size){
    if(visit[k]) return;
    visit[k] = true;
    
    for(int i = 0 ; i < size; i++){
        if( map[k][i] && !visit[i] ){
            BFS(map,visit,i,size);
        }
    }
}

int main(void) {
    int size, n;
    scanf("%d %d",&size, &n);
    
    bool *visit = new bool[size];
    int **map = new int*[size];
    
    for(int i = 0 ; i < size; i++){
        map[i] = new int[size];
        visit[i] = false;
    }
    for(int i = 0 ; i < size; i++){
        for(int j = 0; j < size; j++){
            map[i][j] = 0;
        }
    }
    
    for(int i = 0 ; i < n; i++){
        int t1, t2;
        scanf("%d %d", &t1,&t2);
        map[t1-1][t2-1] = 1;
        map[t2-1][t1-1] = 1;
    }
    
    for(int i = 0 ; i < size; i++){
        if( !visit[i] ){
            BFS(map, visit, i , size);
            result++;
        }
    }
    
    for(int i = 0 ; i < size; i++){
        free(map[i]);
    }
    free(map);
    
    printf("%d",result);
    return 0;
}

/*
 6 5
 1 2
 2 5
 5 1
 3 4
 4 6
 */
