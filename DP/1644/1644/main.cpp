#include <iostream>

using namespace std;

void prime(bool *arr, int num){
    if( num <= 1 ) return ;
    for(int i = 2; i <= num; i++){
        if(!arr[i]) continue;
        for(int j = 2 * i ; j <= num; j += i){
            arr[j] = false ;
        }
    }
}

int main(int argc, const char * argv[]) {
    int num = 0, s = 0, count = 0;
    scanf("%d",&num);
    bool *arr = new bool[num+1];
    for(int i = 2 ; i <= num+1; i++) {
        arr[i] = true;
    }
    
    prime(arr,num);
    
    int a = 2, b = 2;
    while(b <= num+1){
        if( s >= num ){
            s -= a;
            while(!arr[a+1] && a <= num+1) a++;
            a++;
        }else if ( s == num){
            break;
        }else{
            s += b;
            while(!arr[b+1] && b <= num +1 )b++;
            b++;
        }
        if( s == num ) count++;
    }
    
    printf("%d\n",count);
    free(arr);
    return 0;
}
