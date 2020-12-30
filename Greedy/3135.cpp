#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int a, b;
    scanf("%d %d",&a,&b);
    int gap = 11111;
    int num = 0 ;
    scanf("%d",&num);
    
    int *button = (int*) malloc(sizeof(int) * num);
    for(int i = 0 ; i < num; i++)
    {
        int tmp ;
        scanf("%d",&tmp);
        if( gap > abs(b-tmp)) gap = abs(b-tmp);
    }
    
    if( gap + 1 < abs(b-a)){
        gap = gap + 1;
    }else{
        gap = abs(b-a);
    }
    
    cout << gap << endl;;
    
    free(button);
    return 0;
}
