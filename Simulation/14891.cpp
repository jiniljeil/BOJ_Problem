#include <iostream>
#include <string> 
using namespace std;

string wheels[5]; 

int N ;
int result = 0 ;

void rotation(int num_wheel, int direction) { 
    if( direction == 1) { 
        wheels[num_wheel].insert(0,1,wheels[num_wheel][7]);
        wheels[num_wheel].erase(wheels[num_wheel].length() -1 ,1);
    }else if(direction == -1){
        wheels[num_wheel].append(1,wheels[num_wheel][0]);
        wheels[num_wheel].erase(0, 1);
    }
}
void func(int num_wheel, int direction) {  // 1 : 시계 방향, -1 : 반시계방향
    if( num_wheel < 1 || num_wheel > 4) return ;
    int reverse_direction = (direction == 1) ? -1 : 1; 
    if( num_wheel == 1) { 
        if(wheels[num_wheel][2] != wheels[num_wheel+1][6]) {
            if(wheels[num_wheel+1][2] != wheels[num_wheel+2][6]){
                if(wheels[num_wheel+2][2] != wheels[num_wheel+3][6]){
                    rotation(num_wheel, direction) ; 
                    rotation(num_wheel+1, reverse_direction);
                    rotation(num_wheel+2, direction); 
                    rotation(num_wheel+3, reverse_direction);
                }else{
                    rotation(num_wheel, direction) ; 
                    rotation(num_wheel+1, reverse_direction);
                    rotation(num_wheel+2, direction); 
                }
            }else{
                rotation(num_wheel, direction) ; 
                rotation(num_wheel+1, reverse_direction);
            }
        }else{
            rotation(num_wheel, direction);
        }
    }else if( num_wheel == 2){
        if(wheels[num_wheel-1][2] != wheels[num_wheel][6]){ 
            rotation(num_wheel-1, reverse_direction);
        }
        if(wheels[num_wheel][2] != wheels[num_wheel+1][6]){
            if(wheels[num_wheel+1][2] != wheels[num_wheel+2][6]) {
                rotation(num_wheel, direction);
                rotation(num_wheel+1, reverse_direction);
                rotation(num_wheel+2, direction);
            }else{
                rotation(num_wheel, direction);
                rotation(num_wheel+1, reverse_direction);
            }
        }else{
            rotation(num_wheel, direction);
        }
    }else if( num_wheel == 3){
        if( wheels[num_wheel][2] != wheels[num_wheel+1][6]){
            rotation(num_wheel+1, reverse_direction);
        }
        if(wheels[num_wheel-1][2] != wheels[num_wheel][6]){ 
            if(wheels[num_wheel-2][2] != wheels[num_wheel-1][6]){
                rotation(num_wheel, direction);
                rotation(num_wheel-1, reverse_direction);
                rotation(num_wheel-2, direction);
            }else{
                rotation(num_wheel, direction);
                rotation(num_wheel-1, reverse_direction);
            }
        }else{
            rotation(num_wheel, direction);
        }
    }else if( num_wheel == 4){
        if(wheels[num_wheel][6] != wheels[num_wheel-1][2]) {
            if(wheels[num_wheel-1][6] != wheels[num_wheel-2][2]){
                if(wheels[num_wheel-2][6] != wheels[num_wheel-3][2]) {
                    rotation(num_wheel, direction);
                    rotation(num_wheel - 1, reverse_direction);
                    rotation(num_wheel - 2, direction);
                    rotation(num_wheel - 3, reverse_direction);
                }else{
                    rotation(num_wheel, direction);
                    rotation(num_wheel - 1, reverse_direction);
                    rotation(num_wheel - 2, direction);
                }
            }else{
                rotation(num_wheel, direction);
                rotation(num_wheel - 1, reverse_direction);
            }
        }else{
            rotation(num_wheel, direction);
        }
    }
}

void calculation(){ 
    if(wheels[1][0] == '1') {  // 1번. 12시 방향 S극 : 1점 
        result++;
    }
    if(wheels[2][0] == '1') {  // 2번. 12시 방향 S극 : 2점 
        result += 2; 
    }
    if(wheels[3][0] == '1') {  // 3번. 12시 방향 S극 : 3점 
        result += 4;
    }
    if(wheels[4][0] == '1') {  // 4번. 12시 방향 S극 : 4점 
        result += 8; 
    }
}

int main(void){
    // N : 0 , S : 1
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    for(int i = 1 ; i <= 4; i++) {
        cin >> wheels[i];
    }

    cin >> N;
    int t1, t2; 
    // 1 : 시계 방향, -1 : 반시계방향

    for(int i = 0 ; i < N; i++) {
        cin >> t1 >> t2; 
        // cout << wheels[t1] << '\n';
        func(t1,t2);
    }   
    
    calculation();// calculation
    printf("%d\n", result);
    return 0 ;
}
