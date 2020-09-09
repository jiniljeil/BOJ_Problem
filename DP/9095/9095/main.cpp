#include <iostream>

using namespace std;

int c = 0 ;

void count1(int value, int num){
    if(value < num ) return ;
    else if( value == num ){
        c++;
        return;
    }else{
        for(int i = 1; i <= 3 ; i++){
            count1(value, num+i);
        }
    }
}

int main(void){
    int num ;
    scanf("%d",&num);
    
    for(int i = 0; i < num; i++){
        int t ;
        scanf("%d",&t);
        count1(t,0);
        
        cout << c << endl ;
        c = 0 ;
    }
    return 0;
    
}
