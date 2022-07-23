#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std; 

int N ; 
vector<int> V ; 
vector<int> LIS ; 
int main(void) {
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; 

    int tmp; 
    cin >> N ; 
    for (int i = 0 ; i < N ; i++) { 
        cin >> tmp ; 
        V.push_back(tmp) ; 
    }

    LIS.push_back(V[0]) ; 
    for (int i = 1 ; i < V.size(); i++) { 
        if ( LIS.back() < V[i]) { 
            LIS.push_back(V[i]) ; 
        } else { 
            int idx = lower_bound(LIS.begin(), LIS.end(), V[i]) - LIS.begin() ; 
            LIS[idx] = V[i] ; 
        }
    }

    cout << LIS.size() << '\n'; 

    return 0 ;
}