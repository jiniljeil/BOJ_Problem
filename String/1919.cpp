#include <iostream>
#include <string>
using namespace std ;

int main(void){
    string a,b; 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int result = 0, count = 0 ;
    cin >> a >> b ;
    bool *visit = new bool[b.length()];
    for(int i = 0 ; i < a.length(); i++){
        for(int j = 0; j < b.length(); j++) {
            if( !visit[j] && a[i] == b[j] ) {
                visit[j] = true;
                break;
            }
        }
    }

    for(int i = 0 ; i < b.length(); i++){
        if( visit[i] ) {
            count++; 
        }
    }
    result += ((b.length() - count ) + (a.length() - count));
    cout << result << "\n";
    free(visit);
    return 0;
}