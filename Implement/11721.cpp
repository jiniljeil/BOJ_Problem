#include <iostream> 
#include <string> 
using namespace std ;
string s ; 
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0) ;
    cin >> s ; 
    for (int i = 0 ; i < s.size(); i++) { 
        if ( i != 0 && i % 10 == 0 ) cout << '\n';
        cout << s[i] ;
    }
    return 0 ; 
}