#include <iostream> 
#include <vector> 
#include <queue> 
#include <algorithm>
using namespace std ; 

int N ;
int d, w; 

typedef struct Am { 
    int d ; 
    int w ; 
} AM ; 

bool compare(const Am &a, const Am &b) { 
        return (a.w >= b.w) ; 
}

vector<AM> V; 
int date[1001] ; 

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N ;

    for (int i = 0 ; i < N ; i++) { 
        cin >> d >> w ; 
        AM am = {d, w} ;
        V.push_back(am) ; 
    }

    sort(V.begin(), V.end(), compare) ; 

    for (int i = 0 ; i < V.size(); i++) { 
        if ( date[V[i].d] == 0 ) { 
            date[V[i].d] = V[i].w ; 
        } else { 
            int idx = V[i].d ; 
            while ( idx > 0 ) { 
                if ( date[idx] == 0 ) { 
                    date[idx] = V[i].w ; 
                    break ; 
                }
                idx-- ; 
            }
        }
    }
    long long answer = 0; 

    for (int i = 1 ; i <= 1000; i++) { 
        answer += date[i] ; 
    }
    cout << answer << '\n' ;
    return 0 ;
}