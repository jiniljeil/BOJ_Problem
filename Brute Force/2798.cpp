#include <iostream>

using namespace std;

int main(void){
    
    int num, sum ;
    int max = 0 ;
    int *arr;
    scanf("%d %d",&num,&sum);
    
    arr = new int[num];
    for(int i = 0 ; i < num; i++){
        scanf("%d",&arr[i]);
    }
    
    for(int i = 0 ; i < num; i++){
        for(int j = i+1 ; j < num; j++){
            for(int k = j+1 ; k < num; k++){
                int s = arr[i] + arr[j] + arr[k];
                
                if( max < s && s <= sum){
                    max = s ;
                }
            }
        }
    }
    cout << max;
    return 0;
    
}
