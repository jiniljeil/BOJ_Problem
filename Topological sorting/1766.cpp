#include <iostream> 
#include <queue> 
#include <vector> 
using namespace std ;
vector<int> v[32001]; 
int entry_set[32001] ;
priority_queue<int, vector<int>, greater<int> > q; 

int N,M ; 
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> N >> M ;
    int a, b ;
    for(int i = 0 ; i < M; i++) {
        cin >> a >> b; 
        v[a].push_back(b);
        entry_set[b]++;     
    }

    for(int i = 1; i <= N; i++) { 
        if( entry_set[i] == 0 ) q.push(i); 
    }

    while(!q.empty()) {
        int curr = q.top(); 
        q.pop(); 

        cout << curr << ' '; 

        for(int i = 0 ;i < v[curr].size(); i++) {
            int x = v[curr][i]; 
            entry_set[x]--; 
            if( entry_set[x] == 0) q.push(x); 
        }
    }
    
    return 0; 
}