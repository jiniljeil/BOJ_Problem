#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    
    for(int i = 0 ; i < n; i++){
        stack<char> s ;
        string str;
        cin >> str;
        
        if(str.length() > 0){
            if( str[0] == ')') {
                cout << "NO" << "\n";
            }else{
                bool check = true;
                for(int j = 0 ; j < str.length(); j++){
                    if(str[j] == '('){
                        s.push(str[j]);
                    }else if(str[j] == ')'){
                        if(s.empty()){
                            cout << "NO" << "\n";
                            check = false;
                            break;
                        }else{
                            s.pop();
                        }
                    }
                }
                if(!s.empty()){
                    cout << "NO" << "\n";
                }
                if(s.empty() && check){
                    cout << "YES" << "\n";
                }
            }
        }
    }
    
    return 0;
}
