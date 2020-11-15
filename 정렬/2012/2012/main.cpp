#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

long long int num, result;
vector<long long int> arr;

int main(int argc, const char * argv[]) {
    scanf("%lld",&num);
    
    for(int i = 0 ; i < num; i++){
        long long int t = 0;
        scanf("%lld",&t);
        arr.push_back(t);
    }
    
    sort(arr.begin(),arr.end());
    
    for(int i = 1 ; i <= num; i++){
        result += abs(i - arr[i-1]);
    }
    printf("%lld",result);
    return 0;
}
