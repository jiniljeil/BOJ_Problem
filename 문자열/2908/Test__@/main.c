#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *change(char n1[], char n2[], int *arr);

int main(void){
    char num1[4],num2[4];
    int *num;
    
    num = (int*)malloc(sizeof(int) * 2);
    
    while(1){
        int check = 0;
        scanf("%s %s",num1, num2);
        
        for(int i = 0 ; i< 3 ; i++){
            if(num1[i] == '0' || num2[i] == '0'){
                check = 1;
            }
        }
        
        if(check == 0 && strncmp(num1,num2,3) != 0){
            break;
        }
    }
    
    num = change(num1,num2,num);
    
    if(num[0] > num[1]){
        printf("%d",num[0]);
    }else{
        printf("%d",num[1]);
    }
    return 0;
}

int *change(char n1[], char n2[], int *arr){ // 123 -> 321
    int temp = n1[0];
    n1[0] = n1[2];
    n1[2] = temp;
    
    temp = n2[0];
    n2[0] = n2[2];
    n2[2] = temp;
    
    int n_1 = atoi(n1);
    int n_2 = atoi(n2);
    
    arr[0] = n_1;
    arr[1] = n_2;
    return arr;
}
