#include <iostream>
#include <string>
using namespace std; 

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    int n ; 
    cin >> n;

    for(int i = 0 ; i < n; i++) {
        string a,b ;
        cin >> a >> b ;
        if( a.length() != b.length()) {
            cout << "Impossible" << "\n";
        }else{
            bool* check = new bool[a.length()]; 
            for(int j = 0 ; j < a.length(); j++) {
                for(int k = 0; k < b.length(); k++) {
                    if( !check[k] && a[j] == b[k] ){
                        check[k] = true; 
                        break; 
                    }
                }
            }
            bool check2 = true; 
            for(int j = 0 ; j < a.length(); j++) {
                if( !check[j] ){ 
                    check2 = false; 
                    break; 
                }
            }
            if( check2 ) {
                cout << "Possible" << "\n";
            }else{ 
                cout << "Impossible" << "\n";
            }
            free(check); 
        }
        
    }
    return 0;
}