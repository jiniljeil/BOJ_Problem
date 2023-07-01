#include <bits/stdc++.h>

using namespace std ;

int N, M ; 
int arr[100010] ;
int sum[100010] ;
int main() { 
    ios::sync_with_stdio(0); cin.tie(0) ;
    cin >> N >> M ; 

    for (int i = 0 ; i < N ;i++)  {
        cin >> arr[i]; 
        sum[i + 1] = sum[i] + arr[i] ;  
    }

    for (int i = 0 ; i < M ; i++) { 
        int a, b; cin >> a >> b; 
        cout << sum[b] - sum[a - 1] << '\n' ;
    }

    return 0;
}