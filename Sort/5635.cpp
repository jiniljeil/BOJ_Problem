#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std ;

int k ; 

vector< pair<pair<int, int>, pair<int, string> > > P ; 
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0) ;

    cin >> k ;
    for (int i = 0 ; i < k ; i++) {
        string s ; int year, month, day; 
        cin >> s >> day >> month >> year ; 

        P.push_back(make_pair(make_pair(year, month), make_pair(day, s))) ; 
    }

    sort(P.begin(), P.end()) ; 

    cout << P[P.size() - 1].second.second << '\n' << P[0].second.second << '\n';  
    return 0 ; 
}