#include <stdio.h>
#include <string.h>

int main(void){
    char str[101];
    int index[26] = { 0 };
    
    while(1){
        int check = 1;
        scanf("%s",str);
        for(int i = 0; i<strlen(str); i++){
            if(!((int)str[i] >= 97 && (int)str[i] <= 122)){ // 소문자
                check = 0;
            }
        }
        if(check == 1){
            break;
        }
    }
    for(int j = 0 ; j< 26 ; j++) index[j] = -1;
    
    for(int i = 0 ; i<strlen(str); i++){
        if(index[(int)str[i] - 97] == -1){
             index[(int)str[i] - 97] = i;
        }
    }
    
    for(int i = 0 ; i < 26 ; i++){
        printf("%d ", index[i]);
    }
    return 0;
}
