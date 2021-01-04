#include <iostream>

using namespace std ;
int cnt[26];
int main(void){
     
    string str; 
    cin >> str; 
    for(int i = 0 ; i < str.length(); i++){
        if( str[i] - 97 >= 0 && str[i] -97 <= 25){ 
            cnt[str[i] -97] += 1;
        }
    }
    for(int i = 0 ; i < 26; i++){
        cout << cnt[i] << " "; 
    }
    return 0;
}