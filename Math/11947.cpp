#include <iostream>
#include <math.h>
#include <vector>

using namespace std ;
int main(void){
    int num ;
    vector<long long> result;
    scanf("%d", &num);
    
    
    for(int i = 0 ; i < num; i++){
        string str, mid;
        cin >> str;
        mid = str ;
        mid[0] = '5';
        for(int j = 1 ; j < str.length(); j++){
            mid[j] = '0';
        }
        if(stol(mid) < stol(str)){
            for(int j = 0 ; j < mid.size(); j++){
                str[j] = '9'-mid[j]+'0';
            }
            
            long long result = stol(str) * stol(mid);
            cout << result << endl ;
        }else {
            for(int j = 0 ; j < str.size(); j++){
                mid[j] = '9'-str[j]+'0';
            }
            long long result = stol(str) * stol(mid);
            cout << result << endl ;
        }
    }
    
    return 0;
}
