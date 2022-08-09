#include <iostream> 
#include <algorithm>
using namespace std ; 
int arr[10001] ; 
int main(void) {

    int N ; 
    scanf("%d", &N) ; 
    for (int i = 0 ; i < N; i++) {
        scanf("%d", &arr[i]) ; 
    }  

    sort(arr, arr + N) ; 

    long long answer = 0 ;
    
    for (int i = 0 ; i < N - 2 ; i++) { 
        for (int j = i + 1; j < N - 1; j++) { 
            int remainder = -(arr[i] + arr[j]) ; 
            answer += (upper_bound(arr+j+1, arr+N, remainder) - lower_bound(arr+j+1, arr+N, remainder)); 
        }
    }
    cout << answer << '\n'; 
    return 0 ;
}

