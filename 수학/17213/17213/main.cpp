#include <iostream>

using namespace std;

double johap(int a, int b){
    double top = 1;
    double bottom = 1;
    for(int i = a; i > a-b; i-- ){
        top *= i ;
    }
    for(int i = b; i >= 1; i--){
        bottom *= i;
    }
    return top/bottom ;
}

/*
a + b + c = 10
A + b  + c  = 7

3 H 7 = 9 C 7 = 9 C 2  = 9 8 / 2 1
*/


int main(void){
    int numType, numFruit;
    
    scanf("%d" , &numType);
    scanf("%d", &numFruit);
    
    if( numType > 0 && numType <= numFruit){
        printf("%.0lf", johap(numFruit-1 , numFruit - numType));
    }

    return 0;
}
