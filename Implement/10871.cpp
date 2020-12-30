#include <iostream>
#include <vector> 
using namespace std;

int main(void){
    int size, num; 
    vector<int> v ; 
    scanf("%d %d",&size,&num);

    int *arr = new int[size]; 
    for(int i = 0 ; i < size; i++){
        scanf("%d",&arr[i]);
        if( arr[i] < num ) v.push_back(arr[i]);
    }
    for(int i = 0 ; i < v.size(); i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    free(arr); 
    return 0 ; 
}