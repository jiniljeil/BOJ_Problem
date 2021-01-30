#include <iostream>
#include <algorithm>
using namespace std ;

int N ;

pair<pair<string, int> , pair<int,int> > v[100001];

bool compare(pair<pair<string, int> , pair<int,int> > a , pair<pair<string, int> , pair<int,int> > b) {
    if( a.first.second > b.first.second) { 
        return a.first.second > b.first.second; 
    }else if( a.first.second == b.first.second) {
        if( a.second.first < b.second.first) { 
            return true;
        }else if(a.second.first == b.second.first){
            if( a.second.second > b.second.second) { 
                return true; 
            }else if( a.second.second == b.second.second) { 
                return a.first.first < b.first.first;
            }else{ 
                return false; 
            }
        }else{
            return false; 
        }
    }else{
        return false; 
    }
}
int main(void) { 
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N ;
    for(int i = 0 ;i < N ;i++ ) {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second; 
    }

    stable_sort(v, v+ N, compare);

    for(int i = 0 ; i < N; i++) {
        cout << v[i].first.first << '\n';
    }
    return 0 ; 
} 