#include <iostream> 
#include <algorithm>

using namespace std ;

int n, m; 
int arr[10];  
int tmp[10];
bool visited[10]; 
void func(int k) {
    if( k == m) {
        for(int t = 0 ; t < m ; t++) { 
            cout << tmp[arr[t]] << " "; 
        }
        cout << "\n" ;
        return ;
    }

    for(int i = 1; i <= n ; i++) { 
        if(!visited[i] && ((k == 0) ||(k - 1 >= 0 && i > arr[k-1]))){
            arr[k] = i; 
            visited[i] = true; 
            func(k+1) ;
            visited[i] = false; 
        }
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