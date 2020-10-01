#include <iostream>

using namespace std;

void check(long long int boxA[], long long int boxB[], long long int &sumA, long long int &sumB, int sizeA, int sizeB){
    sumA = 1;
    sumB = 1;
    
    for(int i = 0; i < sizeA; i++){
        for(int j = 0 ; j < sizeB; j++){
            if( boxA[i] != 1 && boxB[j] != 1 && boxA[i] == boxB[j]){
                boxA[i] = boxB[j] = 1;
                break;
            }
        }
    }
    
    for(int i = 0 ; i < sizeA; i++){
        if( boxA[i] != 1){
            sumA *= boxA[i];
        }
    }
    for(int i = 0 ; i < sizeB; i++){
        if( boxB[i] != 1){
            sumB *= boxB[i];
        }
    }
}

long long int uclrid(long long int a , long long int b){
    if( a % b == 0){
        return b ;
    }else{
        return uclrid(b, a%b);
    }
}


int main(void){
    int cases ;
    long long int boxA[110001] = { 0,};
    long long int boxB[110001] = { 0,};
    
    scanf("%d",&cases);
    
    for(int i = 0 ; i <cases; i++){
        int na, nb;
        scanf("%d %d",&na,&nb);
        
        long long int sumA = 1 , sumB = 1;
        for(int j = 0 ; j < na; j++){
            int t;
            scanf("%d",&t);
            if(t == 0){
                return 0;
            }
            boxA[j] = t;
        }
        for(int j = 0 ; j < nb; j++){
            int t;
            scanf("%d",&t);
            if(t == 0){
                return 0;
            }
            boxB[j] = t;
        }
        
        check(boxA,boxB,sumA,sumB,na,nb);
        
        
        double ra = sumA / uclrid(sumA, sumB),rb = sumB / uclrid(sumA, sumB);
        printf("Case #%d: %.0lf / %.0lf\n",i+1, ra,rb);
        
        for(int j = 0 ; j <na; j++){
            boxA[j] = 0;
        }
        
        for(int j = 0 ; j <nb; j++){
            boxB[j] = 0;
        }
    }
    return 0;
}

/*
 1
 10 10
 1000000 999999 888888 777777 666666 555555 444444 333333 222222 111111
 298438 928381 923857 827384 381723 374823 758213 728473 847273 172374
 */
