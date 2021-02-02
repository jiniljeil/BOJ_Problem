#include <iostream>
#include <algorithm>

using namespace std ;

int N;
long long arr[100001];
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> N; 
    for(int i = 0; i < N; i++) {
        cin >> arr[i]; 
    }

    sort(arr, arr+N); 

    long long int m = 0, c = 0;
    long long int num = 0;
    for(int i = 0 ; i < N; i++) {
        c++;
        if(i + 1 <= N && arr[i] != arr[i+1]) { // 마지막에도 업데이트 되어야하므로 = 넣기 
            if( m < c ) {
                num = arr[i];
                m = c; 
            }else if( m == c ) {
                if( num > arr[i]) {
                    num = arr[i];
                }
            }
            c = 0 ;
        }
    }
    cout << num << '\n';
    return 0;
}