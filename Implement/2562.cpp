#include <iostream> 

using namespace std;

int main(void){
    int th ; 
    int max = 0 ;
    int arr[9]; 

    for(int i = 0 ; i < 9; i++){
        scanf("%d",&arr[i]); 
        if( arr[i] >= 100 || arr[i] < 0 ) return 0;
        else {
            if( max < arr[i]){
                max = arr[i]; 
                th = i; 
            }
        }
    }
    printf("%d\n%d\n", max,th+1);
    
    return 0;
}