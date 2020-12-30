#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
vector<string> v;
set<string> s ;

bool compare(string a, string b){
    if(a.length() == b.length()){
        return a < b;
    }else{
        return a.length() < b.length();
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n ;
    cin >> n;
    
    for(int i = 0 ; i < n ;i++){
        string t ;
        cin >> t;
        s.insert(t);
    }
    set<string>::iterator iter;
    for(iter = s.begin() ; iter != s.end() ; iter++){
        v.push_back(*iter);
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0 ; i < v.size(); i++){
        cout << v[i] << endl;
    }
    
    return 0;
}
