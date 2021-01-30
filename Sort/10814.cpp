#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N ;
pair<int, string> user[100001];

bool compare(pair<int,string> a, pair<int,string> b) {
    return a.first < b.first;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N ;

    for(int i = 0 ; i < N; i++) {
        cin >> user[i].first >> user[i].second ; 
    }
    stable_sort(user,user+N, compare);
    for(int i = 0 ; i < N; i++) {
        cout << user[i].first << ' ' << user[i].second << '\n';
    }
    return 0;
}