#include <iostream> 
#include <algorithm>
#include <set> 
using namespace std ;

int n, m; 
int arr[10]; 
int tp[10];
int visited[10];  
int tmp[10001];

bool check(int k){ 
    bool c = false; 
    for(int i = 1 ; i <= n; i++) {
        if( k != i && tp[arr[k]] == tp[arr[i]]) {
            c = true; 
            break;
        }
    }   
    return c ;
}

void func(int k) {
    if( k == m) {
        for(int t = 0 ; t < m ; t++) { 
            cout << tp[arr[t]] << " "; 
        }
        cout << "\n" ;
        return ;
    }

    for(int i = 1; i <= n ; i++) { 
        if(!visited[i] && check(i)) {
            arr[k] = i; 
            visited[i] = true; 
            // tmp[tp[i]]--; 
            func(k+1) ;
            visited[i] = false; 
            // tmp[tp[i]]++;
        }
        
    }
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    cin >> n >> m ;
    int p;
    
    for(int i = 1; i <= n ;i++) {
        cin >> p ; 
        tp[i] = p;
        tmp[p]++; 
    }
    sort(tp + 1, tp + n + 1 ) ;
    func(0); 
    return 0;
}