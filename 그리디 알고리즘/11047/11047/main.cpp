#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int numCoin, money;
    
    scanf("%d %d",&numCoin, &money);
    vector<int> arr (numCoin, 0);
    
    for(int i = 0 ; i < arr.size(); i++){
        scanf("%d",&arr[i]);
    }
    
    int count = 0 ;
    while(money != 0){
        for(int i = numCoin-1; i >= 0 ; i--){
            if(money%arr[i] != money){
                count += (money/arr[i]);
                money = money%arr[i];
//                cout << "i <" << i << "COUNT " << count << endl;
                break;
            }
        }
    }
    printf("%d",count);
    return 0;
}
