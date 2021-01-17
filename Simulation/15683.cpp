#include <iostream> 
#include <algorithm>
using namespace std ;

int N, M; // 세로 가로 
int map[8][8];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0,-1};

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    
    cin >> N >> M; 
    int max = 0;
    for(int i = 0  ; i < N; i++) {
        for(int j = 0 ; j < M; j++) {
            cin >> map[i][j]; 
        }
    }
    int result = 0 ;
    int dir_x, dir_y ;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if( map[i][j] == 1 ) {
                result += 1; 
                max = 0 ;
                int idx =0 ;
                for(int k = 0 ; k < 4; k++) {
                    int c = 0 ; 
                    dir_y = i + dy[k];  
                    dir_x = j + dx[k]; 
                    if( dir_y < 0 || dir_y >= N || dir_x < 0 || dir_x >= M) continue; 
                    if( k == 0 ){ // 왼쪽 
                        for(int k2 = dir_x; k2 >= 0; k2--) {
                            if(map[dir_y][k2] == 0 ) {
                                c++; 
                            }else{
                                break; 
                            }
                        }
                    }
                    if( k == 1 ){ // 아래 
                        for(int k2 = dir_y; k2 < N; k2++) {
                            if(map[k2][dir_x] == 0 ) {
                                c++;
                            }else{
                                break;
                            }
                        }
                    }
                    if( k == 2 ){ // 오른쪽 
                        for(int k2 = dir_x; k2 < M; k2++) {
                            if(map[dir_y][k2] == 0 ) {
                                c++;  
                            }else{
                                break;
                            }
                        }
                    }
                    if( k == 3 ){ // 위 
                        for(int k2 = dir_y; k2 >= 0 ; k2--) {
                            if(map[k2][dir_x] == 0) {
                                c++;
                            }else{
                                break;
                            }
                        }
                    }
                    // cout << c << "\n";
                    if(max < c) {
                        max = c ;
                        idx = 0 ;
                    }
                }
                // cout << "MAX: " << max << "\n";
                result += max; 
            }else if(map[i][j] == 2) {
                result += 1; 
                int c1 = 0, c2 = 0 ; 
                for(int k = 0 ; k < 4; k++) {
                    dir_y = i + dy[k];  
                    dir_x = j + dx[k]; 
                    if( dir_y < 0 || dir_y >= N || dir_x < 0 || dir_x >= M) continue; 
                    if( k == 0 ){ // 왼쪽 
                        for(int k2 = dir_x; k2 >= 0; k2--) {
                            if(map[dir_y][k2] == 0 ) {
                                c1++; 
                            }else{
                                break; 
                            }
                        }
                    }
                    if( k == 1 ){ // 아래 
                        for(int k2 = dir_y; k2 < N; k2++) {
                            if(map[k2][dir_x] == 0 ) {
                                c2++;
                            }else{
                                break;
                            }
                        }
                    }
                    if( k == 2 ){ // 오른쪽 
                        for(int k2 = dir_x; k2 < M; k2++) {
                            if(map[dir_y][k2] == 0 ) {
                                c1++;  
                            }else{
                                break;
                            }
                        }
                    }
                    if( k == 3 ){ // 위 
                        for(int k2 = dir_y; k2 >= 0 ; k2--) {
                            if(map[k2][dir_x] == 0) {
                                c2++;
                            }else{
                                break;
                            }
                        }
                    }
                    if(c1 < c2) {
                        max = c2 ;
                    }else{
                        max = c1;
                    }
                }
                result += max;
            }else if(map[i][j] == 3) {
                int c1 = 0, c2 = 0, c3 = 0, c4 = 0 ;
                for(int k = 0 ; k < 4; k++) {
                    int c = 0 ; 
                    dir_y = i + dy[k];  
                    dir_x = j + dx[k]; 
                    if( dir_y < 0 || dir_y >= N || dir_x < 0 || dir_x >= M) continue; 
                    if( k == 0 ){ // 왼쪽 
                        for(int k2 = dir_x; k2 >= 0; k2--) {
                            if(map[dir_y][k2] == 0 ) {
                                c1++; 
                            }else{
                                break; 
                            }
                        }
                    }
                    if( k == 1 ){ // 아래 
                        for(int k2 = dir_y; k2 < N; k2++) {
                            if(map[k2][dir_x] == 0 ) {
                                c2++;
                            }else{
                                break;
                            }
                        }
                    }
                    if( k == 2 ){ // 오른쪽 
                        for(int k2 = dir_x; k2 < M; k2++) {
                            if(map[dir_y][k2] == 0 ) {
                                c3++;  
                            }else{
                                break;
                            }
                        }
                    }
                    if( k == 3 ){ // 위 
                        for(int k2 = dir_y; k2 >= 0 ; k2--) {
                            if(map[k2][dir_x] == 0) {
                                c4++;
                            }else{
                                break;
                            }
                        }
                    }
                }
                int value[4] = {c1 + c2, c2 + c3, c3 + c4, c1 + c4};
                sort(value, value + 4); 
                result += 1; 
                result += value[3];
            }else if(map[i][j] == 4) {
                int c1 = 0, c2 = 0, c3 = 0, c4 = 0 ;
                for(int k = 0 ; k < 4; k++) {
                    dir_y = i + dy[k];  
                    dir_x = j + dx[k]; 
                    if( dir_y < 0 || dir_y >= N || dir_x < 0 || dir_x >= M) continue; 
                    if( k == 0 ){ // 왼쪽 
                        for(int k2 = dir_x; k2 >= 0; k2--) {
                            if(map[dir_y][k2] == 0 ) {
                                c1++; 
                                map[dir_y][k2] = -1;
                            }else if(map[dir_y][k2] == 6){
                                break; 
                            }
                        }
                    }
                    if( k == 1 ){ // 아래 
                        for(int k2 = dir_y; k2 < N; k2++) {
                            if(map[k2][dir_x] == 0 ) {
                                c2++;
                                map[k2][dir_x] = -1; 
                            }else if(map[k2][dir_x] == 6){
                                break;
                            }
                        }
                    }
                    if( k == 2 ){ // 오른쪽 
                        for(int k2 = dir_x; k2 < M; k2++) {
                            if(map[dir_y][k2] == 0 ) {
                                c3++;  
                                map[dir_y][k2] = -1;
                            }else if( map[dir_y][k2] == 6){
                                break;
                            }
                        }
                    }
                    if( k == 3 ){ // 위 
                        for(int k2 = dir_y; k2 >= 0 ; k2--) {
                            if(map[k2][dir_x] == 0) {
                                c4++;
                                map[k2][dir_x] = -1;
                            }else if( map[k2][dir_x] == 6){
                                break;
                            }
                        }
                    }
                }
                int sum = c1 + c2 + c3 + c4 ; 
                int value[4] = {sum - c1, sum - c2, sum -c3, sum - c4};
                int for_max = 0, idx = 0 ;
                for(int a = 0 ; a < 4; a++){
                    if(for_max < value[a]) {
                        for_max = value[a]; 
                        idx = a ; 
                    } 
                }
                if(idx == 0 ){ // 왼쪽 
                    for(int k2 = dir_x; k2 >= 0; k2--) {
                        if(map[dir_y][k2] == -1 ) {
                            map[dir_y][k2] = 0;
                        }else if(map[dir_y][k2] == 6){
                            break; 
                        }
                    }
                }
                if( idx == 1 ){ // 아래 
                    for(int k2 = dir_y; k2 < N; k2++) {
                        if(map[k2][dir_x] == -1 ) {
                            map[k2][dir_x] = 0;
                        }else if(map[k2][dir_x] == 6){
                            break;
                        }
                    }
                }
                if( idx == 2 ){ // 오른쪽 
                    for(int k2 = dir_x; k2 < M; k2++) {
                        if(map[dir_y][k2] == -1 ) {
                            map[dir_y][k2] = 0;
                        }else if( map[dir_y][k2] == 6){
                            break;
                        }
                    }
                }
                if( idx == 3 ){ // 위 
                    for(int k2 = dir_y; k2 >= 0 ; k2--) {
                        if(map[k2][dir_x] == -1) {
                            map[k2][dir_x] = 0;
                        }else if( map[k2][dir_x] == 6){
                            break;
                        }
                    }
                }
                result += 1; 
                result += for_max;
            }else if(map[i][j] == 5) {
                result += 1; 
                for(int k = 0 ; k < 4 ;k++) {
                    dir_y = i + dx[k];  
                    dir_x = j + dy[k]; 
                    if( dir_y < 0 || dir_y >= N || dir_x < 0 || dir_x >= M) continue; 
                    if( k == 0 ){ // 왼쪽 
                        for(int k2 = dir_x; k2 >= 0; k2--) {
                            if(map[dir_y][k2] == 0 ) {
                                map[dir_y][k2] = -1;
                            }else if(map[dir_y][k2] == 6){
                                break; 
                            }
                        }
                    }
                    if( k == 1 ){ // 아래 
                        for(int k2 = dir_y; k2 < N; k2++) {
                            if(map[k2][dir_x] == 0 ) {
                                map[k2][dir_x] = -1; 
                            }else if(map[k2][dir_x] == 6){
                                break;
                            }
                        }
                    }
                    if( k == 2 ){ // 오른쪽 
                        for(int k2 = dir_x; k2 < M; k2++) {
                            if(map[dir_y][k2] == 0 ) {
                                map[dir_y][k2] = -1;
                            }else if(map[dir_y][k2] == 6){
                                break;
                            }
                        }
                    }
                    if( k == 3 ){ // 위 
                        for(int k2 = dir_y; k2 >= 0 ; k2--) {
                            if(map[k2][dir_x] == 0) {
                                map[k2][dir_x] = -1;
                            }else if(map[k2][dir_x] == 6){
                                break;
                            }
                        }
                    }
                }
            }else if(map[i][j] == 6) {
                result += 1; 
            }
        }
    }
    
    cout << N * M - result << "\n";
    return 0;
}