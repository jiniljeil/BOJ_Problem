#include <iostream>
#include <vector>

using namespace std;

int P[48];
int S[48];
int arr[48];
int i , j;
int main() {
    int size = 0 ;
    bool check = false;
    scanf("%d",&size);
    
    for(i = 0 ; i < size; i++){
        arr[i] = 0 ;
    }
    
    for(i = 0 ; i < size; i++){ // 0 1 2
        int t = 0 ;
        scanf("%d",&t);
        P[i] = t;
    }
    
    for(i = 0 ; i < size; i++){ // 0 ~ N-1 ( 중복 X )
        int t = 0 ;
        scanf("%d",&t);
        S[i] = t;
    }
    
//    for(i = 0 ;i < S.size(); i++){ // 같은게 존재할 경우 프로그램 종료
//        for(j = i+1 ; j < S.size() ; j++){
//            if( S[i] == S[j]) {
//                check = true;
//                break;
//            }
//        }
//        if( check ) break;
//    }
//    if( check ) return 0;
    
    int count = 0 ;
    
    while(true){
        check = true;
        for(i = 0 ; i < size; i++){
            if( P[i] != i % 3 ){
                check = false;
            }
        }
        if( check ) {
            printf("%d",count);
            break;
        }
        // 카드 섞기
        for(i = 0 ; i < size; i++){
            arr[S[i]] = P[i];
        }
        for(i = 0 ; i < size; i++){
            P[i] = arr[i];
        }
        
        count++;
        
        if( count > 11111111){
            printf("%d",-1);
            break;
        }
    }
    return 0;
}
