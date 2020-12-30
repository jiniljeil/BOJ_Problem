#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
 20
 30
 50
 48
 33
 66
 0
 64
 */
int main(void){
    vector<int> arr(8, 0);
    vector<int> copy_arr(8,0);
    vector<int> tmp(5,0);
    for(int i = 0 ; i < 8; i++){
        cin >> arr[i];
    }
    
    for(int i = 0 ; i < 8 ; i++){
        copy_arr[i] = arr[i];
    }
    
    sort(arr.begin(), arr.end(), greater<int>());
    
    int sum = 0 ;
    
    for(int i = 0 ; i < 5; i++){
        sum += arr[i];
    }
    
    for(int i = 0 ; i < 5; i++){
        int k = i;
        for(int j = 0 ; j < 8; j++){
            if(arr[k] == copy_arr[j]){
                tmp[i] = j+1;
                break;
            }
        }
    }
    
    sort(tmp.begin(), tmp.end());
    
    cout << sum << endl;
    for(int i = 0 ; i <5; i++){
        cout << tmp[i] << " ";
    }
    return 0;
}
