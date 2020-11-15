#include <iostream>

using namespace std;

bool arr[1000001];

int main() {
    int n;
    for(int i = 2; i <= 1000000; i++) arr[i] = true;
    
    for(int i = 2; i <= 1000000; i++) {
        if( !arr[i] ) continue;
        for(int j = 2*i ; j <= 1000000 ;  j += i ){
            arr[j] = false;
        }
    }
    
    arr[2] = false;
    
    while(1){
        bool check = false;
        scanf("%d",&n);
        if( n == 0 ) break;
        
        if( n != 0 ){
            for(int i = 3 ; i <= n; i++){
                if(arr[i] && arr[n - i]){
                    printf("%d = %d + %d\n",n, i, n-i);
                    check = true;
                    break;
                }
            }
            if(!check ) printf("Goldbach's conjecture is wrong.\n");
        }
    }
   
    return 0;
}
