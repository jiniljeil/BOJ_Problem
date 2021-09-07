#include <iostream>
#include <string.h> 
#include <vector> 
#define MAX 1001
using namespace std; 

int n, max_len;
vector<int> v; 
int arr[MAX]; 
int dp[MAX]; 
vector<int> set[MAX]; 
vector<int> result ; 
// Longest Increasing Sequence 
int LIS_DP() { 
    for(int i = 0 ; i < n ; i++) {
        dp[i] = 1; 
        set[i].push_back(arr[i]); 
        for(int j = i+1 ; j < n; j++){ 
            if (arr[i] < arr[j]) { 
                set[i].push_back(arr[i]); 
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> n ;
    for(int i = 0 ; i < n; i++) { 
        cin >> arr[i]; 
    }
    memset(dp, -1, sizeof(dp)); 

    int result = LIS_DP(); 
    cout << result << '\n'; 

    return 0; 
}