#include <iostream> 
#include <string> 
#include <queue> 
#include <math.h> 
using namespace std ;
int N ;
int cnt[26]; 
priority_queue< int > q ;
int main(void){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    cin >> N ; 
    string s ; 
    for(int i = 0 ;i < N; i++) {
        cin >> s ; 
        for(int j = 0; j < s.length() ; j++) {
            cnt[s[j] - 'A'] += pow(10,s.length() - j - 1) ;
        }
    }

    for(int i = 0 ; i < 26; i++) {
        if( cnt[i] > 0 ){
            q.push(cnt[i]);
        }
    }

    //for(int i = 0; i < 26; i++) cout << cnt[i] << " ";

    int sum = 0 ;
    int num = 9; 
    while(!q.empty()) {
        int curr_alpha = q.top(); 
        sum += (curr_alpha * num);
        num--;
        q.pop();
    }
    cout << sum << "\n";
    return 0;
}