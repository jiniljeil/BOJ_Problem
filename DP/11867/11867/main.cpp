#include <iostream>
using namespace std;
int a, b ;
int main(void){
    scanf("%d %d",&a,&b);
    if( a % 2 == 0 || b % 2 == 0) {
        printf("A");
    }else{
        printf("B");
    }
}
