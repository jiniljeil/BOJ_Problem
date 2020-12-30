#include <iostream>
#include <queue> 
#include <vector> 
#define MAX 51
using namespace std; 

vector<int> tree[MAX];
bool visited[MAX]; 
int rootNode, result; 
int BFS(int rootNode){
    int count = 0;  
    queue<int> q;   
    
    q.push(rootNode);
    visited[rootNode] = true; 
    while(!q.empty()){
        int node = q.front(); 
        q.pop(); 
        
        int child_count = 0; 
        for(int i = 0 ;i < tree[node].size(); i++){
            if( !visited[tree[node][i]] ){
                child_count++; 
                visited[tree[node][i]] = true; 
                q.push(tree[node][i]); 
            }
        }
        if( child_count == 0 ){
            count++; 
        }
    }
    return count; 
} 

int main(void){
    int n;  
    int delete_node  ; 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    // input 
    cin >> n ; 
    for(int i = 0 ; i < MAX; i++) visited[i] = false; 

    int t = 0; 
    for(int i = 0 ; i < n ; i++) {
        cin >> t ;
        if( t != -1 ){ // Not root node 
            tree[t].push_back(i);
            tree[i].push_back(t);
        }else{ 
            rootNode = i; 
        }
    }

    cin >> delete_node; 

    if( delete_node != rootNode){
        visited[delete_node] = true ;
        result = BFS(rootNode);
    } 

    cout << result << "\n";

    return 0 ;
}