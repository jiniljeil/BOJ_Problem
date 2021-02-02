#include <iostream> 
#include <algorithm>
#include <vector> 
#include <string>
#include <stdlib.h>

using namespace std ;
int N; 
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> N;
    vector<long long> num; 
    for(int i = 0; i < N; i++) {
        string str ;
        cin >> str; 
        reverse(str.begin(), str.end());
        long long n = stoll(str);
        num.push_back(n); 
    }

    sort(num.begin(), num.end()); 

    for(int i = 0 ; i < N; i++) {
        cout << num[i] << '\n';
    }
    return 0 ;
}