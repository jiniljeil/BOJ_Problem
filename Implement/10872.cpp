#include <iostream> 
typedef long long ll ; 
using namespace std ;

ll answer = 1; 
int N = 0 ;
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0) ; 
    cin >> N ; 

    for (int i = 1 ; i <= N; i++) { 
        answer *= i ; 
    }
    cout << answer << '\n'; 
    return 0 ;
}