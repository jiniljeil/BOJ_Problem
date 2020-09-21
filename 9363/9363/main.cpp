#include <iostream>

using namespace std;

long long int uclrid(long long int a , long long int b){
    if( a % b == 0){
        return b ;
    }else{
        long long int c = a % b ;
        return uclrid(b, c);
    }
}

int main(void){
    int cases ;
    
    scanf("%d",&cases);
    
    for(int i = 0 ; i <cases; i++){
        int na, nb;
        scanf("%d %d",&na,&nb);
        
        long long int sumA =1 , sumB=1;
        for(int j = 0 ; j < na; j++){
            int t;
            scanf("%d",&t);
            sumA *= t;
        }
        for(int j = 0 ; j < nb; j++){
            int t;
            scanf("%d",&t);
            sumB *= t;
        }
        long long int ra = sumA / uclrid(sumA, sumB),rb = sumB / uclrid(sumA, sumB);
        printf("Case #%d: %lld / %lld\n",i+1, ra,rb);
    }
    return 0;
}
