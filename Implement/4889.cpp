#include <iostream>
#include <stack>
using namespace std; 

stack<char> s ;
int main(void) {
    ios::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    int num = 1; 
    while(true) {
        string str ; 
        cin >> str ;
        if(!(str.find("-") == std::string::npos)) {
            break;
        }
        
        for(int i = 0 ; i < str.length(); i++) {
            if( str[i] == '{') {
                s.push(str[i]) ; 
            }else if(str[i] == '}'){
                if(!s.empty() && s.top() == '{') { 
                    s.pop(); 
                }else{ 
                    s.push(str[i]);
                }
            }
        }
        if(s.empty()) {
            cout << num << ". 0" << "\n"; 
        }else{ 
            int result = 0 ;
            
            while(!s.empty()){
                char tmp = s.top(); 
                s.pop();
                if( tmp == s.top()) {
                    result++;
                }else{
                    result += 2; 
                }
                s.pop();
            }
            cout << num << ". " << result << "\n";
        }
        num++;
    }
    return 0 ;
}