#include <iostream> 
#include <vector>
#include <algorithm>
typedef unsigned int ui ; 
using namespace std ;

int N, C ; 
ui x ; 
vector<ui> V ; 

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ;

    cin >> N >> C ; 
    for (int i = 0 ; i < N ; i++) { cin >> x ; V.push_back(x); }

    sort(V.begin(), V.end()) ;

    ui left = 1, right = V[V.size() - 1] ; 
    ui answer = 0 ; 
    while ( left <= right ) { 
        ui mid = (left + right) / 2 ; 
        ui prev = V[0], num = 1 ; 

        for (int i = 1 ; i < V.size(); i++) { 
            if ( V[i] - prev >= mid ) { 
                prev = V[i] ; 
                num++;
            }
        }

        if ( num >= C ) { 
            left = mid + 1 ; 
            answer = mid ; 
        } else { 
            right = mid - 1 ; 
        }
    }

    cout << answer << '\n'; 
    return 0;
}