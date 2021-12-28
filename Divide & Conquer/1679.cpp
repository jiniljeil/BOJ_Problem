#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int num;
    vector<int> givenNum;
    scanf("%d",&num);
    
    for(int i = 0 ; i < num; i++){
        int t ;
        scanf("%d",&t);
        givenNum.push_back(t);
    }
    
    sort(givenNum.begin(),givenNum.end(),greater<int>());
    
    int limitNum = 0 ;
    scanf("%d",&limitNum);
    
    for(int i = 1 ;; i++){
        int value = i;
        if(i%2 != 0){ // 홀수
            int count = 0;
            for(int j = 0 ; j < givenNum.size(); j++){
                int k = givenNum[j];
                for(int z = 0;;z++){
                    if(value - k < 0){
                        break;
                    }else{
                        value = value - k ;
                        count++;
                        if(value == 0) break;
                    }
                }
            }
            if( count > limitNum || (value != 0)){
                cout << "jjaksoon win at " << i << endl;
                break;
            }
        }else{ // 짝수
            int count = 0;
            for(int j = 0 ; j < givenNum.size(); j++){
                int k = givenNum[j];
                for(int z = 0; ;z++){
                    if(value - k < 0){
                        break;
                    }else{
                        value -= k ;
                        count++;
                        if(value == 0) break;
                    }
                }
            }
            if( count > limitNum || (value != 0)){
                
                cout << "holsoon win at " << i << endl;
                break;
            }
        }
    }
    return 0;
}
