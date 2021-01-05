#include <iostream>

using namespace std; 

int N ; 
long long arr[500001] ; 
long long stack[500001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int top = 0, t = 0 ;
    cin >> N ;
    
    for(int i = 0 ; i < N; i++ ){
        cin >> t ;

        while(top > 0){
            if( arr[top] >= t) {
                cout << stack[top] << " ";
                break;
            }else{
                top--;
            }
        }
        if( top == 0) {
            cout << "0" << " ";
        }
        top++; 
        stack[top] = i + 1; 
        arr[top] = t; 
    }
    
    return 0 ;
}