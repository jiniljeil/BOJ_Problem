#include <iostream>

using namespace std;

int arr[9];
bool visit[9];

void backtracking(int k, int seq, int num){
    
    if( k == num ){
        for(int i = 0; i < num; i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return ;
    }
    
    for(int i = 1 ; i <= seq; i++){
        if(!visit[i]){
            arr[k] = i;
            visit[i] = true;
            backtracking(k+1, seq, num);
            visit[i] = false;
        }
    }
}

int main(void) {
    int seq, num;
    scanf("%d %d",&seq, &num);
    
    backtracking(0,seq,num);
    
    return 0;
}
