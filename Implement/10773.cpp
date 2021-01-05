#include <iostream>
#include <stack> 
using namespace std;

int K;
long long int result = 0; 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K ;
    int t; stack<int> STACK;
    for(int i = 0 ; i < K; i++) {
        cin >> t ;
        if( !STACK.empty() && t == 0 ){
            STACK.pop();
        }else{
            STACK.push(t);
        }
    }

    while(!STACK.empty()){
        result += STACK.top(); 
        STACK.pop();
    }
    cout << result << "\n";
     
    return  0;
}