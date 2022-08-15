#include <iostream> 
#include <algorithm>
#define MAX 4000 
typedef long long ll ; 
using namespace std ; 

int N ; 
int arr[4][MAX] ; 
ll one_two_sum[MAX * MAX] ; 
int main(void) {    
    scanf("%d", &N) ; 
    for (int i = 0; i < N; i++) { 
        scanf("%d %d %d %d", &arr[0][i], &arr[1][i], &arr[2][i], &arr[3][i]) ; 
    }

    int cnt = 0 ; 
    for (int i = 0 ; i < N; i++) { 
        for (int j = 0 ; j < N; j++) { 
            ll sum = arr[0][i] + arr[1][j] ; 
            one_two_sum[cnt++] = -sum ; 
        }
    }  

    sort(one_two_sum, one_two_sum + N * N) ; 

    ll answer = 0 ; 
    for (int i = 0 ; i < N; i++) { 
        for (int j = 0 ; j < N; j++) { 
            ll sum = arr[2][i] + arr[3][j] ; 
            ll cnt = upper_bound(one_two_sum, one_two_sum + N * N, sum) - lower_bound(one_two_sum, one_two_sum + N * N, sum) ; 
            answer += cnt ; 
        }
    }

    cout << answer << '\n'; 
    return 0 ;
}