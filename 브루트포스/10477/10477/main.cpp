#include <iostream>
#include <math.h>
using namespace std;

int c = 0 ;
bool **v;

int divide(int curr_y, int curr_x, int range, int t1, int t2){
    if(v[curr_y][curr_x]) return 0;
    
    v[curr_y][curr_x] = true;
    if( curr_y >= t1 || curr_x >= t2 || range > t2 -1){
        return 0;
    }else{
        cout << curr_x << " " << curr_y << " " << range << endl;
        c++;
        
        for(int i = 0 ; i <= range; i++){
            if ( (!v[curr_y + range - i][curr_x + i] && curr_y <= t1) && curr_x <= t2){
                divide(curr_y + (range - i), curr_x + i, range, t1, t2);
            }
        }
        
        return c;
    }
}
//0 0
//0 1 -> 0 3 , 1 2
//1 0 -> 2,1 , 1,2


int main(void){
    int n ;
    scanf("%d",&n);
    
    for(int i = 0 ; i < n; i++){
        int t1,t2;
        
        scanf("%d %d",&t1,&t2);
        
        v = new bool*[t1+1];
        for(int i = 0 ; i < t1+1; i++){
            v[i] = new bool[t2+1];
        }
        
        for(int i = 1 ; max(t1,t2) >= pow(2,i-1); i++ ){
            cout << "range: " << pow(2,i-1) << endl;
            divide(0, 0, pow(2,i-1), t1, t2);
        }
        
        cout << c << endl;
        
        for(int i = 0 ; i < t1+1; i++){
            delete [] v[i];
        }
        delete [] v;
    }
    return 0;
}
