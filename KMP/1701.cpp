#include <iostream>
#include <string>
#include <vector> 

using namespace std; 

vector<int> pi_set(const string& pattern) { 
    int m = pattern.length();
    vector<int> pi(m, 0); 
    int begin = 1, matched = 0 ; 

    while(begin + matched < m) {
        if(pattern[begin + matched] == pattern[matched]) {
            matched++; 
            pi[begin + matched - 1] = matched ; 
        }else{
            if(matched == 0) begin++; 
            else{
                begin += matched - pi[matched - 1] ;
                matched = pi[matched - 1] ; 
            }
        }
    }
    return pi; 
}

int main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;

    string sentence ; 
    getline(cin, sentence); 
    int ret = 0 ; 
    
    for(int i = 0 ; i < sentence.length(); i++) { 
        // point 
        string sub = sentence.substr(i, sentence.length());
        vector<int> pi = pi_set(sub); 

        for(int j = 0 ; j < pi.size(); j++) { 
            ret = max(ret, pi[j]); 
        }
    }
    cout << ret << '\n';

    return 0;
}