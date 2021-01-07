#include <iostream> 

int row, col; 
int input[50][50], output[50][50] ;

bool checker() {
    for(int i = 0 ; i < row; i++) {
        for(int j = 0 ; j < col ; j++) {
            if(input[i][j] != output[i][j]) {
                return false;
            }
        }
    }
    return true;
}
int main(void){
    scanf("%d %d", &row, &col) ; 

    for(int i = 0 ; i < row; i++) {
        for(int j = 0 ; j< col; j++) {
            scanf("%1d", &input[i][j]); 
        }
    } 

    for(int i = 0 ; i < row; i++) {
        for(int j = 0 ; j < col; j++) {
            scanf("%1d", &output[i][j]); 
        }
    }

    int result = 0 ; bool c = false; 
    for(int i = 0 ; i < row -2 ; i++) {
        for(int j = 0 ; j < col - 2; j++) {
            if( input[i][j] != output[i][j]) {
                for(int k = 0 ; k < 3; k++) {
                    for(int p = 0 ; p < 3; p++) {
                        if(i + k < row && j + p < col) {
                            input[i + k][j + p] = !input[i + k][j + p];
                        }
                    }
                } 
                result++;  
            }
        }
    }
    if(!checker()) printf("%d\n", -1); 
    else printf("%d\n", result);
    return 0;
}