#include <iostream>
#include <stdlib.h>

using namespace std;

string str ;

bool check (string s){
    unsigned long length = s.length();
    unsigned long p = s.length()-1;
    for(int i = 1; i <= length/2; i++){
        if(s.substr( p-i, i) == s.substr( p, i)){
            return false;
        }
        p--;
    }
    
    return true;
}

void func(string s, int k ,int value) {
    if (k > value) return ;
    if (!check (s)) return;
    if( k == value ) {
        cout << s ;
        exit(0);
    }
    
    for(int i = 1 ; i <= value ;i++){
        func(s+"1", k+1, value);
        func(s+"2", k+1, value);
        func(s+"3", k+1, value);
    }
}

int main() {
    int value;
    scanf("%d",&value);
    func(str, 0, value);
    return 0;
}
