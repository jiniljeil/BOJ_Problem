#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    int sum = 0;
    scanf("%d",&n);
    vector<int> arr (n, 0);
    for(int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    sort(arr.begin(), arr.end());
    
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j <= i; j++){
            sum += arr[j];
        }
    }
    cout << sum << endl;
    return 0;
}
