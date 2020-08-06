#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void DFS(int **map, bool v[], int x, int size);
void BFS(int **map, bool v[],int x , int size);

int main(void){
    int node, edge, start;
    cin >> node >> edge >> start ;
    int **map = new int*[node+1];
    for(int i = 0 ; i <= node; i++){
        map[i] = new int[node+1];
    }
    bool *visit = new bool[node+1];
    
    for(int i = 0 ; i <= node; i++){
        visit[i] = false;
    }
    
    for(int i = 1 ; i <= edge ; i++){
        int n1,n2;
        cin >> n1 >> n2;
        map[n1][n2] = 1;
        map[n2][n1] = 1;
    }

    DFS(map,visit,start,node);
    
    cout << endl;
   
    for(int i = 0 ; i <= node; i++){
        visit[i] = false;
    }
    
    BFS(map,visit,start,node);
    
    free(visit);
    for(int i = 0 ; i <node; i++){
        free(map[i]);
    }
    free(map);
    return 0;
}

void DFS(int **map, bool v[], int x, int size){
    stack<int> stack;
    stack.push(x);
    v[x] = true;
    cout << x << " ";
    while(!stack.empty()){
        for(int i = 1 ; i <= size; i++){
            if(map[stack.top()][i] == 1 && !v[i]){
                v[i]= true;
                stack.push(i);
                cout << i << " ";
            }
        }
        stack.pop();
    }
}

void BFS(int **map, bool v[],int x , int size){
    if(v[x] == true) return;
    queue<int> queue;
    queue.push(x);
    v[x] = true;
    cout << x << " ";
    while(!queue.empty()){
        for(int i = 1 ; i <= size; i++){
            if(map[queue.front()][i] == 1 && !v[i]){
                queue.push(i);
                v[i] = true;
                cout << i << " ";
            }
        }
        queue.pop();
    }
}

