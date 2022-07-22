#include <iostream> 
#include <vector> 
#include <algorithm>
#include <stack> 
using namespace std ; 

int N ; 
vector<int> V ;  
vector<int> LIS ; 
int idx_arr[1000010] ; 
int main(void) { 
    int tmp ; 

    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; 

    cin >> N ;

    for (int i = 0 ; i < N; i++) { 
        cin >> tmp ; 
        V.push_back(tmp); 
    }

    LIS.push_back(V[0]) ; 

    for (int i = 1 ; i < V.size(); i++){ 
        if ( LIS.back() < V[i] ) { 
            LIS.push_back(V[i]) ; 
            idx_arr[i] = LIS.size() - 1;
        } else { 
            int idx = lower_bound(LIS.begin(), LIS.end(), V[i]) - LIS.begin() ; 
            LIS[idx] = V[i] ; 
            idx_arr[i] = idx ; 
        }
    }

    cout << LIS.size() << '\n'; 

    vector<int> answer;  
    int f_idx = LIS.size() - 1;
    for (int i = N - 1; i >= 0 ; i--) { 
        if ( idx_arr[i] == f_idx) { 
            f_idx--; 
            answer.push_back(V[i]) ; 
        }
    }
    for (int i = answer.size() - 1 ; i >= 0 ; i--) cout << answer[i] << ' ' ; 
    cout << '\n'; 

    return 0 ; 
}