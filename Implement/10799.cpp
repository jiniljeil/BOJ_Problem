#include <iostream>
#include <string>
#include <stack> 

using namespace std; 

stack<int> s ; 
int main(void){
    int c = 0 ;
    string str ;
    cin >> str ;
    char before ;
    for(int i = 0 ; i < str.length(); i++) {
        if( str[i] == '(') {
            s.push(str[i]) ; 
        }else{ 
            if( before == '(') {
                c += s.size() - 1; 
            }else{
                c++; 
            }
            s.pop(); 
        }
        before = str[i]; 
    }
    cout << c << "\n";
    return 0;
}