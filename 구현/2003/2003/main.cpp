#include <iostream>
#include <vector>

using namespace std;
long long int num, value, result;
vector<int> v;

int main(void){
    scanf("%lld %lld",&num,&value);
    
    for(int i = 0 ; i < num; i++){
        int t = 0 ;
        scanf("%d", &t) ;
        v.push_back(t);
    }
    
    for(int i= 0 ; i < v.size(); i++){
        int curr = i ;
        int sum = 0 ;
        for(int j = curr ; j < v.size(); j++){
            sum += v[j];
            if( sum == value){
                result++;
            }else if(sum > value){
                break;
            }
        }
    }
    printf("%lld",result);
    return 0;
}
