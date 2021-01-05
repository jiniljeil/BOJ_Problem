#include <iostream>
#include <deque> 
#include <string>
#include <cstdlib>
using namespace std;

int N ;
int main(void){
    deque<int> d; 
    scanf("%d",&N);
    
    for(int i = 0 ; i < N ;i++){
        char tmp[20]; 
        getchar();
        scanf("%[^\n]s", tmp);
        string str = tmp ;
        
        if( str.substr(0,10) == "push_front" ){ 
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
            d.push_front(atoi(s.c_str()));
        }else if( str.substr(0,9) == "push_back"){
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
            d.push_back(atoi(s.c_str()));
        }else if(str == "front"){
            if( d.size() == 0 ) {
                cout << "-1" << "\n";
            }else{
                cout << d.front() << "\n";
            }
        }else if( str == "back" ){
            if( d.size() == 0 ) {
                cout << "-1" << "\n";
            }else{
                cout << d.back() << "\n";
            }
        }else if( str == "size") {
            cout << d.size() << "\n";
        }else if( str == "pop_front") {
            if( d.size() == 0 ) {
                cout << "-1" << "\n";
            }else{
                cout << d.front() << "\n";
                d.pop_front(); 
            }
        }else if( str == "pop_back") {
            if( d.size() == 0 ) {
                cout << "-1" << "\n";
            }else{
                cout << d.back() << "\n";
                d.pop_back(); 
            }
        }else if( str == "empty"){
            cout << d.empty() << "\n";
        }
    }
}