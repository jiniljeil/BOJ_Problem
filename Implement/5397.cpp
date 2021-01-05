#include <iostream>
#include <list> 
using namespace std ;

int N; 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    cin >> N ; 

    for(int i = 0 ; i < N; i++) {
        list<char> l; 
        string str; 
        cin >> str ;

        auto cursor = l.begin(); 
        for(int j = 0 ; j < str.length(); j++) {
            if( str[j] == '<'){
                if(cursor != l.begin()){
                    cursor--;
                }
            }else if( str[j] == '>'){
                if(cursor != l.end()){
                    cursor++;
                }
            }else if( str[j] == '-'){
                if(l.size() != 0){
                    cursor = l.erase(cursor);
                }
            }else{
                l.push_back(str[j]);
                cursor++;
            }

            
        }

        for(char c: l){
            cout << c ;
        }

    }
    return 0;
}