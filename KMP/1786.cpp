#include <iostream>
#include <string> 
#include <vector> 

using namespace std;

vector<int> pi_set(const string& pattern) {
    int m = pattern.length(); 
    vector<int> pi(m, 0);
    int begin = 1, matched = 0 ; 
    
    while((begin + matched < m)) {
        if(pattern[begin + matched] == pattern[matched]) {
            matched++; 
            pi[begin + matched - 1] = matched ; 
        }else{
            if(matched == 0) begin++;
            else{
                begin += (matched - pi[matched - 1]); 
                matched = pi[matched - 1]; 
            }
        }
    }
    return pi ;
}

vector<int> kmpSearch(const string& sentence, const string& pattern) {
    vector<int> ret; 
    int n = sentence.length(); 
    int m = pattern.length(); 
    int begin = 0, matched = 0; 

    vector<int> pi = pi_set(pattern); 

    while((begin <= n - m)) {
        if( (matched < m) && sentence[begin + matched] == pattern[matched]) {
            matched++; 
            if(matched == m) ret.push_back(begin); 
        }else{
            if(matched == 0) begin++;
            else {
                begin += (matched - pi[matched - 1]);
                matched = pi[matched - 1]; 
            }
        }
    }
    return ret ;
}   

int main(void) {
    ios::sync_with_stdio(false) ;
    cin.tie(0); cout.tie(0) ;

    string sentence, pattern;
    getline(cin, sentence); 
    getline(cin, pattern); 

    vector<int> ret = kmpSearch(sentence, pattern); 
    cout << ret.size() << '\n'; 
    for(int i = 0 ; i < ret.size(); i++){
        cout << ret[i] + 1 << '\n'; 
    }
    return 0; 
}