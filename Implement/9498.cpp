#include <iostream>

using namespace std;

int main(void){
    int num = 0;
    cin >> num;
    
    if( num >= 0 && num <= 100){
        if(num >= 90 && num <= 100){
            cout << 'A' << endl;
        }else if(num >= 80 && num <= 89){
            cout << 'B' << endl;
        }else if(num >= 70 && num <= 79){
            cout << 'C' << endl;
        }else if(num >= 60 && num <= 69){
            cout << 'D' << endl;
        }else{
            cout << 'F' << endl;
        }
    }
    return 0;
}
