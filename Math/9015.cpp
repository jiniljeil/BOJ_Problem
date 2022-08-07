#include <iostream> 
#include <algorithm>
using namespace std; 
typedef pair<int,int> Point; 

Point points[3001] ; 

int TC, N, x, y;  

int main(void) { 
    scanf("%d", &TC) ; 
    while(TC--) { 
        int answer = 0 ; 

        scanf("%d", &N); 
        for (int i = 0 ; i < N; i++) {
            scanf("%d %d", &points[i].first, &points[i].second) ; 
        }
        sort(points, points + N) ;
        for (int i = 0 ; i < N ; i++) {
            for (int j = i + 1; j < N ; j++) { 
                if ( i == j ) continue ; 
                Point p1 = points[i]; Point p2 = points[j] ; 
                int dx = p1.first - p2.first ; 
                int dy = p1.second - p2.second ; 
                int area = dx * dx + dy * dy ; 
                if ( answer >= area ) continue ; 
                Point p3 = make_pair(p1.first - dy, p1.second + dx); Point p4 = make_pair(p2.first - dy, p2.second + dx); 
                if ( binary_search(points, points + N, p3) && binary_search(points, points + N, p4)) {
                    answer = max(answer, area) ; 
                }
            }
        }
        printf("%d\n", answer) ;  
    }
    return 0; 
}