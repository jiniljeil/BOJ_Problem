#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>
using namespace std; 

vector<char> v ;
string s ;

bool compare(const char& c1, const char& c2 ) {
    if ( c1 > c2 )  {
        return true ;
    } else { 
        return false ; 
    }
}
int main(void) { 
    string s ;
    cin >> s; 
    for (int i = 0 ; i < s.size(); i++)  {
        v.push_back(s[i]) ; 
    }
    sort(v.begin(), v.end(), compare); 

    for (int i = 0 ; i < v.size(); i++) { 
        cout << v[i]; 
    }
    return 0; 
}