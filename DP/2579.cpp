#include <iostream>
#include <math.h>

using namespace std;

int arr[301];
int dp[301];
int main() {
    int n;
    scanf("%d", &n);
    
    for(int i = 0 ;i < n; i++){
        scanf("%d",&arr[i]);
    }
    
    dp[0] = arr[0];
    dp[1] = max(arr[0]+ arr[1] , arr[1]);
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
    
    for(int i = 3; i < n; i++){
        dp[i] = max( arr[i] + dp[i-2], arr[i] + arr[i-1] + dp[i-3]);
    }
    
    printf("%d\n",dp[n-1]);
    return 0;
}
