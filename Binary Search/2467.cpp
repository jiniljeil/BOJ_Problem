#include <iostream> 
#include <climits>
typedef long long ll ; 
using namespace std ;
int N; 
ll arr[100010], k;

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N ; 

    for (int i = 0 ; i < N ;i++) {
        cin >> arr[i] ; 
    }

    int left = 0, right = N - 1 ; 
    ll sum = LLONG_MAX ; 
    ll one = 0 , two = 0 ;
    while ( left < right ) { 
        ll _sum = arr[left] + arr[right] ; 

        if ( abs(_sum) < sum ) { sum = abs(_sum) ; one = arr[left] ; two = arr[right] ; }

        if ( _sum < 0 ) left++; 
        else right--; 
    }
    cout << one << ' ' << two << '\n'; 
    return 0; 
}