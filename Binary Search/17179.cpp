#include <bits/stdc++.h>
#define SIZE 1010
using namespace std ;
typedef long long ll;
int S[SIZE] ;
int N, M, L, K ; 

int main() { 
    ios::sync_with_stdio(0) ; cin.tie(0) ;

    cin >> N >> M >> L ;

    for (int i = 0 ; i < M ;i++)
        cin >> S[i] ; 
    
    sort(S, S + M) ;

    for (int i = 0 ; i < N ; i++) { 
        cin >> K ; 
        // parameteric search 
        ll left = 0, right = L ; 
        ll result = 0 ;

        while ( left <= right ) {
            ll mid = (left + right) >> 1; 
            int prev = 0, cnt = 0 ; 
            for (int t = 0 ; t < M ; t++) { 
                if ( S[t] - prev >= mid ) { 
                    cnt++; 
                    prev = S[t] ;
                }
            }

            // Key point
            if ( cnt == K && L - prev < mid ) cnt--;

            if ( cnt < K ) { 
                right = mid - 1 ; 
            } else { 
                left = mid + 1 ;
                result = max(result,mid) ; 
            }
        }
        cout << result << '\n';
    }
    return 0;
}