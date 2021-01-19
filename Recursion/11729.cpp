#include <iostream>
#include <vector>
using namespace std;

int N, K ; 
vector<pair<int,int> > v; 
void hanoi(int n, int from, int by, int to) {
    if( n == 1) {
        K++;
        v.push_back(make_pair(from, by));
        return ;
    }
    
    hanoi(n-1, from, to, by);
    K++;
    v.push_back(make_pair(from, by));
    hanoi(n-1, to, by, from);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N ;

    
    hanoi(N, 1, 3, 2);
    cout << K << '\n';
    for(int i = 0 ; i < v.size(); i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}