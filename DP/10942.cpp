#include <iostream> 
#include <cstring> 

using namespace std ;

int N, M ; 
int DP[2001][2001] ; 
int arr[2001] ; 

int DFS(int S, int E) {
    if ( S > E ) return 1; // 짝수 
    if ( DP[S][E] != -1 ) return DP[S][E] ; 
    if ( S == E ) return DP[S][E] = 1 ; // 홀수 
    
    if ( arr[S] != arr[E] ) return DP[S][E] = 0 ; 
    else return DP[S][E] = DFS( S + 1 , E - 1) ;
}

void Input() { 
    memset(DP, -1, sizeof(DP)) ; 

    cin >> N ;

    for (int i = 1 ; i <= N; i++) { 
        cin >> arr[i] ; 
    }

    cin >> M ; 
}

int main(void) { 
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; 
    int a , b; 
    
    Input() ; 

    for (int i = 0 ; i < M; i++) { 
        cin >> a >> b ; 
        cout << DFS(a, b) << '\n'; 
    }

    return 0; 
}