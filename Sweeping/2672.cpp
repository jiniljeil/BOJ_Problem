#include <iostream> 
#include <vector> 
#include <algorithm>
#include <queue> 
using namespace std ;
typedef long long ll ;
int N  ;


typedef struct Rect { 
    int x, y, y_h, chk ; 
} RECT ; 
bool compare(Rect a, Rect b) { 
    if ( a.x == b.x ) { 
        return a.chk < b.chk ; 
    } else { 
        return a.x < b.x ; 
    }
}
vector<RECT> V; 
ll answer = 0 ;
float x, y, w, h ; 
int A[20001];

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ;
    cin >> N ; 

    for(int i = 0 ; i < N ; i++) { 
        cin >> x >> y >> w >> h ; 
        x *= 10 ; y *= 10 ; w *= 10 ; h *= 10 ; 
        Rect r = {x, y, (y + h), 1} ; // x좌표의 앞변
        V.push_back(r); 
        r.x = (x + w) ; r.chk = -1 ; // x좌표의 뒷변
        V.push_back(r); 
    }       

    sort(V.begin(), V.end(), compare) ; 

    int lx = 0 ;
    for (int i = 0 ; i < V.size(); i++) { 
        int cnt = 0 ; 
        for (int j = 0 ; j <= 20000; j++) {
            if ( A[j] > 0 ) cnt++;  
        }
        answer += cnt * (V[i].x - lx) ; 
        for (int j = V[i].y + 1 ; j <= V[i].y_h ; j++) { 
            if ( V[i].chk == 1 ) A[j]++; 
            else A[j]--; 
        } 
        lx = V[i].x; 
    }
    
    if ( answer % 100 == 0 ) cout << answer / 100 << '\n' ; 
    else { 
        cout << fixed ; cout.precision(2) ; 
        cout << answer / 100.0 << '\n'; 
    }
}