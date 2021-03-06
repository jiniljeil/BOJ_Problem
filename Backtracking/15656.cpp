#include <iostream> 
#include <algorithm>

using namespace std ;

int n, m; 
int arr[10];  
int tmp[10];

void func(int k) {
    if( k == m) {
        for(int t = 0 ; t < m ; t++) { 
            cout << tmp[arr[t]] << " "; 
        }
        cout << "\n" ;
        return ;
    }

    for(int i = 1; i <= n ; i++) { 
        arr[k] = i; 
        func(k+1) ;
    }
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    cin >> n >> m ;

    for(int i = 1 ; i <= n; i++) { 
        cin >> tmp[i] ;
    } 
    sort(tmp + 1, tmp + n + 1) ;
    func(0); 
    return 0;
}