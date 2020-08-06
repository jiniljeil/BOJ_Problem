#include <stdio.h>
#include <string.h>

#define MAX 1000001

int main(void){
    char str[MAX];
    int count = 1;
    scanf("%[^\n]s",str);
    
    for(int i = 0 ;i<strlen(str); i++){
        if(str[i] == ' ' && str[i+1] != '\0'){
            count++;
        }
    }
    if(str[0] == '\0' || str[0] == ' '){
        count--;
    }
    
    printf("%d\n",count);
    return 0;
}
