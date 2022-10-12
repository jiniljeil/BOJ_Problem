#include <iostream> 
#include <algorithm>
#include <climits>
using namespace std ;
typedef long long ll ; 
ll N, M; 
ll arr[10010] ; 
ll answer ;
ll l, r ; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ;

    cin >> N ; 
    for (int i = 0 ; i < N ; i++) { 
        cin >> arr[i] ; 
        r = max(r, arr[i]); 
    }
    cin >> M ; 

    sort(arr, arr + N) ; 

    l = 0 ;
    ll mid = 0 ;
    while ( l <= r ) { 
        mid = (l + r) / 2 ;
        ll s = 0 ; 
        for (int i = 0 ; i < N ; i++) { 
            if ( arr[i] < mid ) s += arr[i] ; 
            else s += mid ; 
        }
        if ( s > M ) { 
            r = mid - 1; 
        } else { 
            answer = mid ; 
            l = mid + 1 ;
        }
    }
    cout << answer << '\n'; 

    return 0; 
}