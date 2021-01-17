#include <iostream>
#include <algorithm> 

using namespace std;
int N ;
int main(void){ 
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0) ;

    cin >> N; 
    int *arr = new int[N];
    for(int i = 0 ; i < N; i++) {
        cin >> arr[i] ; 
    }
    sort(arr, arr+ N); 

    for(int i = 0 ; i < N; i++) {
        cout << arr[i] << "\n"; 
    }
    free(arr);
    return 0;
}