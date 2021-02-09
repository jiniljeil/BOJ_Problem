#include <iostream>
#include <algorithm> 
using namespace std ;

int N ; 
pair<int,int> arr[100001]; 

bool compare(pair<int,int> a , pair<int,int> b) { 
    if( a.second == b.second) {
        return a.first < b.first ;
    }else{
        return a.second < b.second;
    }
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> N; 
    int m = 0 ; 
    for(int i = 0 ; i <  N; i++) {
        cin >> arr[i].first >> arr[i].second;
        if( m < arr[i].second) { 
            m = arr[i].second; 
        }
    }

    stable_sort(arr, arr + N, compare); 
    int result = 0; 
    int curr = 0;
    
    for(int i = 0 ; i < N; i++) {
        if(arr[i].first >= curr) {
            result++;
            curr = arr[i].second;
        }
    }

    cout << result << '\n';
    return 0; 
}