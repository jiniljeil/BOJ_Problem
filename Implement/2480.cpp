#include <iostream> 

using namespace std;

int main(void){
    int a,b,c; 
    scanf("%d %d %d",&a,&b,&c);

    int arr[3] = {a, b ,c };
    if( a == b && b == c && a == c){
        printf("%d\n", 10000+ (a * 1000));
    }else if (a == b){
        printf("%d\n", 1000 + (a * 100)); 
    }else if (b == c){ 
        printf("%d\n", 1000 + (b * 100)); 
    }else if (a == c){
        printf("%d\n", 1000 + (c * 100)); 
    }else{
        int max = 0; 
        for(int i = 0 ; i < 3; i++){
            if( max < arr[i]) max = arr[i];
        }
        printf("%d\n", max * 100);
    }
    return 0; 
}