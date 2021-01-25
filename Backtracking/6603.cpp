#include <iostream>
#include <algorithm> 

using namespace std; 

int N; 
int set_arr[15];
int arr[15];
bool visited[15];
void func(int k) {
    if( k == 6 ) { 
        for(int i = 0 ; i < 6; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return ;
    }
    for(int i = 0 ; i < N; i++) {
        if((k == 0) || (k - 1 >= 0 && set_arr[i] > arr[k-1])){
            arr[k] = set_arr[i]; 
            func(k + 1);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;

    while(true) {
        cin >> N ; 
        if(N == 0 )break; 

        for(int i = 0 ; i < N; i++) { 
            cin >> set_arr[i];
        }

        sort(set_arr, set_arr+ N); 
        func(0); 
        cout << '\n';
    }
    return 0;
}