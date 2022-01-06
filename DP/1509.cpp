#include <iostream> 
#include <string> 
#define MAX 2501

using namespace std ;

bool Palindrome[MAX][MAX]; 
int dp[MAX]; 

string str; 
int length ; 

void DP() {
    for (int i = 1 ; i <= length ; i++) {
        // length 1 
        Palindrome[i][i] = true; 

        if ( i < length ) { 
            // length 2 
            if ( str[i - 1] == str[i] ) Palindrome[i][i + 1] = true; 
        }
    }

    // LENGTH 3 ~ N-1 
    for (int len = 3; len <= length ; len++) {
        for (int start = 1 ; start + len - 1 <= length; start++) { 
            int end = start + len - 1; 
            if ( str[start - 1] == str[end - 1] && Palindrome[start + 1][end - 1] ) { 
                Palindrome[start][end] = true; 
            }
        }
    }
    
    for (int end = 1; end <= length ; end++) {
        dp[end] = 1e9 ; 
        for(int start = 1; start <= length ; start++) {
            if ( Palindrome[start][end] ) { 
                dp[end] = min(dp[end], dp[start - 1] + 1) ; 
            }
        }
    }

    cout << dp[length] << '\n';
}

void Input() {
    cin >> str; 
    length = str.length(); 
}

int main(void) { 
    ios::sync_with_stdio(false);
    cin.tie(0) ; 

    Input(); 
    DP(); 

    return 0 ;
}