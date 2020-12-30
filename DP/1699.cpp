#include <iostream>
#include <math.h>
#define N 100001

using namespace std;
int arr[N];
int c = 0 ;

int main() {
    int num = 0;
    
    scanf("%d",&num);
    
    for(int i = 1; i * i < N; i++){
        arr[i * i] = 1;
    }
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i < N; i++){
        int t = (int)(sqrt(i));
        int min = 9999999;
        for(int j = t ; j >= 1 ; j--){
            int tmp = arr[i - j * j] + 1;
            if( min > tmp ){
                arr[i] = min = tmp ;
            }
        }
    }
    
    printf("%d",arr[num]);
    return 0;
}
