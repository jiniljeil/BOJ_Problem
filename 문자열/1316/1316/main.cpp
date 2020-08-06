#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int num = 0 ;
    scanf("%d",&num);
    
    int count_var = 0;
    for(int i = 0 ; i < num; i++){
        string str;
        vector<char> ch ;
        bool checker = false;
        cin >> str;
        
        ch.push_back(str[0]);
        for(int j = 0 ; j < str.size()-1; j++){
            char pre_c = str[j];
            char curr_c = str[j+1];
            
            if( pre_c != curr_c){
                pre_c = curr_c ;
                long check = count(ch.begin(),ch.end(), curr_c);
                ch.push_back(pre_c);
                if(check > 0){
                    checker = true;
                    break;
                }
                
            }
        }
        if(!checker){
            count_var++;
        }
        
    }
    printf("%d",count_var);
    
    return 0;
}
