#include <iostream>
#define MAX 1000010
using namespace std;
typedef long long ll ;

int n;
ll x;
bool mid[MAX];
/*
hi + vi ≤ hi−1 + vi−1, for each i ≥ 2 such that vi > 0
hi + vi ≤ hi+1 + vi+1, for each i ≤ N − 1 such that vi > 0
v1 = 0 and vN = 0
*/
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); 
    cin >> n >> x ;

    for (int k = 1; k <= n - 2; k++) { 
        if ( x >= n - 1 - k ) { 
            mid[k] = true ;
            x -= n - 1 - k ;
        }
    }
    if ( x > 0 ) { cout << -1 << '\n' ; return 0 ;} 

    cout << n << ' '; 
    for (int k = 1 ; k <= n - 2 ; k++) { 
        if ( mid[k] ) cout << k << ' ' ; 
    }
    cout << n - 1 << ' ' ; 
    for (int k = n - 2 ; k >= 1 ; k--) { 
        if (!mid[k] ) cout << k << ' ';
    }
    cout << '\n' ; 
    return 0;
}
