#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std ;
typedef long long ll ; 
int N ; 
ll num ; 
vector<ll> V ; 
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    cin >> N ; 

    for (int i = 0 ; i < N ; i++) { 
        cin >> num ; V.push_back(num); 
    }   

    sort(V.begin(), V.end()) ; 

    int answer = 0 ;
    for (int i = 0 ; i < V.size(); i++) { 
        ll curr = V[i] ; 
        int left = 0, right = N - 1 ; 
        while (left < right) { 
            ll sum = V[left] + V[right] ; 
            if ( sum == curr ) { 
                if ( left != i && right != i ) { answer++; break ;} 
                else if ( left == i ) left++; 
                else if ( right == i ) right--; 
            } 
            else if ( sum < curr ) left++;
            else right--;
        }
    }

    cout << answer << '\n';
    return 0 ;
}