#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

vector<string> v; 

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    string str ;
    cin >> str; 

    for(int i = 0 ; i < str.length(); i++) {
        string s = str.substr(i,str.length());
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
    return 0;
}