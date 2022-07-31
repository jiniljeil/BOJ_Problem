#include <iostream> 
#include <string> 
#include <cstring> 
using namespace std ; 

int N ; 
string one, two, third ; 
int one_length, two_length, third_length ; 
int dp[201][201] ; 
void Init() { 
    memset(dp, -1, sizeof(dp)) ; 
}
void Input() { 
    cin >> one >> two >> third ; 

    one_length = one.length() ;  
    two_length = two.length() ; 
    third_length = third.length() ; 
}

int dfs(int one_idx, int two_idx, int third_idx) {  
    if ( third_idx == third_length) return 1 ; 

    int &ret = dp[one_idx][two_idx] ; 

    if ( ret != -1 ) return ret; 
    ret = 0 ; 

    if ( one_idx < one_length && third[third_idx] == one[one_idx] ) ret = dfs(one_idx + 1, two_idx, third_idx + 1) ; 
    if ( two_idx < two_length && third[third_idx] == two[two_idx] ) ret = max(ret, dfs(one_idx, two_idx + 1, third_idx + 1));  

    return ret ; 
}

int main(void) { 
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ;

    cin >> N ; 

    for (int i = 0 ; i < N ;i++ ) { 
        Init() ; 

        Input() ;

        if ( dfs(0, 0, 0) ) { 
            cout << "Data set " << i + 1 << ": yes" << '\n' ; 
        } else { 
            cout << "Data set " << i + 1 << ": no" << '\n'; 
        }
    }

    return 0 ;
}