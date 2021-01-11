#include <iostream>
#include <queue> 
#include <vector> 
#include <cstring> 
#define MAX 501
using namespace std ;

int N; 
int entry[MAX], order[MAX], topo[MAX][MAX]; 
int main(void) {
    ios::sync_with_stdio(false) ;
    cin.tie(NULL); 
    cout.tie(NULL); 
    
    cin >> N ;

    for(int i = 0; i < N; i++) {
        int t, tN, a,b, abN; 
        cin >> tN ;
        for(int j = 1 ; j <= tN; j++) {
            cin >> order[j] ; 
        } 
        for(int j = 1; j <= tN; j++) {
            for(int k = j + 1; k <= tN; k++) {
                topo[order[j]][order[k]] = 1; 
                entry[order[k]]++;
            }
        }
        cin >> abN; 

        for(int j = 0; j < abN; j++) {
            cin >> a >> b; 
            if(topo[a][b]) {
                topo[b][a] = !(topo[a][b] = 0) ; 
                entry[b]--; entry[a]++; 
            }else{
                topo[b][a] = !(topo[a][b] = 1) ; 
                entry[b]++; entry[a]--; 
            }
        }
        queue<int> q; 
        for(int j = 1; j <= tN; j++) {
            if( entry[j] == 0 ){
                q.push(j);
            }
        }
        bool check = true; 
        vector<int> result; 

        while(!q.empty()){ 
            if( q.size() > 1 ) {check = false; break;}
            int curr = q.front(); 
            q.pop(); 
            result.push_back(curr); 
            for(int k = 1; k <= tN; k++) {
                if( topo[curr][k] ) {
                    entry[k]--; 
                    if(entry[k] == 0 ) q.push(k); 
                }
            }
        }
        
        if(!check){ 
            cout << "?";
        }else if(result.size() == tN){
            for(int p = 0 ; p < result.size(); p++) cout << result[p] << " "; 
        }else{
            cout << "IMPOSSIBLE" ;
        }
        cout << "\n";
        memset(entry, 0, sizeof(entry)); 
        memset(order, 0, sizeof(order));
        memset(topo, 0 , sizeof(topo));
    }
    
    return 0;
}