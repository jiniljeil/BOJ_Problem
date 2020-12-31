#include <iostream> 

using namespace std;

int arr[2187][2187]; 
int minus1, zero, one ; 

void func(int x, int y, int size){
    int value = arr[y][x]; 
    bool check = true ;
    for(int i = y ; i < y+size; i++){
        for(int j = x ;j < x+size; j++){
            if( value != arr[i][j]){
                check = false;
                func(x,y, size/3);
                func(x + size/3, y, size/3);
                func(x + size * 2 / 3, y, size/3);
                func(x, y+size/3, size/3) ;
                func(x + size/3, y + size/3, size/3);
                func(x+ size * 2 / 3, y + size/3 , size/3); 
                func(x, y+size * 2 / 3, size/3);
                func(x + size /3, y + size *2 /3, size/3);
                func(x + size * 2 /3 , y + size * 2 /3 , size/3);
                break; 
            }
        }
        if(!check) break; 
    }

    if( check ){
        if( value == -1 ) {
            minus1++;
        }else if( value == 0 ){
            zero++;
        }else if( value == 1){
            one++;
        }
    }
}

int main(void){
    int size; 
    scanf("%d",&size);
    for(int i = 0 ; i < size; i++){
        for(int j = 0 ; j < size; j++){
            if(j == size - 1){
                scanf("%d",&arr[i][j]);
            }else{
                scanf("%d ",&arr[i][j]);
            }
        }
    }
    
    func(0,0,size);

    printf("%d\n%d\n%d\n", minus1, zero, one);
    return 0 ;
}