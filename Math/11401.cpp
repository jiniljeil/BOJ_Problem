#include <iostream> 
#define MOD 1000000007
typedef unsigned long long ll ; 
using namespace std; 

ll n, k ; 
ll answer = 1; 
ll bpow(ll a, ll b, ll mod) { 
    ll res = 1 ; 
    a %= mod ; 
    while(b) { 
        if ( b & 1 ) { 
            res = (res * a) % mod ; 
        }
        b >>= 1 ; 
        a = (a * a) % mod; 
    }
    return res ; 
}

int main(void) {
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; 

    cin >> n >> k ; 

    // (n!/(n-k)!)
    for (ll i = n - k + 1 ; i <= n ; i++) answer = (answer * i) % MOD ; 

    // k!
    ll B = 1 ;
    for (ll i = 1 ; i <= k ; i++) B = (B * i) % MOD ; 

    //페르마의 소정리에 의해서 (n!/((n-k)!k!)) % MOD = (n!/(n-k)!) % MOD * ((k!)^(MOD - 2)) % MOD
    answer = (answer * bpow(B, MOD - 2, MOD)) % MOD ; 

    cout << answer << '\n' ; 
    return 0; 
}