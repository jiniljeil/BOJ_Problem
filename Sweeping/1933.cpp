#include <bits/stdc++.h> 

using namespace std ;

typedef struct b { 
    int x, h, f ;
} B ;
int N, L, H, R ; 
vector<B> V ;
int main(void) { 
    ios::sync_with_stdio(0) ; cin.tie(0) ; 
    cin >> N ; 
    for (int i = 0 ; i < N ; i++) { 
        cin >> L >> H >> R; 
        V.push_back({L, H, 0}) ; 
        V.push_back({R, H, 1}) ; 
    }

    sort(V.begin(), V.end(), [&] (B &a, B&b) {
        if ( a.x != b.x ) return a.x < b.x ;
        if ( a.f != b.f ) return a.f < b.f ; 
        return (a.f == 0) ? a.h > b.h : a.h < b.h ; 
    });

    multiset<int> S ;
    for (int i = 0 ; i < V.size(); i++) { 
        B t = V[i] ; 
        // LEFT 
        if ( t.f == 0 ) {
            // 새로 건물을 짓거나 더 높은 건물을 짓는 경우
            if ( S.empty() || *S.rbegin() < t.h ) cout << t.x << ' ' << t.h << ' ';
            S.insert(t.h) ; 
        // RIGHT
        } else {
            auto p = *S.rbegin();
            auto iter = S.find(t.h) ;
            // 지었던 건물의 끝 지점에 도달하였을 경우 삭제
            if ( iter != S.end() ) S.erase(iter) ;
            // 이어지는 건물이 없을 경우
            if ( S.empty() ) cout << t.x << ' ' << 0 << ' ' ; 
            // 다른 건물이 있는 경우
            else if (p != *S.rbegin()) cout << t.x << ' ' << *S.rbegin() << ' ' ; 
        }
    }
    cout << '\n'; 

    return 0 ; 
}