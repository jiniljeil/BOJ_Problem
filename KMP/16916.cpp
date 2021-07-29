#include <iostream> 
#include <vector> 

using namespace std ;

vector<int> getPartialMatch(const string &pattern) {
    int m = pattern.length(); 
    vector<int> pi (m, 0); 

    int begin = 1, matched = 0 ; 
    while(begin + matched < m) {
        if( pattern[begin + matched] == pattern[matched] ) {
            matched++; 
            pi[begin + matched - 1] = matched ; 
        }else{
            if (matched == 0) begin++; 
            else{
                begin += (matched - pi[matched - 1]);
                matched = pi[matched - 1] ;
            }
        }
    }
    return pi; 
}

int kmpSearch(const string &text, const string &pattern) {
    int n = text.length(), m = pattern.length(); 
    vector<int> ret ; 
    vector<int> pi = getPartialMatch(pattern) ;
    int begin = 0, matched = 0 ; 
    while(begin <= n - m) { 
        if( matched < m && text[begin + matched] == pattern[matched]) { 
            matched++; 
            if( matched == m ) ret.push_back(begin); 
        }else{
            if( matched == 0) begin++; 
            else {
                begin += (matched - pi[matched - 1]); 
                matched = pi[matched - 1]; 
            }
        }
    }
    return !ret.empty(); 
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0) ;cout.tie(0) ;

    string text, pattern ; 

    cin >> text >> pattern; 

    int ret = kmpSearch(text, pattern); 
    cout << ret << '\n' ;
    return 0; 
}