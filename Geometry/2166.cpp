#include <bits/stdc++.h>

using namespace std ;

typedef long long ll;
int N ; 
ll x, y;
ll sum = 0 ; 
vector<pair<ll,ll> > V ;
int main() { 
    scanf("%d", &N) ; 
    for (int i = 0 ; i < N ; i++) {
        scanf("%ld %ld",&x, &y);
        V.push_back({x, y});
    }

    for (int i = 0 ; i < N - 1; i++) { 
        sum += (V[i].first * V[i + 1].second - V[i + 1].first * V[i].second) ; 
    }
    sum += (V[N - 1].first * V[0].second - V[0].first * V[N - 1].second) ;

    printf("%.1lf",  abs(sum) / 2.0 ) ; 
    return 0 ;
}