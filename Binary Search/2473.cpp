#include <iostream> 
#include <algorithm>
#define SIZE 5000
typedef long long ll ;
using namespace std; 

ll arr[SIZE + 1] ;  
ll result[3]; 
ll answer = 3e9 ; 
int N ; 
int main(void) {
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; 

    cin >> N ; 

    for (int i = 0 ; i < N; i++) {
        cin >> arr[i] ; 
    }

    sort(arr, arr + N) ; 

    for (int i = 0 ; i < N - 2 ; i++) { 
        ll left = i + 1; ll right = N - 1 ;  
        while ( left < right ) { 
            ll sum = arr[i] + arr[left] + arr[right] ; 

            if ( abs(answer) > abs(sum) ) { 
                answer = sum ; 
                result[0] = arr[i] ; result[1] = arr[left] ;  result[2] = arr[right];
            }

            if ( sum >= 0 ) right--; 
            else left++; 
        }
    }

    sort(result, result + 3) ; 

    for (int i = 0 ; i < 3 ; i++) cout << result[i] << ' ' ; 

    cout << '\n' ; 
    return 0 ; 
}