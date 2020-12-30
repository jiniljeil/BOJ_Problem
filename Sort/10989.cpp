#include <iostream>
#include <algorithm>

int arr[10001];

using namespace std;

int main(void){
    
    int num = 0 ;
    scanf("%d",&num);
    
    for(int i = 0 ; i <num; i++){
        int k = 0;
        scanf("%d", &k);
        arr[k] += 1;
    }
    
    for(int i = 1 ; i <= 10000; i++){
        for(int j = 0 ; j < arr[i]; j++){
            printf("%d\n",i);
        }
    }
    return 0;
    
}
