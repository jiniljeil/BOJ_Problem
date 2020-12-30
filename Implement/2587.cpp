#include <iostream> 
#include <algorithm>

using namespace std;

int main(void){
    int arr[5]; 
    int sum = 0 ; 
    for(int i = 0 ; i < 5; i++){
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    sum = sum / 5; 
    sort(arr, arr+5);
    printf("%d\n%d\n", sum, arr[2]);

    return 0; 
}
