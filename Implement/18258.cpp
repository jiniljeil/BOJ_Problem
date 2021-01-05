#include <iostream>
#include <queue> 
#include <string>
#include <cstdlib>
using namespace std;

int N ;
int main(void){
    queue<int> q ;
    scanf("%d",&N);
    
    for(int i = 0 ; i < N ;i++){
        char tmp[20]; 
        getchar();
        scanf("%[^\n]s", tmp);
        string str = tmp ;
        
        if( str.substr(0,4) == "push" ){ 
            bool check = false;
            string s = "";
            for(int k = 0 ; k < str.length(); k++) {
                if(check) { 
                    s += str[k];
                }
                if( str[k] == ' '){
                    check = true; 
                }
            }
            q.push(atoi(s.c_str()));
        }else if( str == "front"){
            if( q.size() == 0 ) {
                cout << "-1" << "\n";
            }else{
                cout << q.front() << "\n";
            }
        }else if( str == "back" ){
            if( q.size() == 0 ) {
                cout << "-1" << "\n";
            }else{
                cout << q.back() << "\n";
            }
        }else if( str == "size") {
            cout << q.size() << "\n";
        }else if( str == "pop") {
            if( q.size() == 0 ) {
                cout << "-1" << "\n";
            }else{
                cout << q.front() << "\n";
                q.pop(); 
            }
        }else if( str == "empty"){
            cout << q.empty() << "\n";
        }
    }
}