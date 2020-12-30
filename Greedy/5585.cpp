#include <iostream>

using namespace std;

int main(void){
    int money = 1000;
    int m ;
    scanf("%d",&m);
    
    money = 1000 - m ;
    
    int arr[6] = {500,100,50,10,5,1};
    int count = 0;
    while(money != 0){
        for(int i = 0 ; i < 6; i++){
            if(money%arr[i] != money){
                count += money/arr[i];
                money %= arr[i];
                break;
            }
        }
    }
    cout << count << endl;
    return 0;
}
