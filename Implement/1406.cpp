#include <iostream>
#include <list>

using namespace std;

int N ;
list<char> l ;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str ;
    cin >> str; 

    for(int i = 0 ; i < str.length(); i++) {
        l.push_back(str[i]);
    }

    auto cursor = l.end();
    cin >> N; 
    for(int i = 0 ; i < N; i++){
        char tmp;
        cin >> tmp;
        
        if( tmp == 'L'){
            if(cursor != l.begin()){
                cursor--;
            }
        }else if(tmp == 'D'){
            if(cursor != l.end()){
                cursor++;
            }
        }else if(tmp == 'B'){
            if(cursor != l.begin()){
                cursor--; cursor = l.erase(cursor);
            }
        }else if(tmp == 'P'){
            char t2;
            cin >> t2 ;
            l.insert(cursor, t2);
        }
    }

    list<char>::iterator iter;
    for(iter = l.begin(); iter != l.end(); iter++){
        cout << *iter ;
    }
    cout << "\n";
    return 0;
}