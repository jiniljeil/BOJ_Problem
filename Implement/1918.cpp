#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str ;
stack<char> STACK;

bool isOperand(char c){
    if(c >= 'A' && c <= 'Z' ) return true;
    return false;
}
int percedence(char c){
    if(c =='(') return 0;
    else if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else return 0;
}
//(A+(B*C))-(D/E)
int main(void){
    cin >> str;
    for(int i = 0 ; i < str.length(); i++){
        if(isOperand(str[i])){
            printf("%c",str[i]);
        }else{
            if(str[i] == '('){
                STACK.push(str[i]);
            }else if(str[i] == ')'){
                while(STACK.top() != '('){
                    printf("%c",STACK.top());
                    STACK.pop();
                }
                STACK.pop(); // '(' pop
            }else if(str[i] == '*' || str[i]=='/'){ // operator
                while(!STACK.empty() && (STACK.top() == '*' || STACK.top() == '/')) {
                    printf("%c",STACK.top());
                    STACK.pop();
                }
                STACK.push(str[i]);
            }else if(str[i] == '+' || str[i] == '-'){
                while(!STACK.empty() && STACK.top() != '(' ){
                    printf("%c",STACK.top());
                    STACK.pop();
                }
                STACK.push(str[i]);
            }
        }
    }
    while(!STACK.empty()){
        printf("%c",STACK.top());
        STACK.pop();
    }
    
    return 0;
}
