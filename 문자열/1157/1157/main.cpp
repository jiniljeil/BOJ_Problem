#include <iostream>
#include <string>

using namespace std;

int main(void){
    string str;
    int cnt[26] = { 0 };
    int max = 0 , check = 0 , index = 0 ;
    
    cin >> str;
    
    for(int i = 0 ; i < str.length(); i++){
        if((int)str[i] >= 97 && (int)str[i] <= 122){ // 97 65
            str[i] -= 32;
        }
        cnt[(int)str[i] - 65]++;
    }
    
    for(int j = 0 ; j < 26 ; j++){
        if( max < cnt[j]){
            max = cnt[j];
            index = j ;
        }
    }
    
    for(int i = 0 ; i<26; i++){
        if( i != index && max == cnt[i]){
            check = 1;
        }
    }
    if(check == 1 ){
        printf("?\n");
    }else if(check == 0){
        printf("%c\n", 65+index);
    }
    return 0;
}
