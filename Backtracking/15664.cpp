#include <iostream> 
#include <algorithm>
using namespace std ;

int n, m; 
int arr[10];
int output[10]; 
int visited[10];

void func(int k) { 
    if( k == m ){ 
        for(int i = 0 ; i < m; i++) {
            cout << output[i] << " " ;
        }
        cout << '\n';
        return;
    }
    int before = 0 ;
    for(int i = 0 ; i < n; i++) {
        if(!visited[i] && before != arr[i] && (k == 0 || (k-1 >= 0 && output[k-1] <= arr[i]))){
            output[k] = arr[i]; 
            before = output[k] ; 
            visited[i] = true ; 
            func(k+1) ;
            visited[i] = false; 
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