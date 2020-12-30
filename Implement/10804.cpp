#include <iostream>

using namespace std;

int main(void){
    int arr[20] ;

    for(int i = 0 ; i < 20; i++){
        arr[i] = i+1; 
    }

    for(int i = 0 ; i < 10; i++ ){
        int p1,p2 ;
        int k = 0 ; 
        scanf("%d %d",&p1,&p2);
        int *tmp = new int[p2-p1+1];
        p1 -= 1; p2 -= 1; 
        for(int j = p1; j <= p2; j++){
            tmp[k] = arr[j]; 
            k++; 
        }
        for(int j = p1; j <= p2; j++){
            k--;
            arr[j] = tmp[k];
        }
        free(tmp);
    }
    for(int i = 0 ; i < 20; i++) printf("%d ",arr[i]);
    printf("\n");
    
    return 0;
}