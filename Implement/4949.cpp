#include <iostream>
#include <stack> 
using namespace std; 


int main(void){
    string str; 
    do {
        str = "" ;
        stack<char> s ;
        getline(cin, str) ;
        
        bool check = false; 
        for(int i = 0 ; i < str.length(); i++) {
            if(str[i] == '(' || str[i] == '[') {
                s.push(str[i]) ;
            }
            if(str[i] == ')') {
                if( s.empty() ) {
                    check = true; 
                    cout << "no" << "\n";
                    break; 
                }
                if( s.top() == '(') {
                    s.pop(); 
                }else{
                    check = true; 
                    cout << "no" << "\n";
                    break; 
                }
            }else if(str[i] == ']') {
                if( s.empty() ) {
                    check = true; 
                    cout << "no" << "\n";
                    break; 
                }
                if( s.top() == '[') {
                    s.pop(); 
                }else{
                    check = true; 
                    cout << "no" << "\n";
                    break; 
                }
            }
        }
        if( str != "." && !check ) {
            if(s.empty()) { 
                cout << "yes" << "\n";
            }else{ 
                cout << "no" << "\n";
            }
        }
    }while(str != ".");
    return 0;
}