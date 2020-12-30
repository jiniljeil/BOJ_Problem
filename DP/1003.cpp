#include <iostream>

using namespace std;

int dp[10001];

int print(int n, int& countZero, int& countOne) {
    if(n == 0){
        countZero++;
        return 0;
    }else if(n == 1){
        countOne++;
        return 1;
    }else{
        return print(n-1,countZero,countOne) + print(n-2,countZero,countOne);
    }
}
int main(void){
    int num  ;
    scanf("%d", &num);
    
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2 ; i < 41 ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    for(int i = 0 ; i < num; i++){
        int n = 0 ;
        
        scanf("%d",&n);
        
        if(n == 0){
            printf("1 0\n");
        }else if(n == 1){
            printf("0 1\n");
        }else{
            printf("%d %d\n",dp[n-1], dp[n]);
        }
        
    }
    return 0;
}

/*
 8
 0 1 2 3 4 5 6 7
 1 0
 0 1
 1 1
 1 2
 2 3
 3 5
 5 8
 8 13
 */
