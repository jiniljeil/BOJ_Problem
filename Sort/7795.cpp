#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std; 
int N;
int A[20001];
int B[20001];
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;

    cin >> N; 

    while(N--) {
        int a, b ;
        cin >> a >> b; 
        memset(A, 0, sizeof(A)); 
        memset(B, 0, sizeof(B));
        for(int i = 0 ; i < a ;i++) {
            cin >> A[i]; 
        }
        for(int i = 0 ; i < b; i++) {
            cin >> B[i];
        }
        sort(A, A+a);
        sort(B, B+b);
        int start = 0, end = b -1 ; 
        int mid;
        int result = 0 ;
        for(int i = 0 ; i < a; i++) {
            int key = A[i];
            int k = 0;
            while( k < b && B[k] < key) {
                k++;
            }
            result += k;
        }
        cout << result << '\n';
    }
    return 0 ;
}