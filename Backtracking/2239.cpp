#include <iostream>

using namespace std ;

int matrix[9][9]; 

int checker(int x, int y, int num) {
    // line check 
    for(int i = 0 ; i < 9; i++) {
        if (matrix[i][x] == num || matrix[y][i] == num) return 0; 
    }
    
    int th_x = x / 3 * 3, th_y = y / 3 * 3 ; 
    // 3 X 3 check
    for(int i = th_y; i < th_y + 3 ; i++ ) {
        for(int j = th_x; j < th_x + 3 ; j++) {
            if (matrix[i][j] == num) {
                return 0;
            }
        }
    }
    
    return 1;
}

bool finish(){ 
    for(int i = 0 ; i < 9; i++) {
        for(int j = 0 ; j < 9; j++) {
            if (matrix[i][j] == 0) {
                return false; 
            }
        }
    }
    return true; 
}

int backtrack(int p) {
    for (int i = p ; i < 9; i++) {
        for(int j = 0 ; j < 9; j++) { 
            if( matrix[i][j] == 0) {
                for(int k = 1; k <= 9; k++) {
                    if (checker(j, i, k)) {
                        matrix[i][j] = k; 
                        backtrack(i);

                        // completion
                        if (finish()) return 0;
                        matrix[i][j] = 0 ;
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}

int main(void) {

    for (int i = 0 ; i < 9 ;i++) {
        for(int j = 0 ; j < 9; j++) {
            scanf("%1d", &matrix[i][j]);
        }
    }
    
    backtrack(0);  

    for(int i = 0 ; i < 9; i++) {
        for(int j = 0 ; j < 9; j++) {
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}