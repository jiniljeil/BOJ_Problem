#include <bits/stdc++.h>

using namespace std ;

typedef struct point { 
    int x,y ; 
} point ; 

int ccw(point p1, point p2, point p3) { 
    int cross_product = (p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y);
    if ( cross_product > 0 ) return 1;
    else if ( cross_product < 0 ) return -1 ;
    else return 0 ;
}

int main() { 
    vector<point> v ;
    for (int i = 0 ; i < 3 ; i++) { 
        int x, y ; cin >> x >> y ;
        v.push_back({x,y}) ;
    }

    cout << ccw(v[0], v[1], v[2]) ; 
}