#include <iostream> 

using namespace std; 
typedef long long ll ;
int L, W, H, N ;
ll cnt, ans ; 
ll A[21]; 
int main(void) { 
    ios::sync_with_stdio(0) ; cin.tie(0) ; 

    cin >> L >> W >> H ; 
    cin >> N ; 

    for (int i = 0,a,b; i < N ; i++) { 
        cin >> a >> b ; A[a] = b ; 
    }
    for (int i = 19; i >= 0 ; i--) { 
        cnt <<= 3; 
        ll t = min(A[i], (ll)(L >> i)*(W >> i)*(H >> i) - cnt) ; 
        cnt += t ; ans += t ;  
    }
    if ( cnt != (ll)L * W * H ) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0 ;  
}