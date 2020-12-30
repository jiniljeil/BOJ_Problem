#include <iostream> 

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t1,t2,t3; 
    cin >> n ;

    for(int i = 0 ;i < n ;i++){
        cin >> t1 ;
        cin >> t2 ;
        t3 = t1 + t2;
        cout << t3 << '\n'; 
    }
    
    return 0 ;
}