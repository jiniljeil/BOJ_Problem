#include <iostream>

using namespace std;

int main(void){
    string str ;
    cin >> str;
    int count = 0 ;
    for(int i = 0 ; i < str.size()/2; i++){
        int front = i, back = str.size() -i -1;
        if(str[front] != str[back]){
            str[front] = 'x';
            str[back] = 'x';
            
//            cout << str << endl;
        }else{
            count++;
            int b = back ;
//            cout << b << endl ;
            while(1){
                if(str[front] == str[b]){
                    count++;
                    b--;
                }else{
                    break;
                }
            }
        }
        
    }
    
    cout << count << endl ;
    return 0;
}
