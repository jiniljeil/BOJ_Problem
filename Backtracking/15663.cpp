#include <iostream> 
#include <algorithm>
#include <vector> 
#include <set>
using namespace std ;

int n, m; 
int arr[10]; 
int tmp[10];
int visited[10];  

void func(int k) {
    if( k == m ) { 
        for(int p = 0; p < m; p++) {
            cout << arr[p] << " "; 
        }
        cout << "\n";
        return ;
    }
    int before = 0; 
    for(int i = 0 ; i < n; i++) {
        if(!visited[i] && (tmp[i] != before)) {
            arr[k] = tmp[i] ; 
            before = arr[k] ; 
            visited[i] = true; 
            func(k+1); 
            visited[i] = false; 
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    cin >> n >> m ;
    
    for(int i = 0; i < n ;i++) {
        cin >> tmp[i];
    }
    sort(tmp, tmp + n ) ;
    func(0); 

    return 0;
}

