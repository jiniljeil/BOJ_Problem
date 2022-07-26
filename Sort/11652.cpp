#include <iostream> 
#include <map> 
#include <vector> 
#include <algorithm>
using namespace std; 

int N ; 
long long tmp ; 
map<long long, int> M ; 

bool compare(const pair<long long,int>&a, const pair<long long,int> &b)  {
    if ( a.second == b.second ) return a.first < b.first ; 
    else return a.second > b.second ; 
}
int main(void) { 
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; 

    cin >> N ; 

    for (int i = 0 ; i < N; i++) { 
        cin >> tmp ; 

        M[tmp]++; 
    }

    vector<pair<long long, int> > V (M.begin(), M.end()) ; 

    sort(V.begin(), V.end(), compare) ; 

    cout << V[0].first << '\n' ;
    return 0; 
}