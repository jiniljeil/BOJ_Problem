#include <iostream> 

using namespace std ;

int N; 
int wine[10001];
int drink[10001];

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> N; 

    for(int i = 1 ; i <= N; i++) {
        cin >> wine[i]; 
    }
    drink[1] = wine[1]; 
    drink[2] = wine[1] + wine[2]; 

    for(int i = 3; i <= N; i++) {
        drink[i] = max(drink[i-1], max(drink[i-2] + wine[i], drink[i-3] + wine[i-1] + wine[i]));      
    }
    cout << drink[N] << '\n';
    return 0 ;
}
