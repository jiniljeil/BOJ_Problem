#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n,sum = 0;
    int arr[101];
    
    scanf("%d",&n);
    
    for(int i = 0 ; i<n ; i++){
        scanf("%1d",&arr[i]);
    }
    
    for(int i = 0 ; i < n ; i++){
        sum += arr[i];
    }
    
    printf("%d",sum);
    return 0;
}
