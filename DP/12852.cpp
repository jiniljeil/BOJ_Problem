#include <iostream> 

using namespace std ;

int N; 
int DP[1000001];
int trace[1000001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    cin >> N ;

    DP[1] = 0; 
    trace[1] = 0 ; 

    for(int i = 2; i <= N; i++) {
        DP[i] = DP[i - 1] + 1; 
        trace[i] = i - 1; 
        if( i % 2 == 0 && DP[i] > DP[i/2] + 1){ 
            DP[i] = DP[i/2] + 1; 
            trace[i] = i/2; 
        }
        if( i % 3 == 0 && DP[i] > DP[i/3] + 1) {
            DP[i] = DP[i/3] + 1; 
            trace[i] = i/3;
        }
    }

    cout << DP[N] << '\n';
    int n = N; 
    while(n != 0) { 
        cout << n << ' ';
        n = trace[n];
    }
    return 0;
}