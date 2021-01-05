#include <iostream>
#include <string> 
#include <deque>
using namespace std; 

int N ;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N ;

    for(int i = 0 ; i < N ; i++){
        int size, t = 0 ; 
        deque<int> d ;
        string str, str2;
        cin >> str >> size >> str2;
        string tmp = "";
        for(int j = 0 ; j< str2.length(); j++){
            if(str2[j] >= '0' && str2[j] <= '9'){
                tmp += str2[j]; 
            }else if((str2[j] == ']' || str2[j] == ',') && tmp != "") {
                d.push_back(atoi(tmp.c_str()));
                tmp = ""; 
            }
        }
        bool reverse_check = false;
        bool check = false;
        for(int j = 0 ; j < str.length(); j++) {
            if(str[j] == 'R') {
                reverse_check = !reverse_check;
            }else if(str[j] == 'D'){
                if( d.empty()) {
                    cout << "error" << "\n"; 
                    check = true; 
                    break;
                }else{
                    if( reverse_check ){ 
                        d.pop_back();
                    }else{
                        d.pop_front();
                    }   
                }
            }
        }
        if(!check) {
            cout << "[" ; 
            if(reverse_check) {
                while(!d.empty()){
                    cout << d.back() ;
                    d.pop_back();
                    if(!d.empty()) cout << ",";
                }
            }else{
                while(!d.empty()){
                    cout << d.front();
                    d.pop_front();
                    if(!d.empty()) cout << ",";
                }
            }
            cout << "]\n" ;
        }
        
    }
    return 0;
}