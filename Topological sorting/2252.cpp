#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std;

int N, M ;
vector<int> v[32001]; 
int Entry[32001] ;
queue<int> q; 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

    cin >> N >> M ; 
    int a,b; 
    for(int i = 0 ;i < M ;i++) {
        cin >> a >> b;
        v[a].push_back(b);
        Entry[b]++;
    }

    for(int i = 1 ; i <= N; i++){
        if( Entry[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr= q.front(); 
        q.pop(); 
        cout << curr << " "; 
        for(int i = 0 ; i < v[curr].size(); i++){
            Entry[v[curr][i]]--;
            if( Entry[v[curr][i]] == 0 ) q.push(v[curr][i]);
        }
    }
    return 0;
}