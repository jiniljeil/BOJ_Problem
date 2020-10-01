#include <iostream>

using namespace std;

long long int sub(int value){
    string str = to_string(value);
    if (str != "") {str = str.substr(0,str.length()-1);}
    return stoll(str);
}

int main(void){
    long long int num, input;
    bool check = false;
    int count = 1;
    scanf("%lld %lld",&num,&input);
    
    while(input != num){
        if (input < num) {
            check = true;
            break;
        }else{
            string temp = to_string(input);
            if( temp[temp.length()-1] != '1' && input % 2 != 0){
                check = true;
                break;
            }
            
            count++;
            if( input % 2 == 0 ){
                input /= 2;
            }else{
                input = sub(input);
            }
                   
        }
    };
    if( check ){
        cout << -1 << endl;
    }else{
        cout << count << endl;
    }
    
    return 0;
}
