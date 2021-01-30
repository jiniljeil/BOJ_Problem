#include <iostream>
#include <algorithm>
using namespace std ;

int N ;
pair<int, int> v[100001];
bool compare(pair<int,int> a, pair<int,int> b) {
    if( a.second < b.second) {
        return true; 
    }else{
        if( a.second == b.second) {
            return a.first < b.first;
        }else{
            return false;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> N; 
    for(int i = 0 ; i < N; i++) {
        cin >> v[i].first >> v[i].second ;
    }
    sort(v, v+N, compare);

    for(int i = 0 ; i < N; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}