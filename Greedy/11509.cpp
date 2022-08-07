#include <iostream> 
#include <vector> 
using namespace std; 

int N, H; 
vector<int> V ; 
int main(void) { 
    ios::sync_with_stdio(false); 
    cin.tie(0) ; 

    cin >> N ; 

    for (int i = 0 ; i < N ; i++) { 
        bool t = false; 
        cin >> H ; 
        for (int j = 0 ; j < V.size(); j++) { 
            if ( V[j] - 1 == H ) { 
                t = true ; 
                V[j] = H ;
                break; 
            }
        }
        if ( t == false ) V.push_back(H) ; 
    }

    cout << V.size() << '\n'; 
    return 0; 
}