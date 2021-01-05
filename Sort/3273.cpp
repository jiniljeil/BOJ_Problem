#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std; 

int N, X ; 
int v[1000001];
bool check[1000001]; 

int main(void){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL); 
    cout.tie(NULL); 

    cin >> N ;
    int t ;
    for(int i = 1 ; i <= N; i++ ){
        cin >> v[i] ;
        check[v[i]] = true;
    }
    cin >> X ;

    sort(v, v + N);

    int result = 0; 
    for(int i = 1 ; i <= N; i++){
        int tmp = X - v[i]; 
        if( tmp > 0 && tmp != v[i] && check[tmp]) {
            check[tmp] = check[v[i]] = false;
            result++;
        }
    }
    cout << result << "\n";
    return 0;
}