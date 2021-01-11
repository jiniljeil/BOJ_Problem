#include <iostream> 
#include <algorithm>
using namespace std ;

int n, m; 
int arr[10];
int output[10]; 

void func(int k) { 
    if( k == m ){ 
        for(int i = 0 ; i < m; i++) {
            cout << output[i] << " " ;
        }
        cout << '\n';
        return ;
    }
    int before = 0 ;
    for(int i = 0 ; i < n; i++) {
        if(before != arr[i] ){
            output[k] = arr[i]; 
            before = output[k] ; 
            func(k+1) ;
        }
    }
}
int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> n >> m ; 

    for(int i = 0 ; i < n; i++) {
        cin >> arr[i] ; 
    }
    sort(arr, arr+ n) ;
    func(0);
    return 0;
}