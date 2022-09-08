#include <iostream> 
#include <set> 

using namespace std; 

set<int> S ; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0); 

    for (int i = 0, n = 0 ; i < 10 ; i++) { 
        cin >> n ; 
        S.insert(n % 42) ; 
    }

    cout << S.size() << '\n'; 
    return 0 ;
}