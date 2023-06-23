#include <iostream> 
#include <vector> 
#include <algorithm>
#define SIZE 300010
#define INF 200000000
typedef long long ll ;

using namespace std ;

typedef struct info { 
    ll value, idx ;
} INFO; 
int n;
ll A[SIZE], B[SIZE][4] ; 
vector<INFO>  V ;
int main(void) { 
    ios::sync_with_stdio(0); cin.tie(0) ; 

    cin >> n ; 
    for (int i = 0 ; i < n ; i++) cin >> A[i]; 

    V.resize(0) ; V.push_back({INF, -1}); 
    for (int i = 0 ; i < n ; i++) { 
        while( V.back().value <= A[i] ) V.pop_back() ; 
        B[i][0] = V.back().idx + 1 ;
        V.push_back({A[i], i}) ;
    }
    
    V.resize(0) ; V.push_back({INF, n}) ; 
    for (int i = n - 1; i >= 0 ; i--) { 
        while( V.back().value < A[i] ) V.pop_back() ; 
        B[i][1] = V.back().idx - 1; 
        V.push_back({A[i], i}) ;  
    }
    
    V.resize(0) ; V.push_back({-INF, -1});
    for (int i = 0 ; i < n ; i++) { 
        while( V.back().value >= A[i] ) V.pop_back() ; 
        B[i][2] = V.back().idx + 1 ;
        V.push_back({A[i], i}) ;
    }
    
    V.resize(0) ; V.push_back({-INF, n}) ; 
    for (int i = n - 1; i >= 0 ; i--) { 
        while( V.back().value > A[i] ) V.pop_back() ; 
        B[i][3] = V.back().idx - 1; 
        V.push_back({A[i], i}) ;  
    }
    
    ll sum = 0 ; 
    for (int i = 0 ; i < n ; i++) { 
        sum += A[i] * (B[i][1] - i + 1) * (i - B[i][0] + 1) ;
        
        sum -= A[i] * (B[i][3] - i + 1) * (i - B[i][2] + 1) ; 
    }
    cout << sum << '\n'; 
    return 0;
}