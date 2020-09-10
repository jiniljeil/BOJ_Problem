#include <iostream>

using namespace std;

int arr[1000001];

int main(void){
    int a, b;
    
    for(int i = 0;; i++){
        scanf("%d %d", &a,&b);
        if((a < 0 && b < 0) || a > b || b > 1000000){
            break;
        }
        int count = 0 ;
        int count2 = 0;
        
        for(int i = 2 ; i <= b; i++){
            arr[i] = i ;
        }
        
        for(int i = 2; i <= b ; i++){
            if( arr[i] == 0) continue;
            for (int j = i + i; j <= b ; j += i){
                arr[j] = 0;
            }
        }
        
        for(int i = a ; i <= b ; i++){
            if( arr[i] != 0){
                count++;
                if((i-1) % 4 == 0){
                    count2++;
                }
            }
        }
        
        printf("%d %d %d %d\n",a,b,count,count2);
    }
    return 0;
}
