#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long int num =0 ;
    scanf("%lld",&num);
    
    for(int i =0 ; i < num; i++){
        long long int t = 0;
        scanf("%lld",&t);
        vector<long long int> v ;
        for(int j = 0 ; j < t; j++){
            long long int tp = 0 ;
            scanf("%lld",&tp);
            v.push_back(tp);
        }
        long long int max = -1;
        long long int sum = 0;
        
        for(int j = v.size()-1; j >=0 ; j--){
            if ( max < v[j]){
                max = v[j];
            }else{
                sum += (max - v[j]);
            }
        }
        printf("%lld\n",sum);
    }
    
    return 0;
}
