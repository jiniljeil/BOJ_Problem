#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std; 

int N ; 
vector<int> V; 
int main(void) { 
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; 
    
    int tmp ; 

    cin >> N ; 
    for (int i = 0 ; i < N; i++) { 
        cin >> tmp ; 
        V.push_back(tmp) ;
    }

    sort(V.begin(), V.end()) ; 

    cout << V[0] << ' ' << V[V.size() - 1] << '\n' ; 
    return 0; 
}