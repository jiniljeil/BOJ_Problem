#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int num = 0 ;
    cin >> num ;
    for (int i = 0 ; i < num ; i++) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        int count = 0 ;
        
        for(int j = 0 ; j < s1.length(); j++){
            if( s1[j] == s2[j]){
                s1[j] = '2';
                s2[j] = '2';
            }
        }
        
        for(int j = 0 ; j < s1.length(); j++){
            for(int k = 0 ; k < s2.length(); k++){
                if( s1[j] != '2' && s2[k] != '2' && s1[j] == s2[k]){
                    s1[j] = '2';
                    s2[k] = '2';
                    if( j != k){
                        count++;
                    }
                    break;
                }
            }
        }
        count /= 2;
        int rem = 0;
        for(int j = 0 ; j < s1.length(); j++){
            if( s1[j] == '?'){
                rem++;
                s1[j] = '2';
            }
        }
        
        bool check = true;
        for(int j = 0 ; j < s1.length(); j++){
            if( s1[j] != '2') check = false;
        }
        count += rem;
        
        if( check ){
            cout << "Case " << i+1 << ": " << count << endl;
        }else{
            cout << "Case " << i+1 << ": " << -1 << endl;
        }
    }
    
    return 0;
}

