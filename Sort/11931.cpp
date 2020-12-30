#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n ;
    scanf("%d",&n);
    int *arr = new int[n];
    
    for(int i = 0 ; i < n ; i++){
        int tmp = 0 ;
        scanf("%d",&tmp);
        arr[i] = tmp ;
    }
    sort(arr, arr+n, greater<int>());
    
    for(int i = 0 ; i < n ; i++) printf("%d\n",arr[i]);
    free(arr);
    return 0;
}
