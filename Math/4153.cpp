#include <iostream> 
#include <algorithm>
using namespace std ;

int a,b,c; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    while (1) { 
        cin >> a >> b >> c ; 

        if ( a == 0 && b == 0 && c == 0) break; 
        int arr[3] = {a, b, c}; 
        sort(arr, arr + 3) ; 

        if ( ((arr[0] * arr[0]) + (arr[1] * arr[1])) == (arr[2] * arr[2])) {
            cout << "right" << '\n';
        } else { 
            cout << "wrong" << '\n'; 
        }
    }
    return 0 ;
}