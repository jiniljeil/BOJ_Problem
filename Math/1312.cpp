#include <iostream> 

using namespace std ;

int A, B, N; 
int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 

    cin >> A >> B >> N ; 

    int m = A % B ;  

    int k = 0 ; 
    while(N--) { 
        k = (m * 10) / B ; 
        m = (m * 10) % B ; 
    }
    cout << k << '\n' ; 
    return 0 ; 
}