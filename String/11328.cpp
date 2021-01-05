#include <iostream>
#include <string>
using namespace std; 

int cnt[26];
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
            bool check = true;
            for(int j = 0 ; j < a.length(); j++){ 
                cnt[a[j] - 'a']++; 
            }
            for(int j = 0 ; j < b.length(); j++){
                if( cnt[b[j] - 'a'] == 0 ){
                    check = false;
                    cout << "Impossible" << "\n";
                    break;
                }else{
                    cnt[b[j] - 'a']--;
                }
            }
            if(check) cout << "Possible" << "\n";
            for(int j = 0 ; j < 26; j++) cnt[j] = 0;
        }
        
    }
    return 0;
}