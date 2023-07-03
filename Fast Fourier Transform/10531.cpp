#include <bits/stdc++.h>
#define SIZE 200010
using namespace std ;

const double PI = acos(-1) ; 
typedef complex<double> cpx ;
int N, M, k, result ; 
void FFT(vector<cpx> &v, bool inverse) { 
    int S = v.size() ; 

    for (int i = 1, j = 0 ; i < S ; i++) { 
        int bit = S / 2; 
        while ( j >= bit ) { j -= bit ; bit /= 2; } 
        j += bit ; 
        if ( i < j ) swap(v[i], v[j]) ;
    }
    
    for (int k = 1 ; k < S; k *= 2) {
        double angle = (inverse ? PI / k : -PI / k) ;
        cpx w(cos(angle), sin(angle));

        for(int i=0; i<S; i+=k*2) {
            cpx z(1, 0);

            for(int j=0; j<k; j++) {
                cpx even = v[i+j];
                cpx odd = v[i+j+k];

                v[i+j] = even + z*odd;
                v[i+j+k] = even - z*odd;

                z *= w;
            }
        }
    }

    if ( inverse ) for (int i = 0 ; i < N ; i++) v[i] /= S ; 
}

vector<cpx> mul(vector<cpx> &v, vector<cpx> u ) { 
    int S = 1 ;
    while ( S < v.size() + u.size() ) S *= 2 ; 

    v.resize(S) ; FFT(v, false) ; 
    u.resize(S) ; FFT(u, false) ; 

    vector<cpx> vu(S) ; 
    for (int i = 0 ; i < S; i++) vu[i] = v[i] * u[i] ;  
    FFT(vu, true) ; 

    return vu ;
}

int main() { 
    ios::sync_with_stdio(0) ; cin.tie(0) ;

    vector<cpx> v(SIZE), u(SIZE) ; 
    vector<int> dist(SIZE) ;

    cin >> N ; 
    while (N--) { 
        cin >> k ;
        v[k] = u[k] = cpx(1, 0); 
        dist[k] = 1 ;
    }

    vector<cpx> c = mul(v, u) ;

    cin >> M ; 
    while (M--) { 
        cin >> k;
        if ( dist[k] > 0 || round(c[k].real()) > 0) result++; 
    }

    cout << result << '\n';

    return 0;
}