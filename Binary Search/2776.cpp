#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std ;
int TC, N, M ; 
vector<int> V1 ;

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> TC ; 

    while(TC--) { 
        cin >> N ; 
        for (int i = 0, k = 0 ; i < N ; i++) { cin >> k ; V1.push_back(k) ; }
        sort(V1.begin(), V1.end()) ; 
        cin >> M ; 
        for (int i = 0, k = 0 ; i < M ; i++) { 
            cin >> k ; 
            if ( binary_search(V1.begin(), V1.end(), k) ) { cout << '1' << '\n'; } 
            else { cout << '0' << '\n' ; }
        } 
        V1.clear(); 
    }

    return 0 ; 
}