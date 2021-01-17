#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std; 
int N; 
vector<string> v; 

bool compare(const string a, const string b) {
    if( a.length() == b.length()){ 
        int a_s = 0, b_s = 0 ; 
        for(int i = 0 ; i < a.length(); i++) {
            if( a[i] >= '0' && a[i] <= '9') {
                a_s += (a[i] - '0'); 
            }
            if( b[i] >= '0' && b[i] <= '9') {
                b_s += (b[i] - '0'); 
            }
        }
        if( a_s == b_s) { 
            return a < b; 
        }else{
            return a_s < b_s; 
        }
    }else{
        return a.length() < b.length();
    }
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;

    cin >> N; 
    string str = ""; 
    for(int i = 0 ; i < N; i++) {
        cin >> str ; 
        v.push_back(str);
        str = "";
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0 ; i < N; i++) {
        cout << v[i] << '\n';
    }
    return 0 ;
}