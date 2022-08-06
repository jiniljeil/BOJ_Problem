#include <iostream> 
#include <algorithm>
#include <vector> 
using namespace std; 

int N, num ; 
vector<int> V ; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N ; 

    for (int i = 0 ; i < N; i++) {
        cin >> num ; V.push_back(num) ; 
    }
    sort(V.begin(), V.end()) ; 

    int answer = 1;  
    for (int i = 0 ; i < V.size(); i++) {
        if ( answer < V[i]) break; 
        answer += V[i] ;
    }

    cout << answer << '\n'; 
    return 0 ; 
}