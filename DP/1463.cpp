#include <iostream>

using namespace std;

int min(int a, int b ){
    if (a > b){
        return b;
    }else{
        return a;
    }
}

int main(void){
    int input;
    cin >> input ;
    int arr[1000001] = { 0, };
    arr[1] = 0 ;
     
    for(int i = 2; i <= input; i++){
        arr[i] = arr[i-1] + 1;
        if( i % 2 == 0){
            arr[i] = min(arr[i],arr[i/2]+1);
        }
        if( i % 3 == 0){
            arr[i] = min(arr[i],arr[i/3]+1);
        }
    }
    cout << arr[input] << endl;
    return 0;
}
