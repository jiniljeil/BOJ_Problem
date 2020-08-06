#include <iostream>
#include <string>
using namespace std;

int main(void){
    char str[1000] = { 0 , };
    
    cin >> str ;
    
    string tmp(str);
    
    for(int i = 0 ; i < tmp.length() ; i++){
        if( str[i] - 65 < 3 ){
            str[i] = str[i] + 26 - 3 ;
        }else{
            str[i] = str[i] - 3;
        }
    }
    cout << str << endl;
    return 0;
}
