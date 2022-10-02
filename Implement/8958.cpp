#include <iostream> 
#include <string> 
using namespace std; 
int N ;
string s; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ;

    cin >> N ; 

    for (int i = 0 ; i < N ;i++) { 
        cin >> s ;
        long long answer = 0 ;
        int cnt = 0 ; 
        for ( int j = 0 ; j < s.length() ; j++) {
            if ( s[j] == 'O' ) { 
                cnt++; 
            } else if ( s[j] == 'X'){ 
                cnt = 0 ; 
            }
            answer += cnt ; 
        }
        cout << answer << '\n'; 
    }
    
    return 0 ;
}