#include <bits/stdc++.h>
#define SIZE 1010
using namespace std ;

string A, B ; 
int dp[SIZE][SIZE] ; 
int pcnt, cnt ;
string s ; 

void func(int i, int j) { 
    if ( dp[i][j] == 0 ) return ; 

    if ( A[i - 1] == B[j - 1] ) { 
        func( i - 1, j - 1 ) ; 
        cout << A[i - 1]; 
    } else { 
        if ( dp[i - 1][j] > dp[i][j - 1] ) { 
            func(i - 1, j) ; 
        } else{ 
            func(i , j - 1) ; 
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0) ;

    cin >> A >> B ;

    for (int i = 1 ; i <= A.size() ;i++) { 
        for (int j = 1 ; j <= B.size(); j++) { 
            if ( A[i - 1] == B[j - 1] ) { 
                dp[i][j] = dp[i - 1][j - 1] + 1 ;
            } else { 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) ; 
                
            }
        }
    }

    cout << dp[A.size()][B.size()] << '\n' ;

    func(A.size(), B.size()) ; 

    return 0; 
}