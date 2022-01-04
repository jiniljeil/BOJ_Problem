#include <iostream> 
#include <vector> 
#include <cstring>
#define MAX_W 100001

using namespace std ;

int N, K, W, V ; 
int B[MAX_W][2] ; 
vector<pair<int,int> > v ; 

void DP() { 
    memset(B, 0, sizeof(B)) ;

    for (int i = 0 ; i < v.size(); i++) { 

        for (int w = 1 ; w <= K; w++) {
            if ( v[i].first <= w ) { 
                if ( v[i].second + B[w - v[i].first][0] > B[w][0]) { 
                    B[w][1] = v[i].second + B[ w - v[i].first][0] ; 
                } else { 
                    B[w][1] = B[w][0] ;
                }
            } else { 
                B[w][1] = B[w][0] ; 
            }
        }

        for (int w = 1; w <= K; w++) {
            B[w][0] = B[w][1] ;
        }
    }

    cout << B[K][0] << '\n';
}

void Input() { 
    cin >> N >> K ; 

    for (int i = 0 ; i < N ; i++) {
        cin >> W >> V ; 
        v.push_back(make_pair(W, V)) ; 
    }
}

int main(void) { 
    ios::sync_with_stdio(false) ;
    cin.tie(0) ; 

    Input() ;
    DP(); 

    return 0 ;
}