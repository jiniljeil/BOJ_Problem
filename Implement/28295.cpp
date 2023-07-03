#include <bits/stdc++.h>

using namespace std ; 

char c = 'N' ; 
void func(int k) { 
    if ( c == 'N') { 
        if ( k == 1 ) c = 'E';
        else if ( k == 2 ) c = 'S';
        else if ( k == 3 ) c = 'W';
    } else if ( c == 'E') { 
        if ( k == 1 ) c = 'S';
        else if ( k == 2 ) c = 'W';
        else if ( k == 3 ) c = 'N';
    } else if ( c == 'W') { 
        if ( k == 1 ) c = 'N';
        else if ( k == 2 ) c = 'E';
        else if ( k == 3 ) c = 'S';
    } else {
        if ( k == 1 ) c = 'W';
        else if ( k == 2 ) c = 'N';
        else if ( k == 3 ) c = 'E';
    }
}
int main() { 
    ios::sync_with_stdio(0); cin.tie(0) ; 
    for (int i = 0 ; i < 10 ;i++ ) {
        int k ; cin >> k ;  
        func(k) ;  
    }

    cout << c << '\n';
    return 0 ;  
}