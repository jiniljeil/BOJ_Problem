#include <iostream> 

using namespace std ;

int n, m; 
int arr[10];  
void func(int k) {
    if( k == m) {
        for(int t = 0 ; t < m ; t++) { 
            cout << arr[t] << " "; 
        }
        cout << "\n" ;
        return ;
    }

    for(int i = 1; i <= n ; i++) { 
        if( (k == 0) || (k -1 >= 0 && i >= arr[k-1]) ){
            arr[k] = i ;
            func(k+1) ;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    cin >> n >> m ; 
    func(0); 
    return 0;
}