#include <iostream>
#include <algorithm>
using namespace std ;

int N, C; 
pair<pair<int,int>,int> arr[1001];

bool compare(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){ 
    if( a.first.second > b.first.second ) {
        return a.second > b.second;
    }else if( a.first.second == b.first.second) {
        if( a.second < b.second) {
            return true; 
        }
    }else{
        return false;
    }
    return false;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> C; 
    int num = 0, k = 0;
    for(int i = 0 ; i < N; i++) {
        cin >> num ;
        bool check = false; 
        for(int j = 0 ; j < k; j++){
            if( num == arr[j].first.first) {
                check = true; 
                arr[j].first.second++;
                break;
            }
        }
        if( !check ) {
            arr[k].first.first = num ;
            arr[k].first.second = 1 ;
            arr[k].second = k;
            k++;
        }
    }

    stable_sort(arr, arr+k, compare);

    for(int i = 0 ; i < k; i++) {
        for(int j = 0 ; j < arr[i].first.second; j++) {
            cout << arr[i].first.first << ' ';
        }
    }
    return 0 ;
}