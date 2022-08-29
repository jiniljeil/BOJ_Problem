#include <iostream> 

using namespace std; 

int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 
    int x1, y1 ;
    int x2, y2 ; 
    int x3, y3 ; 

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;  

    if ( x1 == x2 ) cout << x3 << ' '; 
    else if ( x1 == x3 ) cout << x2 << ' ' ; 
    else if ( x2 == x3 ) cout << x1 << ' ' ; 
    
    if ( y1 == y2 ) cout << y3 << '\n'; 
    else if ( y1 == y3 ) cout << y2 << '\n' ; 
    else if ( y2 == y3 ) cout << y1 << '\n' ; 
    
    return 0 ;
}