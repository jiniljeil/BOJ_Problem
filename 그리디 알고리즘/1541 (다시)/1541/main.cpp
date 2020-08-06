#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void){
    string expression;
    cin >> expression ;
    
    bool resultCheck = false;
    while(!resultCheck){
        resultCheck = true;
        
        for(int i = 0 ; i < expression.length(); i++){
            if(expression[i] == '+'){
                    resultCheck = false;
            }
                
            if(expression[i] == '+'){
                int preIdx = -1, lastIdx = -1;
                for(int j = i-1; j >= 0; j--){
                    if(expression[j] == '+' || expression[j] == '-'){
                        preIdx = j;
                        break;
                    }
                }
                
                for(int j = i+1 ; j < expression.length(); j++){
                    if(expression[j] == '+' || expression[j] == '-'){
                        lastIdx = j;
                        break;
                    }
                }
                
                if(preIdx < 0 && lastIdx < 0){
                    string t1 = expression.substr(0,i);
                    string t2 = expression.substr(i+1,expression.length()-(i+1));
                    
                    int num1, num2;
                    num1 = stoi(t1);
                    num2 = stoi(t2);
                    int sum = num1 + num2;
                    cout << sum << endl;
                }else if(preIdx < 0){
                    int calculate = stoi(expression.substr(0,i-1)) + stoi(expression.substr(i+1,lastIdx));
                    expression.replace(0,lastIdx,to_string(calculate));
                }else if(lastIdx < 0){
                    int calculate = stoi(expression.substr(preIdx+1,i)) + stoi(expression.substr(i+1,expression.length()));
                    expression.replace(preIdx+1, expression.length() - (preIdx+1), to_string(calculate));
                }else{
                    int calculate = stoi(expression.substr(preIdx+1,i)) + stoi(expression.substr(i+1,lastIdx));
                    expression.replace(preIdx+1, lastIdx-preIdx-1, to_string(calculate));
                }
//                cout << preIdx << " " << lastIdx << endl;
            }
        }
        
//        cout << expression << endl;
    }
    
    resultCheck = false;
    
    while(!resultCheck){
        resultCheck = true;
        
        for(int i = 1 ; i < expression.length(); i++){
            if(expression[i] == '-'){
                resultCheck = false;
            }
                
            if(expression[i] == '-'){
                int preIdx = -1, lastIdx = -1;
                for(int j = i-1; j >= 0; j--){
                    if(expression[j] == '-'){
                        preIdx = j;
                        break;
                    }
                }
                
                for(int j = i+1 ; j < expression.length(); j++){
                    if(expression[j] == '-'){
                        lastIdx = j;
                        break;
                    }
                }
                
                if((preIdx <= 0) && lastIdx < 0){
                    if(expression[0] == '-'){
                        string t1 = expression.substr(0,i);
                        string t2 = expression.substr(i,expression.length()-(i)+1);
                    
                        int num1, num2;
                        num1 = stoi(t1);
                        num2 = stoi(t2);
                        int sum = num1 + num2;
                        cout << sum << endl;
                        resultCheck = true;
                    }else{
                        string t1 = expression.substr(0,i);
                        string t2 = expression.substr(i,expression.length()-(i+1));
                        
                        int num1, num2;
                        num1 = stoi(t1);
                        num2 = stoi(t2);
                        int sum = num1 - num2;
                        cout << sum << endl;
                        resultCheck = true;
                    }
                    
                }else if(preIdx < 0){
                    int calculate = stoi(expression.substr(0,i)) - stoi(expression.substr(i+1,lastIdx));
                    expression.replace(0,lastIdx,to_string(calculate));
                }else if(lastIdx < 0){
                    int calculate = stoi(expression.substr(preIdx,i)) + stoi(expression.substr(i,expression.length()));
                    expression.replace(preIdx, expression.length() - (preIdx+1), to_string(calculate));
                }else{
                    int calculate = stoi(expression.substr(preIdx,i)) + stoi(expression.substr(i,lastIdx));
                    expression.replace(preIdx, lastIdx-preIdx, to_string(calculate));
                }
//                cout << preIdx << " " << lastIdx << endl;
            }
            
//            cout << expression << endl;
        }
        
        
    }
//    cout << expression << endl;
    
    return 0;
}
