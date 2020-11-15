#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int main(int argc, const char * argv[]) {
    int num;
    scanf("%d",&num);
    
    for(int i = 0 ; i < num; i++){
        int t = 0 ;
        scanf("%d",&t);
        
        arr.push_back(t);
    }
    
    sort(arr.begin(),arr.end());
    
    for(int i = 0 ; i < num; i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
