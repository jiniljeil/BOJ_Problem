#include <bits/stdc++.h>

using namespace std ;

typedef complex<double> cpx ;

const double PI = acos(-1) ;

int N ;
long long result ;

void FFT(vector<cpx> &f, cpx w) { 
    int N = f.size() ;
    if ( N == 1 ) return ;
    vector<cpx> even(N / 2), odd(N / 2) ; 
    for (int i = 0 ; i < N ; i++ ) { 
        if ( i % 2 == 0 ) even[i / 2] = f[i] ; 
        else odd[i / 2] = f[i] ; 
    }

    FFT(even, w * w) ; FFT(odd, w * w) ; 
    cpx z(1,0) ;
    for (int i = 0 ; i < N / 2 ; i++ ) {
        f[i] = even[i] + z * odd[i] ;
        f[i + N/2] = even[i] - z * odd[i] ; 
        z *= w ;
    }
}

vector<cpx> mul(vector<cpx> &v, vector<cpx> &u) { 
    int N = 1; 
    while ( N <= v.size() || N <= u.size() ) N *= 2 ; 
    N *= 2 ;
    
    u.resize(N) ; v.resize(N) ; 
    vector<cpx> c(N) ;

    cpx w(cos(2 * PI / N), sin(2 * PI / N)); 

    FFT(v, w) ; FFT(u, w) ; 

    for (int i = 0 ; i < N ;i++) c[i] = v[i] * u[i] ;

    FFT(c, cpx(1, 0) / w) ; 

    for (int i = 0 ; i < N  ; i++) { 
        c[i] /= cpx(N, 0); 
        c[i] = cpx(round(c[i].real()), round(c[i].imag())) ;
    }

    return c; 
}
int main() {
    ios::sync_with_stdio(0) ; cin.tie(0) ;

    cin >> N ;
    vector<int> a( N + N ), b(N) ; 
    for (int i = 0 ; i < N ; i++ ) cin >> a[i] ; 
    for (int i = N - 1; i >= 0 ; i--) cin >> b[i] ; 
    for (int i = 0 ; i < N ; i++) a[i + N] = a[i] ; 

    vector<cpx> v, u; 
    for (int i = 0 ; i < a.size(); i++) v.push_back(cpx(a[i] ,0)) ; 
    for (int i = 0 ; i < b.size(); i++) u.push_back(cpx(b[i] ,0)) ; 
    
    vector<cpx> c = mul(v, u) ; 

    for (int i = 0 ; i < c.size() ; i++) {
        result = max<long long>(result, round(c[i].real())) ;
    }
    
    cout << result << '\n'; 
    return 0;
}