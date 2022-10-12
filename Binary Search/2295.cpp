#include <iostream> 
#include <vector> 
#include <algorithm>
#define MAX 1010
using namespace std ;
typedef unsigned long long ll ; 
ll N, k; 
ll arr[MAX] ;
ll sum1[MAX * MAX] ;
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N ; 
    for (int i = 0 ; i < N ; i++) { 
        cin >> arr[i] ; 
    }

    sort(arr, arr + N) ; 

    int cnt = 0 ; 
    for (int i = 0 ; i < N ; i++) { 
        for (int j = i; j < N ; j++) { 
            ll s = arr[i] + arr[j] ; 
            sum1[cnt++] = s ; 
        }
    }
    
    sort(sum1, sum1 + cnt) ;

    ll answer = 0 ; 
    for (int i = N - 1 ; i >= 0 ; i--) { 
        for (int j = N - 2 ; j >= 0 ; j--) { 
            ll s = arr[i] - arr[j] ;
            if (binary_search(sum1, sum1 + cnt, s)) { 
                answer = max(answer, arr[i]) ; 
            } 
        }
    }
    cout << answer << '\n'; 
    return 0 ;
}