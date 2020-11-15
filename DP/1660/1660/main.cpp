#include <iostream>
#include <vector>
#define N 300001

using namespace std;

vector<int> store ;
int dp[N];

int result (int value) {
    for(int i = 0 ; i < store.size(); i++){
        for(int j = store[i] ; j<= value; j++){
            if( dp[j] > dp[j - store[i]] + 1){
                dp[j] = dp[j - store[i]] +1;
            }
        }
        
    }
    return dp[value];
}

int main(void){
    int s = 0 ;
    for(int i = 1 ;; i++){
        s += (i * (i + 1))/2 ;
        if( s > N -1 ) break;
        store.push_back(s);
    }
    for(int i = 1 ; i < N ; i++) dp[i] = N;
    int num = 0 ;
    scanf("%d",&num);
    
    for(int i = 0 ; i < store.size(); i++){
        dp[store[i]] = 1;
    }
    
    cout << result(num) << endl;

    return 0;
}
