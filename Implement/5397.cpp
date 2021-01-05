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
        string str; 
        cin >> str ;
        list<char> l; 
        list<char>::iterator cursor = l.end();
        for(int j = 0 ; j < str.length(); j++) {
            if( str[j] == '<'){
                if( cursor != l.begin()){
                    cursor--;
                }
            }else if(str[j] == '>'){
                if(cursor != l.end()){
                    cursor++;
                }
            }else if( str[j] == '-'){
                if( cursor != l.begin()){
                    cursor = l.erase(--cursor);
                }
            }else{
                l.insert(cursor,1,str[j]); 
            }
        }

        list<char>::iterator iter ;
        for(iter = l.begin(); iter != l.end(); iter++){
            cout << *iter ;
        }
        cout << "\n";
        l.clear();
    }
    return 0;
}