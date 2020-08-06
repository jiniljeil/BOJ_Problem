#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

void search (int value,int left, int right){
    // 4 1 5 2 3
    // 1 3 7 9 5
    while(left <= right){
        int mid = (left+right)/2;
        if(value > arr[mid]){
            left = mid+1; //return search(value,arr,left+1,right);
        }else if(value == arr[mid]){
            printf("%d\n",1);
            return ;
        }else{
            right = mid-1; //return search(value,arr,left,right-1);
        }
    }
    printf("%d\n",0);
    return ;
}

int main(void){
    int num1;
    int num2;
    
    scanf("%d",&num1);
    
    for(int i = 0 ; i < num1; i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+num1);

    scanf("%d",&num2);
    
    for(int i = 0 ; i < num2; i++){
        int n = 0 ;
        scanf("%d",&n);
        search(n, 0, num1-1);
    }

    return 0;
}
