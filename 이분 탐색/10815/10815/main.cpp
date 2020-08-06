#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[500001];

void search (int value,int left, int right){
    // 4 1 5 2 3
    // 1 3 7 9 5
    while(left <= right){
        int mid = (left+right)/2;
        if(value > arr[mid]){
            left = mid+1; //return search(value,arr,left+1,right);
        }else if(value == arr[mid]){
            printf("%d ",1);
            return ;
        }else{
            right = mid-1; //return search(value,arr,left,right-1);
        }
    }
    printf("%d ",0);
    return ;
}

int main(void){
    int num1 = 0 , num2 = 0;
    
    scanf("%d", &num1);
    
    for(int i = 0 ;i <num1; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+num1);
    
    scanf("%d",&num2);
    for(int i = 0 ;i < num2; i++){
        int tmp = 0;
        scanf("%d",&tmp);
        
        search(tmp,0,num1-1);
    }
    return 0;
}

/*
5
111111 2934 120394 384 3212
9
111111 92358 93418 384 3212 9438 2934 38423 2931
 */
