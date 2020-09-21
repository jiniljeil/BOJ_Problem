#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int numFa, numChicken ;
    long long sum = 0;
    
    scanf("%d %d",&numFa,&numChicken);
    int arr[1000000] = { 0, };
    
    for(int i = 0 ; i < numFa; i++){
        int t;
        scanf("%d",&t);
        arr[i] = t ;
        sum += t ;
    }
    
    sort(arr,arr+numFa);
    
    long long left = 0, right = sum / numFa;
    long long mid = (left + right)/2;
    while(left <= right) {
        int ch = 0;
        for(int i = 0 ; i < numFa; i++){
            cout << mid << " ";
            ch += arr[i] / mid;
        }
        if( ch >= numChicken){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
        mid = (left + right) / 2; 
    }
    
    cout << sum - mid * numChicken;

    return 0;
}
