#include <iostream>
#include <algorithm>

using namespace std;

int main (void){
    int x , y;
    int w, h; // 직사각형 오른쪽 위 꼭짓점
    int result = 0;
    
    cin >> x >> y >> w >> h ;
    
    if(x >= 1 && x <= w-1 && y >= 1 && y <= h-1){
        result = min(w-x ,x );
        result = min(result, min(h-y,y));
        cout << result << endl;
    }
    
    return 0;
    
}
