#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std; 

int N ;

int main(void)  {
    ios::sync_with_stdio(false); cin.tie(0) ; 

    while ( cin >> N ) {  
        vector<int> V ; 
        vector<int> LIS ; 
        for (int i = 0, n = 0 ; i < N ; i++) {
            cin >> n ; V.push_back(n) ; 
        }

        LIS.push_back(V[0]) ; 
        for (int i = 1 ;i < V.size(); i++) {
            if ( LIS.back() < V[i] ) { 
                LIS.push_back(V[i]) ; 
            } else { 
                int idx = lower_bound(LIS.begin(), LIS.end(), V[i]) - LIS.begin() ; 
                LIS[idx] = V[i] ; 
            }
        }

        cout << LIS.size() << '\n'; 
    }
    return 0 ;
}