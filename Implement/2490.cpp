#include <iostream>

using namespace std;

int main(void){
    int arr[3][4] ;
    char result[3] ; 
    for(int i = 0 ; i < 3; i++)
        for(int j = 0 ; j < 4; j++)
            scanf("%d", &arr[i][j]);
    
    for(int i = 0 ; i < 3; i++){
        int count = 0; 
        for(int j = 0 ; j < 4; j++){
            if( arr[i][j] == 0){
                count++; 
            }
        }
        if( count == 0){
            result[i] = 'E';
        }else if( count == 1){
            result[i] = 'A';
        }else if( count == 2){
            result[i] = 'B';
        }else if( count == 3){
            result[i] = 'C';
        }else if( count == 4){
            result[i] = 'D';
        }
    }
    for(int i = 0 ; i < 3 ;i++) printf("%c\n", result[i]);
    return 0;
}
