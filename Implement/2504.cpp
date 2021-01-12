#include <iostream>
#include <stack> 
#include <string> 
using namespace std;

stack<int> s; 
int result = 0; 
int curr_v = 1; 
int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    string str ;
    bool check = false; 

    cin >> str; 

    for(int i = 0 ; i <str.length(); i++){ 
        if( str[i] == '(') {
            curr_v *= 2 ;
            s.push(str[i]);
        }else if( str[i] == '[') {
            curr_v *= 3; 
            s.push(str[i]);
        }else if( str[i] == ')') {
            if( s.empty() || s.top() != '('){ 
                cout << "0" << "\n"; 
                check = true; 
                break;
            }else{
                if(str[i-1] == '('){ 
                    result += curr_v; 
                }
                s.pop(); curr_v /= 2; 
            } 
        }else if( str[i] == ']') {
            if( s.empty() || s.top() != '['){ 
                cout << "0" << "\n"; 
                check = true; 
                break; 
            }else {
                if(str[i-1] == '['){ 
                    result += curr_v; 
                }
                s.pop(); curr_v /= 3 ;
            }
        }
    }
    if(!check){ 
        if(s.empty()) {
            cout << result << "\n"; 
        }else{
            cout << "0" << "\n";
        }
    }
    return 0;
}