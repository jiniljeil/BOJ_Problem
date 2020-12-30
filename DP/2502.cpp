#include <iostream>

using namespace std;
int day, num;
int first, second ;
int ca = 1;
int cb = 1;
int main(int argc, const char * argv[]) {
    
    scanf("%d %d",&day,&num);
    
    int *arrA = new int[day];
    int *arrB = new int[day];
    
    for(int i = 0 ; i < day; i++){
        arrA[i] = 0 ;
        arrB[i] = 0 ;
    }
    arrA[0] = 1;
    arrB[1] = 1;
    
    for(int i = 2 ; i < day; i++){
        arrA[i] = arrA[i-1] + arrA[i-2];
        arrB[i] = arrB[i-1] + arrB[i-2];
    }
    bool check = false;
    for(int i = 1; i < num; i++){
        for(int j = 0 ; j < num; j++){
            if( j * arrB[day-1] + i * arrA[day-1] == num){
                first = i;
                second = j;
                check = true;
                break; 
            }
        }
        if(check) break;
    }
    
    printf("%d\n%d",first, second);
    free(arrA);
    free(arrB);
    return 0;
}
