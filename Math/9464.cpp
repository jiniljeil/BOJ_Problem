#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std; 

vector<int> V ; 
int TC ; 
int N ; 

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x; 
}

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    for (int i = 1; i < 10000; i++) { 
        for (int j = i + 1 ; 2ll * i * j < 10000 ; j++) { 
            int a = 2 * i * j ; 
            int b = j * j - i * i ; 

            if ( gcd(a, b) == 1 ) { 
                V.push_back(2 * a + 2 * b); 
            } 
        }
    }
    sort(V.begin(), V.end()) ; 

    cin >> TC ; 

    while(TC--)  {
        cin >> N ; 
        for (int i = 0 ; i < V.size(); i++) { 
            if ( N - V[i] >= 0 ) { 
                N = N - V[i] ; 
            } else { 
                cout << i << '\n'; 
                break ;
            }
        }
    }
    return 0; 
}