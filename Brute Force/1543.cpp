#include <iostream> 

using namespace std ;

string a, b; 
int main(void) {
    ios::sync_with_stdio(false) ;
    cin.tie(0); cout.tie(0) ;

    getline(cin,a); 
    getline(cin,b);

    int len = b.length(); 
    int result = 0 ; 

    if( a.length() < len) { 
        cout << "0" << '\n';
        return 0 ;
    }

    for(int i = 0 ; i < a.length() - len + 1; i++) {
        string t = a.substr(i, len) ;
        if( t == b ) {
            i += (len-1) ; 
            result++;
        }
    }

    cout << result << '\n';
    return 0 ;
}