#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std ;

int TC, N, a, b; 
vector<pair<int, int> > V ; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ;

    cin >> TC ; 

    while (TC--) { 
        cin >> N ;  
        for (int i = 0 ; i < N ;i++) { 
            cin >> a >> b ; 
            V.push_back(make_pair(a, b)) ; 
        }

        sort(V.begin(), V.end()) ;
        
        int answer = 1 ;

        int second = V[0].second ; 
        for (int i = 1 ; i < V.size() ; i++) {
            if ( V[i].second <= second ) { 
                second = V[i].second ; 
                answer++; 
            }
        }

        cout << answer << '\n' ;
        V.clear() ; 
    }
    return 0 ; 
}